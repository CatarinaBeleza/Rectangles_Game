#ifndef matriz_H
#define matriz_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHAS 25     // definido no enunciado
#define COLUNAS 80     // definido no enunciado

//-----limpa a matriz colocando um " " em todas as células ----//
void limparMatriz(char matriz[LINHAS][COLUNAS]) ;

//-----imprime a matriz------//
void imprimeMatriz(char matriz[LINHAS][COLUNAS]);

#endif 