#Exercício 4: while

#Supor que as variáveis de a, b e c estão carregadas nos 
#registradores $8, $9 e $10

#	while (a != 0) {
#   	c = c + b;
#	   a--;	
#	}

while:
    beq $8, $0, while_end   # sai do laço se a == 0
    add $10, $10, $9        # c = c + b
    addi $8, $8, -1          # a--
    j while 
    
while_end: