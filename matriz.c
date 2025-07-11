#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

#define LINHAS 25     // definido no enunciado
#define COLUNAS 80     // definido no enunciado

//-----limpa a matriz colocando um " " em todas as células ----//
void limparMatriz(char matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            matriz[i][j] = ' '; //substituir por um " " a célula
        }
    }
}

//-----imprime a matriz------//
void imprimeMatriz(char matriz[LINHAS][COLUNAS]) {
    
    printf("    ");

    for (int coluna = 0; coluna < COLUNAS; coluna++) {
        if (coluna % 5 == 0) {  // imprime a numeração das colunas de 10 em 10
            printf("%-10d", coluna);
        }
    }

    printf("\n");
    printf("    ");  

    for (int coluna = 0; coluna < COLUNAS;coluna++) {
        printf("%d", coluna % 10);  // imprime a numeração das colunas de 0 a 9
        printf("|");
    }

    printf("\n");

    for (int linha = LINHAS-1; linha >= 0; --linha) {
        printf("%2d |", linha);
        for (int coluna = 0; coluna < COLUNAS; ++coluna) { // imprime a numeraçao das linhas 
            if(matriz[linha][coluna] >= 'a' && matriz[linha][coluna] <= 'j'){ // imprime retangulos
                printf("X|");
            }else if(matriz[linha][coluna] >= '0' && matriz[linha][coluna] <= '9'){
                printf("+|"); 
            }
        }
        printf("\n");
    }
    printf("   ");

    for (int coluna = 0; coluna < COLUNAS; ++coluna) { // imprimir a linha final da matriz
        printf("--");
    }
    printf("\n");
}