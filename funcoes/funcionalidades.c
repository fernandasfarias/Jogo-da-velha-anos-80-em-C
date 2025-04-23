#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "matrizes.h"

typedef struct{
    char nome[51];
    int num;
} Jogador;

void apresentacao(Jogador *num1, Jogador *num2){

    printf("\t\t\t\033[96m+-------------------------------------------------+\033[0m\n");
    printf("\t\t\t\033[95m| Olá! Seja bem-vindo(a) ao jogo da velha retrô 🕹️ |\033[0m\n");
    printf("\t\t\t\033[96m+-------------------------------------------------+\033[0m\n\n");
    sleep(2);

    printf("\t\t\033[95m     Por favor, jogador número 1, digite a seguir o seu nome 📝 :\033[0m\n");
    printf("\t\t\033[95m     > \033[0m");
    scanf("%[^\n]%*c", num1->nome);

    printf("\n\n\t\t\t\t\033[95m| Jogador número 1 🎮: %s |\033[0m\n", num1->nome);

    printf("\t\t\t\033[95m| Aperte 1 para escolher ❌ ou 2 para escolher 🟡 |\033[0m\n");
    printf("\t\t\033[95m        > \033[0m");
    scanf("%d%*c", &num1->num);

    // para o caso do usuário não digitar 1 ou 2.
    while(num1->num != 1 && num1->num != 2){
        printf("\n\t\t\t\t\033[91m| Número inválido! Digite 1 ou 2: |\033[0m\n");
        printf("\t\t\t\033[95m        > \033[0m");
        scanf("%d%*c", &num1->num);
    }

    printf("\n\t\t\033[95m     Por favor, jogador número 2, digite a seguir o seu nome 📝 :\033[0m\n");
    printf("\t\t\033[95m     > \033[0m");
    scanf("%[^\n]%*c", num2->nome);

    printf("\n\n\t\t\t\t\033[95m| Jogador número 2 🎮: %s |\033[0m\n", num2->nome);
    if (num1->num == 1){
        num2->num = 2;
        printf("\t\t\t\t\033[95m| Você irá ficar com o símbolo 🟡 |\033[0m\n");
    }
    else{
        num2->num = 1;
        printf("\t\t\t\t\033[95m| Você irá ficar com o símbolo ❌ |\033[0m\n");
    }
}

void jogoDaVelha(Jogador num1, Jogador num2){
    char *matriz[3][3] = {
        {"🌌", "🌌", "🌌"},
        {"🌌", "🌌", "🌌"},
        {"🌌", "🌌", "🌌"}
    };

    int cont = 0, fim = 0, linha, coluna;

    printf("\t\t\t\033[32m+----------------------------------------------------+\033[0m\n");
    printf("\n\t\t\t\033[32m     O jogo de vocês irá iniciar dessa maneira 👾...\033[0m\n\n");
    printf("\t\t\t\033[32m+----------------------------------------------------+\033[0m\n\n");
    sleep(2);
    imprimirMatriz(matriz);

    printf("Antes de começar, gostaria de lembrá-los que vocês não podem repetir uma linha e coluna já selecionada...\n");
    printf("Dito isso, vamos começar!\n");

    sleep(4);
    system(clear);

    while(1){

        for (int i = 0; i < 2; i++){
            if (i == 0){
                printf("Jogador(a) %s, escolha uma linha (de 1 a 3) e uma coluna (de 1 a 3)\n", num1.nome);
                cont++;
            }

            else printf("Jogador(a) %s, escolha uma linha (de 1 a 3) e uma coluna (de 1 a 3)\n", num2.nome);

            scanf("%d%*c", &linha);
            scanf("%d%*c", &coluna);

            while(linha > 3 && coluna > 3){
                printf("Por favor, digite uma posição válida!\n");
                scanf("%d%*c", &linha);
                scanf("%d%*c", &coluna);
            }

            linha = linha-1;
            coluna = coluna-1;

            while(strcmp(matriz[linha][coluna], "🌌") != 0){
                printf("Essa posição já foi escolhida, por favor, escolha novamente!\n");
                scanf("%d%*c", &linha);
                scanf("%d%*c", &coluna);
            }

            if (num1.num == 1) matriz[linha][coluna] = "❌";
            else matriz[linha][coluna] = "🟡";

            // sem quantidade de jogadas do jogador 1 o suficiente para verificar se há algum jogador.
            if (cont < 3){
                printf("Jogo atual: \n");
                imprimirMatriz(matriz);
            }

            // agora que o jogador já fez  jogadas, podemos começar a verificar se há algum ganhador ou não.
            else {
                printf("Jogo atual:\n");
                imprimirMatriz(matriz);

                if (percorrendoMatrizLinhas == 1 || percorrendoMatrizColunas == 1 || percorrendoDiagonalPrincipal == 1 || percorrendoDiagonalSecundaria == 1){
                    printf("Parabéns %s!!! Você é o ganhador do nosso jogo da velha!!!\n", num1.nome);
                    fim = 1;
                }

                else if (percorrendoMatrizLinhas == 2 || percorrendoMatrizColunas == 2 || percorrendoDiagonalPrincipal == 2 || percorrendoDiagonalSecundaria == 2){
                    printf("Parabéns %s !!! você é o ganhador do nosso jogo da velha!!!\n", num2.nome);
                    fim = 1;
                }

                else{
                    if (deuVelha(matriz) == 1){
                        printf("DEU VELHA!! Isso significa que temos um empate!\n");
                        fim = 1;
                    }

                    else printf("Ainda temos algumas cartas na manga, vamos lá!\n");
                }
            }


        }
        
        if (fim == 1) break;
    }
}

int continuarJogo(){
    printf("\n\t\t\t\t\033[96m   +--------------------------------+\n\033[0m");
    printf("\t\t\t\t\033[95m   Querem continuar jogando? 🌀 [S/N]\n\033[0m");
    printf("\t\t\t\t\033[96m   +--------------------------------+\n\033[0m");
    printf("\t\t\t           > ");
    char resposta[2];
    scanf("%s%*c", resposta);

    if (resposta[0] == 'N' || resposta[0] == 'n') return 0;

    return 1;
}