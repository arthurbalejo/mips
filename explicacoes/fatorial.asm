#    int fatorial(int n) {
#
#        if ( n == 0 ) 
#            return n;
#        else 
#            return fatorial(n-1) * n; 
#    }

    .text
    
    li $sp, 0x10010020
    
    li $a0, 3			#
    jal fatorial		# fatorial(3)
    
    # Print result
    add $a0, $v0, $zero
    li $v0, 1                  # Print integer          
    syscall
    
    # Terminate execution
    li $v0, 10
    syscall

fatorial:    
    addi $sp, $sp, -8          # Allocate stack space
    sw $ra, 0($sp)             # Store ra on stack
    sw $a0, 4($sp)             # Store a0 on stack

    bne $a0, $zero, else       # n == 0 ?
        addi $v0, $zero, 1     # 
        j return               # return 1  
      
else:    
    addi $a0, $a0, -1          # n-1
    jal fatorial               # fatorial(n-1)
    lw $a0, 4($sp)             # restore n before the function call      
    mult $v0, $a0              # fatorial(n-1) * n
    mflo $v0

return:    
    lw $ra, 0($sp)             # Restore ra from stack
    addi $sp, $sp, 8           # Deallocate stack space 
    jr $ra                     # return
