#ifndef retangulo_H
#define retangulo_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHAS 25     // definido no enunciado
#define COLUNAS 80     // definido no enunciado

//----- cria um retangulo -----//
int create(int x, int y, int l, int h,int Retangulo, char matriz[25][80]);

// ---- movimenta o retangulo para a esquerda-----//
int moveleft(int x ,int y ,int p , char matriz[LINHAS][COLUNAS]);

// ---- movimenta o retangulo para a direita-----//
int moveright(int x ,int y ,int p , char matriz[LINHAS][COLUNAS]);

// ---- apaga o retangulo -----//
int delete(int x, int y , char matriz[LINHAS][COLUNAS]);

#endif 