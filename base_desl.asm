# programa base-deslocamento
# descrição: exemplo de funcionamento do modo de endereçamento base-deslocamento

.text

	# r11 <- 0x10010000
	lui $11, 0x1001		# r11(31:16) <- r11(15:0) <- 0
	
	# r8 <- 0xABCD000F
	lui $8, 0xABCD
	ori $8, $8, 0xf
	
	sw $8, 8($11)		# MEM(r11 + 4) <- r8
	lw $9, 8($11)		# r9 <- MEM(r11 + 4)