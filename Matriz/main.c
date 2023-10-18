#include <stdio.h>
#include "Matriz.h"

int main() {
    int n, m;
    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &n, &m);

    Matriz *mat = criarMatriz(n, m);

    // Inserir valores na matriz
    inserirValor(mat, 1, 1, 10.5);

    inserirValor(mat, 0, 1, 50.5);
    inserirValor(mat, 1, 0, 50.5);
    inserirValor(mat, 2, 1, 50.5);
    inserirValor(mat, 1, 2, 50.5);


    // Consultar valores na matriz
    double *valor = obterValor(mat, 1, 1);
    if (valor != NULL) {
        printf("Valor na posição (1, 1): %.2lf\n", *valor);
    } else {
        printf("Posição inválida.\n");
    }

    // Buscar valor na matriz
    double valorPesquisado = 20.3;
    double *result = pesquisarValor(mat, valorPesquisado);
    if (result != NULL) {
        printf("Valor %.2lf encontrado na posição (%d, %d)\n", valorPesquisado,
               (int)(result - &mat->no[0][0]) / mat->colunas,
               (int)(result - &mat->no[0][0]) % mat->colunas);
    } else {
        printf("Valor %.2lf não encontrado na matriz.\n", valorPesquisado);
    }

    // Imprimir vizinhos
    printf("Vizinhos da posição (1, 1):\n");
    obterVizinhos(mat, 1, 1);

    // Desalocar a matriz
    liberando(mat);

    return 0;
}
