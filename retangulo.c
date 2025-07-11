#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retangulo.h"

#define LINHAS 25     // definido no enunciado
#define COLUNAS 80     // definido no enunciado

//----- cria um retangulo -----//
int create(int x, int y, int l, int h,int Retangulo, char matriz[25][80]) {
    int x_direita = x + l - 1;
    int y_cima = y + h - 1;

    if (x < 0 || y < 0 || x_direita >= 80 || y_cima >= 25) {
        printf("Sem espaço para criar um retangulo.\n");
        return 0;
    }

    for (int j = y; j < y_cima; ++j) {
        for (int i = x; i < x_direita; ++i) {
            if(matriz[j][i] != ' '){
              printf("Já existe um retangulo com esta localização.\n");
              return 0 ;
            }
        }
    }
    
    for (int i = x; i <= x_direita; ++i) { // escreve o retangulo na matriz
        matriz[y][i] = 'a'+Retangulo;       // linhas horizontais
        matriz[y_cima][i] = 'a'+Retangulo;   
    }
  
    for (int j = y; j <= y_cima; ++j) {
        matriz[j][x] = 'a'+Retangulo;       //linhas verticais
        matriz[j][x_direita] = 'a'+Retangulo; 
    }
    
    for (int j = y + 1; j < y_cima; ++j) {
        for (int i = x + 1; i < x_direita; ++i) { // interior do retangulo
            matriz[j][i] = '0'+Retangulo;
        }
    }
    return 1;
}

// ---- movimenta o retangulo para a direita-----//
int moveright(int x ,int y ,int p , char matriz[LINHAS][COLUNAS]) { // p: quantas celulas queres andar para a direita

    int retangulo;

    if(matriz[y][x] == ' '){
        printf("Retangulo não encontrado.\n");
        return 0;
    }

    if(matriz[y][x] >= 'a' && matriz[y][x] <= 'j'){ //deteta se o ponto escolhido é uma borda
        retangulo = matriz[y][x] - 'a';
    }else if(matriz[y][x] >= '0' && matriz[y][x] <= '9'){ // deteta se o ponto escolunahido é interior de um retangulo
        retangulo = matriz[y][x] - '0';   
    }

    for (int coluna = COLUNAS-1; coluna > 0; coluna--) {
        for (int linha = 0; linha < 25; linha++) {
            if ((matriz[linha][coluna] == 'a'+retangulo )||(matriz[linha][coluna] == '0'+retangulo) ) {
                char atual = matriz[linha][coluna];
                if (coluna+p >= COLUNAS) { // verifica se o destino é possível ou se está fora da matriz
                        printf("Sem espaço para mover.\n");
                        return 0;
                }

                for(int i = 1; i <= p; i++) {
                    if (matriz[linha][coluna+i] != ' ') {  // verifica se a celula para onde iamos mover está vazia
                        printf("Sem espaço para mover.\n");
                        return 0;
                    }
                }
                    matriz[linha][coluna+p] = atual; //move a celula para a nova posição
                    matriz[linha][coluna] = ' '; // coloca um espaço na posição inicial
            }
        }
    }
}

// ---- movimenta o retangulo para a esquerda-----//
int moveleft(int x ,int y ,int p , char matriz[LINHAS][COLUNAS]) { // p: quantas celulas queres andar para a esquerda

    int retangulo;

    if(matriz[y][x] == ' '){
        printf("Retangulo não encontrado.\n");
        return 0;
    }

    if(matriz[y][x] >= 'a' && matriz[y][x] <= 'j'){  //deteta se o ponto escolhido é uma borda
        retangulo = matriz[y][x] - 'a';
    }else if(matriz[y][x] >= '0' && matriz[y][x] <= '9'){ // deteta se o ponto escolunahido é interior de um retangulo
        retangulo = matriz[y][x] - '0';   
    }

    for (int coluna = 0; coluna < COLUNAS; coluna++) {
        for (int linha = 0; linha < LINHAS; linha++) {
            if ((matriz[linha][coluna] == 'a'+retangulo )||(matriz[linha][coluna] == '0'+retangulo) ) {
                char atual = matriz[linha][coluna];
                if (coluna-p <0) { // verifica se o destino é possível ou se está fora da matriz
                        printf("Sem espaço para mover.\n");
                        return 0;
                }

                for(int i = 1; i <= p; i++) {  
                    if (matriz[linha][coluna-i] != ' ') { // verifica se a celula para onde iamos mover está vazia
                        printf("Sem espaço para mover.\n");
                        return 0;
                    }
                }
                    matriz[linha][coluna-p] = atual; //move a celula para a nova posição
                    matriz[linha][coluna] = ' ';    // coloca um espaço na posição inicial
            }
        }
    }
}
 
// ---- apaga o retangulo -----//
int delete(int x, int y , char matriz[LINHAS][COLUNAS]){

    int retangulo;

    if(matriz[y][x] == ' '){
        printf("Retangulo não encontrado.\n");
        return 0;
    }

    if(matriz[y][x] >= 'a' && matriz[y][x] <= 'j'){ //deteta se o ponto escolhido é uma borda
        retangulo = matriz[y][x] - 'a';
    }else if(matriz[y][x] >= '0' && matriz[y][x] <= '9'){ // deteta se o ponto escolunahido é interior de um retangulo
        retangulo = matriz[y][x] - '0';   
    }

    for (int coluna = 0; coluna < COLUNAS; coluna++) {
        for (int linha = 0; linha < LINHAS; linha++) {
            if ((matriz[linha][coluna] == 'a'+retangulo )||(matriz[linha][coluna] == '0'+retangulo) ) {
                matriz[linha][coluna] = ' '; // substitui o retangulo em causa por espaços
            }
        }
    }
}
