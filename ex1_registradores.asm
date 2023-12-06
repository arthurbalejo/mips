#programa : registrador
#descricao: exemplo do funcionamento do modo de enderecamento e registrador

.text
	add $t1, $t2, $t3	#t1 <- t2 + t3
	
	and $t4, $t2, $t3	#t4 <- t2 & t3
	
	slt $t5, $t2, $t3	#t5 <- 1 se t2 <t3, senao t5 <- 0