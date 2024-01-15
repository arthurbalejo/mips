# Programa: mult_div
# Descrição: exemplo do funcionamento das instruções de multiplicação e visão

.text
	# r8 <- 0x12345678
	lui $8, 0x1234
	ori $8, $8, 0x5678
	
	mult $8, $8	# [Hi e Lo] <- r8 * r8
	
	addi $10, $0, 7	# r10 <- 7
	
	addi $11, $0, 2	# r11 <- 2
	
	div $10, $11	# Lo <- r10/11; Hi <- r10 % r11
	
	mfhi $12	# r12 <- hi
	mflo $13	# r13 <- lo