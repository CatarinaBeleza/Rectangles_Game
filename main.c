#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "comandos.h"
#include "retangulo.h"
#include "gravidade.h"

#define LINHAS 25     // definido no enunciado
#define COLUNAS 80     // definido no enunciado


//------- Função principal -----//
int main()
{
    char matriz[LINHAS][COLUNAS]; // inicializar a matriz de desenho
    int retangulos = 0; // nº de retangulos existentes na matriz
    char linha[100];    // comando que o utilizador colunaoca

    limparMatriz(matriz); // colunaocar " " em todos os locais da matriz

    while(1){
    printf("Introduza um dos comandos: \n");
    if (fgets(linha, sizeof(linha), stdin)) {
        linha[strcspn(linha, "\n")] = 0;
        analisarComando(linha,matriz, &retangulos); // analisar o comando do utilizador
        verificaColisoes(matriz,retangulos); // aplica a gravidade e deteta colunaisões provocadas por esta
        imprimeMatriz(matriz); // imprime matriz
    }
   }
    return 0;
}
