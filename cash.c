#include <stdio.h>

int main() {
    // Variáveis para contagem de notas entregues num saque
    int saque100, saque50, saque20, saque10, saque5;
    
    // Estoque inicial de notas na máquina (começam com 0 ou podes alterar para testar)
    int estoque100 = 10, estoque50 = 10, estoque20 = 10, estoque10 = 10, estoque5 = 10;
    
    int valor_usuario, opcao;
    
    do {
        printf("\n=== Sistema de Cash Dispenser ===\n");
        printf("0 - Mostrar quantidade de dinheiro\n");
        printf("1 - Sacar dinheiro no Cash Dispenser\n");
        printf("2 - Adicionar dinheiro no Cash Dispenser\n");
        printf("3 - Sair do sistema\n");
        
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        if (opcao == 0) {
            printf("\n--- Estoque Atual de Notas ---\n");
            printf("Notas de 100: %d\n", estoque100);
            printf("Notas de 50: %d\n", estoque50);
            printf("Notas de 20: %d\n", estoque20);
            printf("Notas de 10: %d\n", estoque10);
            printf("Notas de 5: %d\n", estoque5);
        }
        else if (opcao == 1) {
            printf("\n--- Sacar Dinheiro ---\n");
            printf("Digite o valor que deseja sacar: R$ ");
            scanf("%d", &valor_usuario);
            
            if (valor_usuario <= 0) {
                printf("Valor invalido para saque!\n");
            } else {
                // Cálculo das notas (priorizando as maiores)
                saque100 = valor_usuario / 100;
                valor_usuario = valor_usuario % 100;
                
                saque50 = valor_usuario / 50;
                valor_usuario = valor_usuario % 50;
                
                saque20 = valor_usuario / 20;
                valor_usuario = valor_usuario % 20;
                
                saque10 = valor_usuario / 10;
                valor_usuario = valor_usuario % 10;
                
                saque5 = valor_usuario / 5;
                valor_usuario = valor_usuario % 5;
                
                if (valor_usuario > 0) {
                    printf("Erro: O caixa nao possui notas para entregar o valor exato.\n");
                } else {
                    printf("\nSaque realizado com sucesso! Notas entregues:\n");
                    if (saque100 > 0) printf("- Notas de 100: %d\n", saque100);
                    if (saque50 > 0)  printf("- Notas de 50: %d\n", saque50);
                    if (saque20 > 0)  printf("- Notas de 20: %d\n", saque20);
                    if (saque10 > 0)  printf("- Notas de 10: %d\n", saque10);
                    if (saque5 > 0)   printf("- Notas de 5: %d\n", saque5);
                }
            }
        }
        else if (opcao == 2) {
            int tipo_nota, quantidade;
            
            printf("\n--- Abastecer Caixa Dispenser ---\n");
            printf("Qual nota deseja adicionar (100, 50, 20, 10, 5)? ");
            scanf("%d", &tipo_nota);
            
            printf("Quantas unidades dessa nota deseja adicionar? ");
            scanf("%d", &quantidade);
            
            if (tipo_nota == 100) {
                estoque100 += quantidade;
                printf("Sucesso! Adicionadas %d notas de 100.\n", quantidade);
            }
            else if (tipo_nota == 50) {
                estoque50 += quantidade;
                printf("Sucesso! Adicionadas %d notas de 50.\n", quantidade);
            }
            else if (tipo_nota == 20) {
                estoque20 += quantidade;
                printf("Sucesso! Adicionadas %d notas de 20.\n", quantidade);
            }
            else if (tipo_nota == 10) {
                estoque10 += quantidade;
                printf("Sucesso! Adicionadas %d notas de 10.\n", quantidade);
            }
            else if (tipo_nota == 5) {
                estoque5 += quantidade;
                printf("Sucesso! Adicionadas %d notas de 5.\n", quantidade);
            }
            else {
                printf("Nota invalida! O caixa so aceita notas de 100, 50, 20, 10 ou 5.\n");
            }
        }
        else if (opcao == 3) {
            printf("\nSaindo do sistema. Ate logo!\n");
        }
        else {
            printf("\nOpcao invalida!\n");
        }

    } while (opcao != 3);

    return 0;    
}
