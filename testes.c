#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "comandos.h"
#include "retangulo.h"
#include "gravidade.h"

#define LINHAS 25     // definido no enunciado
#define COLUNAS 80     // definido no enunciado

int main() {
//----- teste para cria um retangulo 1,1+10,10 -----//
int create(int 1, int 1, int 10, int 10,int Retangulo, char matriz[25][80]);
imprimeMatriz(matriz); 

// ---- movimenta o retangulo para a esquerda 1,3+1 -----//
int moveleft(int 1 ,int 3 ,int 1 , char matriz[LINHAS][COLUNAS]);
imprimeMatriz(matriz); 
// ---- movimenta o retangulo para a direita 9,8+2-----//
int moveright(int 9 ,int 8 ,int 2 , char matriz[LINHAS][COLUNAS]);
imprimeMatriz(matriz); 
// ---- apaga o retangulo 10,2 -----//
int delete(int 10, int 2 , char matriz[LINHAS][COLUNAS]);
imprimeMatriz(matriz); 
    }


