#include <stdio.h>

int main() {
    int saque100, saqued50, saqued20, saqued10, saqued5, estoque100, estoque50, estoque20, estoque10, estoque5;
    int valor_usuario, opcao;
    
    do {
         printf("Sistema de Cash Dispenser");
         prinff("0 - Monstrar quantidade de dinheiro");
         printf("1 - Sacar dinheiro no Cash Dispenser");
         printf("2 - Adicionar dinheiro no Cash Dispenser");
         printf("3 - Sair do sistema");
         
         printf("Escolha um opção: ");
         scanf("%d", &opcao);
         
         if (opcao == 0){
                   printf("Voce escolheu ver quantidade de dinheiro\n");
                   
         else if (opcao == 1){
                   printf("Voce escolheu sacar dinheiro\n");
         }
         else if (opcao == 2) {
              printf("Voce escolheu adicionar dinheiro\n");
         }
         else if (opcao == 3){
              printf("Voce escolheu sair do sistema\n");
       }
        else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 3);


    
 return 0;   
}
