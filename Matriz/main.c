#include <stdio.h>
#include "matriz.h"

//Alunos: Nathan Guimarães e Natal Machado
int main() {
    int linhas = 3;
    int colunas = 3;
    Matrix *matriz = criarMatriz(linhas, colunas);

    inserirDadosNaMatriz(matriz);

    /*inserirValor(matriz, 0, 0, 1);
    inserirValor(matriz, 1, 1, 2);
    inserirValor(matriz, 2, 2, 3);
*/
    No *no = consultarPosicao(matriz, 1, 1);
    if (no != NULL) {
        printf("Valor na posição (1, 1): %d\n", no->vlr);
    } else {
        printf("Posição inválida na matriz.\n");
    }

    no = buscarValor(matriz, 2);
    if (no != NULL) {
        printf("Valor 2 encontrado na posição (%d, %d)\n", no->vlr, no->vlr);
    } else {
        printf("Valor não encontrado na matriz.\n");
    }

    printf("Vizinhos de (1, 1):\n");
    imprimirVizinhos(matriz, 1, 1);

    desalocarMatriz(matriz);

    return 0;
}
