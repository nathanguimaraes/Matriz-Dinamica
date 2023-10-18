#include "Matriz.h"
#include <stdio.h>
#include <stdlib.h>

Matriz* criarMatriz(int linhas, int colunas) {
    Matriz *matriz = malloc(sizeof(Matriz));
    if (matriz == NULL) {
        fprintf(stderr, "Erro na alocação de memória para a matriz.\n");
        exit(EXIT_FAILURE);
    }

    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->no = malloc(linhas * sizeof(double *));
    if (matriz->no == NULL) {
        fprintf(stderr, "Erro na alocação de memória para os nós da matriz.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < linhas; i++) {
        matriz->no[i] = calloc(colunas, sizeof(double));
        if (matriz->no[i] == NULL) {
            fprintf(stderr, "Erro na alocação de memória para os nós da matriz.\n");
            exit(EXIT_FAILURE);
        }
    }

    return matriz;
}



int inserirValor(Matriz *matriz, int linha, int coluna, double value) {
    if (linha >= 0 && linha < matriz->linhas && coluna >= 0 && coluna < matriz->colunas) {
        matriz->no[linha][coluna] = value;
        return 1;
    }
    return 0;
}

double* obterValor(Matriz *matriz, int linha, int coluna) {
    if (linha >= 0 && linha < matriz->linhas && coluna >= 0 && coluna < matriz->colunas) {
        return &matriz->no[linha][coluna];
    }
    return NULL;
}

double* pesquisarValor(Matriz *matriz, double value) {
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            if (matriz->no[i][j] == value) {
                return &matriz->no[i][j];
            }
        }
    }
    return NULL;
}

void obterVizinhos(Matriz *matriz, int linha, int coluna) {
    if (linha - 1 >= 0) {
        printf("Vizinho superior: %.2lf\n", matriz->no[linha - 1][coluna]);
    }
    if (linha + 1 < matriz->linhas) {
        printf("Vizinho  abaixo: %.2lf\n", matriz->no[linha + 1][coluna]);
    }
    if (coluna - 1 >= 0) {
        printf("Vizinho esquerda: %.2lf\n", matriz->no[linha][coluna - 1]);
    }
    if (coluna + 1 < matriz->colunas) {
        printf("Vizinho direita: %.2lf\n", matriz->no[linha][coluna + 1]);
    }
}


void liberando(Matriz *matriz) {                                                        //liberando nos
    for (int i = 0; i < matriz->linhas; i++) {
        free(matriz->no[i]);
    }
    free(matriz->no);
    free(matriz);
}
