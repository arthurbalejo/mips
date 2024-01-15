#Exercício 5: do-while

#Supor que as variáveis de a, b e c estão carregadas nos 
#registradores $8, $9 e $10
#	do {
#   		c = c + b;
#   		a--;
#	} while (a != 0);

do:
    add $10, $10, $9
    addi $8, $8, -1
while:
    bne $8, $0, do

#os valores das variaveis a e c nao estap atualizados na memoria

