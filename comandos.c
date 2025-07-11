#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comandos.h"
#include "retangulo.h"

#define LINHAS 25     // definido no enunciado
#define COLUNAS 80     // definido no enunciado

//-----Analisa o comando dado pelo utilizador-----///
void analisarComando(const char* input, char matriz[LINHAS][COLUNAS], int *retangulos) {
    char comando[20]; // string que vai conter o comando
    int x, y, a, b; // x: COLUNAS y:linhas a:1º variável do comando b:2º variável do comando

    if (sscanf(input, "%19s", comando) != 1) {  
        printf("Comando inválido\n");
        return;
    }
//----- se o comando for create-----//
    if (strncmp(comando, "create", 6) == 0) {  
        if (sscanf(input + 7, "%d,%d+%d,%d", &x, &y, &a, &b) == 4) { // colunaoca o comando do utilizador nas variáveis
            if(create(x-1, y-1, a, b, *retangulos, matriz)){ // se temos todas as variáveis necessárias, então cria retangulo
                (*retangulos)++;
            };
        } else {
            printf("Formato de comando de create inválido\n");
        }
//--------se o comando for moveleft------//
    } else if (strncmp(comando, "moveleft", 8) == 0) {
        if (sscanf(input + 9, "%d,%d+%d", &x, &y, &a) == 3) { // colunaoca o comando do utilizador nas variáveis
            moveleft(x-1, y-1, a, matriz); // se temos todas as variáveis necessárias, então arrasta retangulo para a esquerda
        } else {
            printf("Formato de comando de moveleft inválido\n");
        }
//--------se o comando for moveright------//
    } else if (strncmp(comando, "moveright", 9) == 0) {
        if (sscanf(input + 10, "%d,%d+%d", &x, &y, &a) == 3) {// colunaoca o comando do utilizador nas variáveis
            moveright(x-1, y-1, a, matriz); // se temos todas as variáveis necessárias, então arrasta retangulo para a direita
        } else {
            printf("Formato de comando de moveright inválido\n");
        }
//-----se o comando for delete -----//
    } else if (strncmp(comando, "delete", 6) == 0) { // colunaoca o comando do utilizador nas variáveis
        if (sscanf(input + 7, "%d,%d", &x, &y) == 2) { // se temos todas as variáveis necessárias, então apaga retangulo 
            delete(x-1, y-1, matriz);
        } else {
            printf("Formato de comando de delete inválido\n");
        }
    } else {
        printf("Comando inválido: %s\n", comando);
    }
}
