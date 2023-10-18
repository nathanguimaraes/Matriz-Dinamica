
#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
    double **no;
    int linhas;
    int colunas;
} Matriz;

Matriz* criarMatriz(int rows, int colunas);
void liberando(Matriz *matriz);
int inserirValor(Matriz *matriz, int linhas, int colunas, double valor);
double* obterValor(Matriz *matriz, int linhas, int colunas);
double* pesquisarValor(Matriz *matriz, double valor);
void obterVizinhos(Matriz *matriz, int linhas, int colunas);

#endif /* MATRIZ_H */
