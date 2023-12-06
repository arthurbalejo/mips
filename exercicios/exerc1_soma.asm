# Exercício 1: f = (g + h) – (i + 34)

# Supor que as variáveis de f até i estão carregadas nos 
# registradores de $8 até $11

.text
	# carga das variáveis em registradores
	la $9, g  			# r9 <- &g
	lw $9, 0($9)		# r9 <- g

	la $10, h			# r10 <- $h
	lh $10, 0($10)		# r10 <- h

	la $11, i			#r11 <- &i
	lb $11, 0($11)		#r11 <- i

	# manipulacao das variaveis em registradores
	add $12, $9, $10	# r12 <- g + h
	addi $13, $11, 34	# r13 <- i + 34
	sub $8, $12, $13	# r8(f) <- (g + h) - (i + 34)

	# atualização das variaveis na memoria
	la $14, f 			# r14 <- &f
	sw $8, 0($14)		# f <- r8

.data
	f:  .word  0x1		# 32 bits variable
	g:  .word  0x33		# 32 bits variable
	i:  .byte  0x44 	# 8 bits variable
	h:  .half  0x15 	# 16 bits variable
	