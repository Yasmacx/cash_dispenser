#include <stdio.h>
#include <stdlib.h>

int main() {
    int estoque100 = 0, estoque50 = 0, estoque20 = 0, estoque10 = 0, estoque5 = 0;
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
            case 1: {
                printf("\n--- Quantidade de Notas Disponiveis ---\n");
                printf("Notas 5: %d\n", estoque5);
                printf("Notas 10: %d\n", estoque10);
                printf("Notas 20: %d\n", estoque20);
                printf("Notas 50: %d\n", estoque50);
                printf("Notas 100: %d\n", estoque100);
                break;
            }
            case 2: {
                int add100 = 0, add50 = 0, add20 = 0, add10 = 0, add5;
                printf("\n--- Adicionando dinheiro no Cash ---\n");

                printf("Notas 5: ");
                scanf("%d", &add5);
                printf("Notas 10: ");
                scanf("%d", &add10);
                printf("Notas 20: ");
                scanf("%d", &add20);
                printf("Notas 50: ");
                scanf("%d", &add50);
                printf("Notas 100: ");
                scanf("%d", &add100);

                if (add5 > 0) estoque5 += add5;
                if (add10 > 0) estoque10 += add10;
                if (add20 > 0) estoque20 += add20;
                if (add50 > 0) estoque50 += add50;
                if (add100 > 0) estoque100 += add100;

                printf("\nDinheiro adicionado com sucesso!\n");
                break;
            }
            case 3: {
                int valor, restante;
                int quant100 = 0, quant50 = 0, quant20 = 0, quant10 = 0, quant5 = 0;

                printf("\n--- Sacar de Dinheiro ---\n");
                printf("Valor do saque: ");
                scanf("%d", &valor);

                //o valor tem que ser maior que zero e multiplo de 10 para separar por dezena(igual dinheiro)
                if (valor <= 0 || valor % 10 != 0) {
                    printf("\nValor invalido! O valor do saque deve ser positivo e multiplo de 10.\n");
                    break;
                }

                restante = valor;

                //divide por 100 para calcular em blocos, depois verifica se o valor de saque é maior que o estoque, e depois subtrai do restante o calculo em blocos
                quant100 = restante / 100;
                if (quant100 > estoque100) quant100 = estoque100;
                restante -= quant100 * 100;

                quant50 = restante / 50;
                if (quant50 > estoque50) quant50 = estoque50;
                restante -= quant50 * 50;

                quant20 = restante / 20;
                if (quant20 > estoque20) quant20 = estoque20;
                restante -= quant20 * 20;

                quant10 = restante / 10;
                if (quant10 > estoque10) quant10 = estoque10;
                restante -= quant10 * 10;

                quant5 = restante / 5;
                if (quant5 > estoque5) quant5 = estoque5;
                restante -= quant5 * 5;

                if (restante > 0) {
                    printf("\nSaque nao realizado: Notas indisponiveis no caixa para compor o valor solicitado.\n");
                } else {
                    estoque100 -= quant100;
                    estoque50 -= quant50;
                    estoque20 -= quant20;
                    estoque10 -= quant10;

                    printf("\nSaque realizado com sucesso\n");
                    printf("Valor: %d\n", valor);
                    printf("Notas 5: %d\n", quant5);
                    printf("Notas 10: %d\n", quant10);
                    printf("Notas 20: %d\n", quant20);
                    printf("Notas 50: %d\n", quant50);
                    printf("Notas 100: %d\n", quant100);
                }
                break;
            }
            case 4:
                printf("\nEncerrando o sistema de Cash. Ate logo!\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
        }

    } while (opcao != 4);

    return 0;
}
