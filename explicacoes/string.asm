
.text
    li $v0, 4           # Print string
    la $a0, msg         # Source string address
    syscall

    li $v0, 8           # Read string
    la $a0, readStr     # Target string address
    li $a1, 20          # Maximum number of characters to read
    syscall 
    
    li $v0, 11          # Print char
    li $a0, '\t'        # tab
    syscall
    
    li $v0, 4           # Print string
    la $a0, readStr     # Source string address
    syscall

.data
    msg: .asciiz "Digite uma string: "
    readStr: .space 20 
