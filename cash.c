#include <stdio.h>
#include <stdlib.h>

int main() {
    int estoque100 = 0, estoque50 = 0, estoque20 = 0, estoque10 = 0;
    int opcao;

    do {
        printf("UNICSUL - Simulador de Cash Dispenser - versao 2026\n");
        printf("01/09/2026\n\n");
        printf("Menu: \n");
        printf("1 - Ver quantidade de dinheiro no cash\n");
        printf("2 - Adicionar dinheiro no cash\n");
        printf("3 - Sacar dinheiro no cash\n");
        printf("4 - Sair\n");
        printf("Escolha operacao: ");
        
        if (scanf("%d", &opcao) != 1) {
        //essa função é pra limpar o lixo de memoria quando acontece um erro de validação de int, esse comando faz que não entre em loop no erro
            fflush(stdin);
            opcao = -1;
        }

        switch (opcao) {
            case 0: {
                printf("\n--- Quantidade de Notas Disponiveis ---\n");
                printf("Notas 10: %d\n", estoque10);
                printf("Notas 20: %d\n", estoque20);
                printf("Notas 50: %d\n", estoque50);
                printf("Notas 100: %d\n", estoque100);
                break;
            }
            case 1: {
                int add100 = 0, add50 = 0, add20 = 0, add10 = 0;
                printf("\n--- Abastecer ATM ---\n");
                
                printf("Notas 10: ");
                scanf("%d", &add10);
                printf("Notas 20: ");
                scanf("%d", &add20);
                printf("Notas 50: ");
                scanf("%d", &add50);
                printf("Notas 100: ");
                scanf("%d", &add100);

                if (add10 > 0) estoque10 += add10;
                if (add20 > 0) estoque20 += add20;
                if (add50 > 0) estoque50 += add50;
                if (add100 > 0) estoque100 += add100;

                printf("\nATM abastecido com sucesso!\n");
                break;
            }
            case 2: {
                int valor, restante;
                int q100 = 0, q50 = 0, q20 = 0, q10 = 0;

                printf("\n--- Saque de Dinheiro ---\n");
                printf("Valor do saque: ");
                scanf("%d", &valor);

                if (valor <= 0 || valor % 10 != 0) {
                    printf("\nValor invalido! O valor do saque deve ser positivo e multiplo de 10.\n");
                    break;
                }

                restante = valor;

                q100 = restante / 100;
                if (q100 > estoque100) q100 = estoque100;
                restante -= q100 * 100;

                q50 = restante / 50;
                if (q50 > estoque50) q50 = estoque50;
                restante -= q50 * 50;

                q20 = restante / 20;
                if (q20 > estoque20) q20 = estoque20;
                restante -= q20 * 20;

                q10 = restante / 10;
                if (q10 > estoque10) q10 = estoque10;
                restante -= q10 * 10;

                if (restante > 0) {
                    printf("\nSaque nao realizado: Notas indisponiveis no caixa para compor o valor solicitado.\n");
                } else {
                    estoque100 -= q100;
                    estoque50 -= q50;
                    estoque20 -= q20;
                    estoque10 -= q10;

                    printf("\nSaque realizado com sucesso\n");
                    printf("Valor: %d\n", valor);
                    printf("Notas 10: %d\n", q10);
                    printf("Notas 20: %d\n", q20);
                    printf("Notas 50: %d\n", q50);
                    printf("Notas 100: %d\n", q100);
                }
                break;
            }
            case 9:
                printf("\nEncerrando o sistema de ATM. Ate logo!\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 9);

    return 0;
}
