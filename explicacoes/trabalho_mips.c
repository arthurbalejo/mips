#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_ALREADY_INSERTED    -1
#define INSERTION_OK                0

/* List element definition */
struct Student {
    char name[90];
    unsigned int registration; 
    char course[50];
};

/* List node definition */
struct Node {
    struct Student *student;
    struct Node *prev, *next;
};

/* List definition */ 
struct DoubledLinkedList {
    int size;
    struct Node *head;        /* Points the first node */
    struct Node *tail;        /* Points the last node */
};

/* Initialize the list struct as an empty list */
void CreateList(struct DoubledLinkedList *list) {

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/* Insert a new node according to the student registration order (higher registration is the head node) 
 *      - Return STUDENT_ALREADY_INSERTED if the student was already inserted
 *      - Return INSERTION_OK on success 
*/
int InsertNode(struct DoubledLinkedList *list, struct Node *newNode) {
    
    /* Auxiliary pointer */
    struct Node *aux;
    
    /* Initialize the new node prev and next pointers to NULL */
    newNode->prev = NULL;
    newNode->next = NULL;
    
    /* Verifies if the list is empty */
    if (list->size == 0) {            
        /* Empty list: insert the node as first and last */
        list->head = newNode;
        list->tail = newNode;
    }

    /* Search for the right place to insert the student */
    /* Students are linked following registration order */
    /* list->head points the higher registration */
    /* list->tail points the lower registration */
    else {
        
        aux = list->head;
        
        /* Search the right position according to the registration */
        while (aux != NULL) 
            if (newNode->student->registration >= aux->student->registration) {
                if (newNode->student->registration == aux->student->registration)         
                    return STUDENT_ALREADY_INSERTED;  /* Student already inserted */
                else
                    break;
            }                
            else
                aux = aux->next;            
        
        /* If aux == list->head, then the new student has the higher registration */
        if (aux == list->head) {
            /* Insert before the first node (new head node) */
            aux->prev = newNode;
            newNode->next = aux;
            list->head = newNode;
        } 
        /* If aux == NULL, then the new student has the lower registration */
        else if (aux == NULL) {
            /* Insert after the last node (new tail node) */
            newNode->prev = list->tail;
            list->tail->next = newNode;
            list->tail = newNode;
        }      
        else {
            /* Insert between two nodes */
            aux->prev->next = newNode;
            newNode->prev = aux->prev;
            aux->prev = newNode;
            newNode->next = aux;
        }        
    }

    list->size++;   /* Update the list size */
    
    return INSERTION_OK;       /* Node inserted */
}

/* Allocate memory to create a clone of the list */
struct DoubledLinkedList *CloneList2(struct DoubledLinkedList *list) {
    
    struct DoubledLinkedList *clonedList;
    struct Node *node, *aux;
    
    clonedList = (struct DoubledLinkedList *)malloc(sizeof(struct DoubledLinkedList));
    
    CreateList(clonedList);
    
    /* Points the head element on source list */
    aux = list->head;
    
    while(aux != NULL) {
        /* Allocate memory for node and student structs */
        node = (struct Node *)malloc(sizeof(struct Node));
        node->student = (struct Student *)malloc(sizeof(struct Student));
        
        /* Clone the student */
        strcpy(node->student->name,aux->student->name);
        node->student->registration = aux->student->registration;
        strcpy(node->student->course,aux->student->course);
        
        /* Insert the cloned node into the cloned list */
        InsertNode(clonedList,node);
        
        /* Points the next node to be cloned */
        aux = aux->next;
    }
    
    return clonedList;        
}

/* Prints the list from head to tail */
void PrintList(struct DoubledLinkedList *list) {

    struct Node *aux;

    aux = list->head;

    while ( aux != NULL ) {
        printf("Reg.: %d   Name: %s   Course: %s\n",aux->student->registration, aux->student->name, aux->student->course);
        aux = aux->next;
    }
}

/* Prints the list from tail to head */
void PrintListReverse(struct DoubledLinkedList *list) {

    struct Node *aux;

    aux = list->tail;

    while ( aux != NULL ) {
        printf("Reg.: %d   Name: %s   Course: %s\n",aux->student->registration, aux->student->name, aux->student->course);
        aux = aux->prev;
    }
}



int main() {

    struct DoubledLinkedList list, *clonedList;
    struct Node *newNode;
    
    CreateList(&list);
           
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->student = (struct Student *)malloc(sizeof(struct Student));
    strcpy(newNode->student->name,"Ozzy Osbourne");
    newNode->student->registration = 666;
    strcpy(newNode->student->course,"Heavy Metal");
    if (InsertNode(&list,newNode) == STUDENT_ALREADY_INSERTED)  /* Empty list: insert the node as first and last */
        printf("Student %s already inserted.\n",newNode->student->name);
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->student = (struct Student *)malloc(sizeof(struct Student));
    strcpy(newNode->student->name,"Ozzy Osbourne");
    newNode->student->registration = 666;
    strcpy(newNode->student->course,"Heavy Metal");
    if (InsertNode(&list,newNode) == STUDENT_ALREADY_INSERTED)  /* Try to insert an already inserted student */
        printf("Student %s already inserted.\n",newNode->student->name);
        
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->student = (struct Student *)malloc(sizeof(struct Student));
    strcpy(newNode->student->name,"Scott Ian");
    newNode->student->registration = 670;
    strcpy(newNode->student->course,"Thrash Metal");
    if (InsertNode(&list,newNode) == STUDENT_ALREADY_INSERTED)  /* Inserts before the first node (new head node) */
        printf("Student %s already inserted.\n",newNode->student->name);
        
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->student = (struct Student *)malloc(sizeof(struct Student));
    strcpy(newNode->student->name,"Vince Neil");
    newNode->student->registration = 668;
    strcpy(newNode->student->course,"Hard Rock");
    if (InsertNode(&list,newNode) == STUDENT_ALREADY_INSERTED)  /* Inserts between two nodes */
        printf("Student %s already inserted.\n",newNode->student->name);
        
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->student = (struct Student *)malloc(sizeof(struct Student));
    strcpy(newNode->student->name,"Lemmy Kilmister (R.I.P.)");
    newNode->student->registration = 660;
    strcpy(newNode->student->course,"Extreme Rock and Roll");
    if (InsertNode(&list,newNode) == STUDENT_ALREADY_INSERTED)  /* Inserts after the last node (new tail node) */
        printf("Student %s already inserted.\n",newNode->student->name);
        
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->student = (struct Student *)malloc(sizeof(struct Student));
    strcpy(newNode->student->name,"Robert Johnson (R.I.P.)");
    newNode->student->registration = 671;
    strcpy(newNode->student->course,"Delta Blues");
    if (InsertNode(&list,newNode) == STUDENT_ALREADY_INSERTED)  /* Inserts before the first node (new head node) */
        printf("Student %s already inserted.\n",newNode->student->name);
        
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->student = (struct Student *)malloc(sizeof(struct Student));
    strcpy(newNode->student->name,"Robert Johnson (R.I.P.)");
    newNode->student->registration = 671;
    strcpy(newNode->student->course,"Delta Blues");
    if (InsertNode(&list,newNode) == STUDENT_ALREADY_INSERTED)   /* Try to insert an already inserted student */
        printf("Student %s already inserted.\n",newNode->student->name);
  
    printf("\nList size: %d\n",list.size);
    PrintList(&list);
    printf("\n");
    PrintListReverse(&list); 

    clonedList = CloneList2(&list);
    printf("\nCloned list\n");
    printf("List size: %d\n",clonedList->size);
    PrintList(clonedList);
    printf("\n");
    PrintListReverse(clonedList); 

    return 0;
}