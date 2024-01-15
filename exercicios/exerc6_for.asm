# supor que as variaveis i, j e k estao carregadas
# nos registradores $8, $9, $10

# for (i = 0; i < j; i++){
#   k = k + i;    
# }

# da pra fazer com addi ou xor para i = 0

    xor $8, $8, $8              # i = 0
for_test:
    slt $13, $8, $9             # (i<j) $13 <- 1 : (i>j) $13 <- 0
    beq $13, $0, for_end        # desvia se (i>=j)
    add $10, $10, $8            # k = k + 1
    addi $8, $8, 1              # i++
    j for_test
for_end:

#os valores das variaveis i e k nao estao atualizados na memoria

