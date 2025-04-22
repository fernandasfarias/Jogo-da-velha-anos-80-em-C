#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void imprimirMatriz (char *matriz[3][3]){
    for (int i = 0; i < 3; i++){
        printf("\t\t\t\t\t\t");
        for (int j = 0; j < 3; j++){
            printf("%s ", matriz[i][j]);
        }
        printf("\n");
    }
}

int percorrendoMatrizLinhas(char *matriz[3][3]){
    for (int i = 0; i < 3; i++){
        int cont1 = 0, cont2 = 0;
        for (int j = 0; j < 3; j++){
            if (strcmp(matriz[i][j], "❌") == 0) cont1++;
            else if (strcmp(matriz[i][j], "🟡") == 0) cont2++;
        }
        if (cont1 == 3) return 1;
        else if (cont2 == 3) return 2;
    }
    return 0;
}

int percorrendoMatrizColunas(char *matriz[3][3]){
    for (int i = 0; i < 3; i++){
        int cont1 = 0, cont2 = 0;
        for (int j = 0; j < 3; j++){
            if (strcmp(matriz[j][i], "❌") == 0) cont1++;
            else if (strcmp(matriz[j][i], "🟡") == 0) cont2++;
        }
        if (cont1 == 3) return 1;
        else if (cont2 == 3) return 2;
    }
    return 0;
}

int percorrendoDiagonalPrincipal(char *matriz[3][3]){
    int cont1 = 0, cont2 = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (i == j){
                if (strcmp(matriz[i][j], "❌") == 0) cont1++;
                else if (strcmp(matriz[i][j], "🟡") == 0) cont2++;
            }
        }
    }
    if (cont1 == 3) return 1;
    else if (cont2 == 3) return 2;
    return 0;
}

int percorrendoDiagonalSecundaria(char *matriz[3][3]){
    int cont1 = 0, cont2 = 0;
    int totalColunas = 2;

    for (int i = 0; i < 3; i++){
        if (strcmp(matriz[i][totalColunas], "❌") == 0) cont1++;
        else if (strcmp(matriz[i][totalColunas], "🟡") == 0) cont2++;
        totalColunas--;
    }

    if (cont1 == 3) return 1;
    else if (cont2 == 3) return 2;

    return 0;
}
