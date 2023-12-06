#Exercício 2: if-else com fluxo parecido com c

#Supor que as variáveis de f até j estão carregadas nos registradores de $8 até $12

#	if (i == j)  
#	   f = g + h; 
#	else 
#	   f = g – h;
# OBS: O VALOR DA VARIAVEL F NAO ESTA ATUALIZADO NA MEMORIA

    bne $11, $12, else   # se i != j salta para else
    add $8, $9, $10      # f = g + h (i ==j)
    j end_if             # salta para o corpo do else
else:
    sub $8, $9, $10      # f = g - h (i != j)
end_if: