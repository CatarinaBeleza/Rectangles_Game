#ifndef gravidade_H
#define gravidade_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHAS 25     // definido no enunciado
#define COLUNAS 80     // definido no enunciado

//------Verifica se os retangulos estão o mais para baixo possivel------//
int verificaGravidade(char matriz[LINHAS][COLUNAS], int x, int y, char letra);

//------Aplica a gravidade aos retangulos, puxa-os para baixo o máximo possivel----//
void aplicaGravidade(char matriz[25][80], int nretangulos);

int vizinhoDiferente(char matriz[LINHAS][COLUNAS], int x, int y);

//----verifica se devido à gravidade existe uma colisão ----//
int verificaColisoes(char matriz[LINHAS][COLUNAS], int nretangulos);

#endif 