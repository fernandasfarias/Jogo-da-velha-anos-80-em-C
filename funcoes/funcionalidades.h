#ifndef FUNCIONALIDADES_H
#define FUNCIONALIDADES_H

typedef struct{
    char nome[51];
    int num;
} Jogador;

void apresentacao(Jogador *num1, Jogador *num2);

void jogoDaVelha(Jogador num1, Jogador num2);

int continuarJogo();

#endif