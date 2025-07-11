#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gravidade.h"  

#define LINHAS 25     // definido no enunciado
#define COLUNAS 80     // definido no enunciado

//------Verifica se os retangulos estão o mais para baixo possivel------//
int verificaGravidade(char matriz[LINHAS][COLUNAS], int x, int y, char letra) {
    int i = 0;
    int dist = 80;
    int retangulo =0 ;

    if(matriz[y][x] >= 'a' && matriz[y][x] <= 'j'){
        retangulo = matriz[y][x] - 'a';
    }else if(matriz[y][x] >= '0' && matriz[y][x] <= '9'){
        retangulo = matriz[y][x] - '0';   
    }
   
    while(( matriz[y][x+i] == '0'+retangulo || matriz[y][x+i]== 'a'+retangulo) && (x+i < COLUNAS)){
        int verificaDistancia = y;
        int distancia = 0; 
    while (verificaDistancia > 0 &&( matriz[verificaDistancia-1][x+i] == ' ')) {
        verificaDistancia--;
        distancia++;
    }
    
    if(distancia < dist) {
        dist = distancia;   
    }
    i++;
    }
   return dist;
}

//------Aplica a gravidade aos retangulos, puxa-os para baixo o máximo possivel----//
void aplicaGravidade(char matriz[25][80], int nretangulos) {
    int retangulos[10] = {80};

    for(int i = 0; i < nretangulos; ++i) {
        for (int coluna = 0; coluna < COLUNAS; ++coluna) {
            for (int linha = 0; linha < LINHAS; ++linha) {
                if (matriz[linha][coluna] == 'a'+i ) {
                    retangulos[i] = verificaGravidade(matriz, coluna, linha, matriz[linha][coluna]);
                    coluna = COLUNAS;
                    linha = LINHAS;
                    break;
                }
            }
        }
    }

    for (int coluna = 0; coluna < COLUNAS; ++coluna) {
        for (int linha = 0; linha < LINHAS; ++linha) {
            if ((matriz[linha][coluna] >= 'a' &&  matriz[linha][coluna] <= 'j')||(matriz[linha][coluna] >= '0' && matriz[linha][coluna] <= '9') ) {
                int n = 0 ;
                char atual = matriz[linha][coluna];
                if(matriz[linha][coluna] >= 'a' && matriz[linha][coluna] <= 'j'){
                    n = matriz[linha][coluna] - 'a';
                }else if(matriz[linha][coluna] >= '0' && matriz[linha][coluna] <= '9'){
                    n = matriz[linha][coluna] - '0';   
               }

                if(retangulos[n] > 0) {
                    matriz[linha-retangulos[n]][coluna] = atual;
                    matriz[linha][coluna] = ' ';
                }
            }
        }
    }
}

//------verifica se a matriz ------//
int vizinhoDiferente(char matriz[LINHAS][COLUNAS], int x, int y) {
    char alvo = matriz[y][x];
    int dy[] = {-1, 1, 0, 0}; // direções: cima, baixo, esquerda, direita
    int dx[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int novoX = x + dx[i];
        int novoY = y + dy[i];

        if (novoX >= 0 && novoX < COLUNAS && novoY >= 0 && novoY < LINHAS) {
            char vizinho = matriz[novoY][novoX];
            
            if (vizinho != ' ' && vizinho != alvo && (vizinho >= 'a' && vizinho <= 'j')) {
               printf("alvo %c em %d,%d com vizinho %c em %d,%d\n",alvo,x,y,vizinho,novoX,novoY);
            }
        }
    }
    return 0; 
}

//----verifica se devido à gravidade existe uma colisão ----//
int verificaColisoes(char matriz[LINHAS][COLUNAS], int nretangulos){
    char aux[LINHAS][COLUNAS];

    for(int coluna = 0; coluna < COLUNAS; ++coluna) {
        for (int linha = 0; linha < LINHAS; ++linha) {
            aux[linha][coluna] = matriz[linha][coluna];
        }
    }
    
    aplicaGravidade(matriz,nretangulos);
    
    for(int coluna = 0; coluna < COLUNAS; ++coluna) {
        for (int linha = 0; linha < LINHAS; ++linha) {
            if(aux[linha][coluna] != matriz[linha][coluna]) {
                 if(matriz[linha][coluna] >= 'a' && matriz[linha][coluna] <= 'j'){
                    vizinhoDiferente(matriz,coluna,linha);
                 }
            }
        }
    }
}
