#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funcoes/funcionalidades.h"
#include "funcoes/matrizes.h"

int main(){
    Jogador jogador1, jogador2; 

    apresentacao(&jogador1, &jogador2);
    sleep(4); // para dar tempo de olhar o restante da função (com qual símbolo o segundo jogador ficou)
    system("clear");

    while (1){
        jogoDaVelha(jogador1, jogador2);
        if (continuarJogo() == 0) break;
    }

    return 0;
}
