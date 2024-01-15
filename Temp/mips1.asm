#Exercício 3: switch-case

#Supor que as variáveis de f, g e h estão carregadas nos 
#registradores $12, $13 e $14 e a variável x no $8

#	switch (x) {
#   	case 1: f = g + h; break
#   	case 2: f = g - h; break
#   	case 3: f = g; break
#	default: f++; 
#	}

# se usar bne o fluxo fica mais parecido com c
# carga das constantes
	addi $9, $0, 1  		#r9 <- 1
	addi $10, $0, 2			#10 <- 2
	addi $11, $0, 3			#r11 <- 3

case1:
	bne $8, $9, case2       # verifica se x != 1
	add $12, $13, $14  		# f = g + h
	j switch_end
	
case2:
	bne $8, $10, case3		# verifica  se x != 2
	sub $12, $13, $14		# f = g - h
	j switch_end

case3:
	bne $8, $11, default 	# verifica  se x != 3
	add $12, $13, $0		# f = g 

default:                	# executa se nao cair em nunhum teste
	addi $12, $12, 1		# f++

switch_end:

# O VALOR DA VARIAVEL F NAO ESTA ATUALIZADO NA MEMORIA
