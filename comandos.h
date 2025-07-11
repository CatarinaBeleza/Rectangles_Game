#ifndef comandos_H
#define comandos_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHAS 25     // definido no enunciado
#define COLUNAS 80     // definido no enunciado

//-----Analisa o comando dado pelo utilizador-----///
void analisarComando(const char* input, char matriz[LINHAS][COLUNAS], int *retangulos);

#endif 