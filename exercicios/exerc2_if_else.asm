#Exercício 2: if-else

#Supor que as variáveis de f até j estão carregadas nos registradores de $8 até $12

#	if (i == j)  
#	   f = g + h; 
#	else 
#	   f = g – h;
# OBS: O VALOR DA VARIAVEL F NAO ESTA ATUALIZADO NA MEMORIA

	beq, $12, $12, if	# if (i == j)  
else:
	sub $8, $9, $11	# f = g - h; 
	j end_if
if:
	add $8, $9, $11	# f = g + h;
end_if:
 