#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct No {
    int vlr;
    struct No *direita;
    struct No *abaixo;
} No;

typedef struct {
    int lin;
    int col;
    No *inicio;
} Matrix;

Matrix* criarMatriz(int linhas, int colunas);
void desalocarMatriz(Matrix *matriz);
int inserirValor(Matrix *matriz, int x, int y, int valor);
No* consultarPosicao(Matrix *matriz, int x, int y);
No* buscarValor(Matrix *matriz, int valor);
void imprimirVizinhos(Matrix *matriz, int x, int y);

#endif
