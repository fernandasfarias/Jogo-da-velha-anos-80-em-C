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

    // int cont1 = 0, cont2 = 0, linha, coluna;

    printf("\t\t\t\033[32m+----------------------------------------------------+\033[0m\n");
    printf("\n\t\t\t\033[32m     O jogo de vocês irá iniciar dessa maneira 👾...\033[0m\n\n");
    printf("\t\t\t\033[32m+----------------------------------------------------+\033[0m\n\n");
    sleep(2);
    imprimirMatriz(matriz);

    /*while(1){
        printf("\n\t\t\t\033[32m     %s, escolha uma linha e uma coluna 🕹️\033[0m\n\n", nome);
    }*/
    
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