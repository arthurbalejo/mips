#    int a = 3;
#    int b = 5;
#    int c = 0;

#    while (a > 0) {
#        c = c + b;
#        a--;	
#    }

.text
    la $t0, a                # t0 <- &a // endereço diferente pois
                            #será alterado o valor no final do programa
    lw $t1, 0($t0)          # ti <- a

    la $t2, b               # $t2 <- &b
    lw $t2, 0($t2)          # $t2 <- b

    la $t3, c               # t3 <- &c
    lw $t4, 0($t3)          # t4 <- c

    # Manipulação das variáveis 
    # em registradores
while:
    slt $t8, $zero, $t1
    beq $t8, $zero, while_end
    
        add $t4, $t4, $t2
        addi $t1, $t1, -1	
    
    j while

# Atualização das variáveis 
# em memória
while_end:	
    sw $t1, 0($t0)  # a ← t1
    sw $t4, 0($t3)	# c ← t4

    # Mostra resultado

.data
    a: .word 3
    b: .word 5
    c: .word 0