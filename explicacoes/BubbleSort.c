#   void BubbleSort(int *array, int size) {
#
#       int i, j, temp;
#       int swap = 1;
#
#       while (swap == 1) {
#           swap = 0;
#           for(i = 0, j = 1; j < size; i++, j++)
#               if (array[i] > array[j]) {
#                   temp = array[j];
#                   array[j] = array[i];
#                   array[i] = temp;
#                   swap = 1;
#               }
#           }
#       }


.text
    
    # a0: &array
    la $a0, array
    
    # a1: size
    li $a1, 5         

bubbleSort:
    # t0: swap
    addi $t0, $zero, 1              
    
    # t9: constante 1
    addi $t9, $zero, 1
    
    # while (swap == 1)
while:
    bne $t0, $t9, while_end         # Sai do laço se swap = 1
   
    # swap = 0;
    add $t0, $zero, $zero
    
    # t1: i
    add $t1, $zero, $zero           
    
    # t2: j
    addi $t2, $zero, 1
    
    # for(i = 0, j = 1; j<size; i++, j++)   
for:
    # j < size ?
    slt $t8, $t2, $a1               # j < size ?
    beq $t8, $zero, for_end         # Sai do laço se j >= size
    
    # if (array[i] > array[j])
    # Obtém array[i]
    sll $t3, $t1, 2                 # Obtém deslocamento em palavras correspondente ao índice i
    add $t3, $a0, $t3               # t3: &array[i] (base do array + deslocamento do índice)
    lw $t4, 0($t3)                  # t4: array[i]
    
    # Obtém array[j]
    sll $t5, $t2, 2                 # Obtém deslocamento em palavras correspondente ao índice j
    add $t5, $a0, $t5               # t5: &array[j] (base do array + deslocamento do índice)
    lw $t6, 0($t5)                  # t6: array[j]
    
    # array[j] < array[i] ?
    slt $t8, $t6, $t4               # array[j] < array[i] ?
    beq $t8, $zero, inc             # Pula corpo do if condição for falsa
        # swap(array[j], array[i])
        sw $t4, 0($t5)
        sw $t6, 0($t3)
        addi $t0, $zero, 1          # swap <- 1 
        
inc:
    addi $t1, $t1, 1                # i++
    addi $t2, $t2, 1                # j++
    j for
    
for_end:
    j while
while_end:


.data
    array: .word 5 -1 -3 2 4
    
