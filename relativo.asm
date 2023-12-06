# Programa: relativo
# Descriçã: exemplo do funcionamento do momdo de endereçamento relativo (PC)

.text
start:
	addi $9, $zero, 1	# r9 <- 1
	
	# Branch if equal
	beq $9, $0, end		# Desvia se r9 = 0
	
	# Branch if not equal
	bne $9, $0, start	# Desvia se r9 != 0
end: