#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


Matrix* criarMatriz(int linhas, int colunas) {
    Matrix *matriz = (Matrix*)malloc(sizeof(Matrix));
    matriz->lin = linhas;
    matriz->col = colunas;

    No *temp = (No*)malloc(sizeof(No));
    matriz->inicio = temp;

    No *atual = temp;

    // Preenche a matriz com nós inicializados com valor 0.
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            atual->vlr = 0;
            if (j < colunas - 1) {
                atual->direita = (No*)malloc(sizeof(No));
                atual->direita->abaixo = NULL;
                atual->direita->direita = NULL;
                atual = atual->direita;
            }
        }
        if (i < linhas - 1) {
            temp->abaixo = (No*)malloc(sizeof(No));
            temp->abaixo->direita = NULL;
            temp->abaixo->abaixo = NULL;
            temp = temp->abaixo;
            atual = temp;
        }
    }
    return matriz;
}

void desalocarMatriz(Matrix *matriz) {
    No *atual = matriz->inicio;
    No *temp;

    while (atual != NULL) {
        while (atual != NULL) {
            temp = atual;
            atual = atual->direita;
            free(temp);
        }
        atual = matriz->inicio;
        matriz->inicio = matriz->inicio->abaixo;
        free(atual);
    }
    free(matriz);
}

// inserir um valor em uma posição específica na matriz.
int inserirValor(Matrix *matriz, int x, int y, int valor) {
    if (x < 0 || x >= matriz->lin || y < 0 || y >= matriz->col) {
        return 0; // Fora dos limites da matriz
    }

    No *atual = matriz->inicio;
    for (int i = 0; i < x; i++) {
        atual = atual->abaixo;
    }

    for (int j = 0; j < y; j++) {
        atual = atual->direita;
    }

    atual->vlr = valor;
    return 1; // confirmando operacao
}

// Função para inserir valores na matriz com entrada do usuário.
void inserirDadosNaMatriz(Matrix *matriz) {
    int valor, x, y;
    printf("Insira os dados na matriz. Use -1 para parar.\n");

    while (1) {
        printf("Digite o valor (-1 para parar): ");
        scanf("%d", &valor);

        if (valor == -1) {
            break;
        }

        printf("Digite a posição (x y): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= matriz->lin || y < 0 || y >= matriz->col) {
            printf("Posição inválida na matriz. Tente novamente.\n");
        } else {
            inserirValor(matriz, x, y, valor);
        }
    }
}

// Função para consultar e retornar um nó em uma posição específica na matriz.
No* consultarPosicao(Matrix *matriz, int x, int y) {
    if (x < 0 || x >= matriz->lin || y < 0 || y >= matriz->col) {
        return NULL; // Fora dos limites da matriz
    }

    No *atual = matriz->inicio;
    for (int i = 0; i < x; i++) {
        atual = atual->abaixo;
    }

    for (int j = 0; j < y; j++) {
        atual = atual->direita;
    }

    return atual;
}

// Função para buscar e retornar um nó com um valor específico na matriz.
No* buscarValor(Matrix *matriz, int valor) {
    No *atual = matriz->inicio;
    while (atual != NULL) {
        No *temp = atual;
        while (temp != NULL) {
            if (temp->vlr == valor) {
                return temp;
            }
            temp = temp->direita;
        }
        atual = atual->abaixo;
    }
    return NULL; // Valor não encontrado
}

// Função para imprimir os vizinhos de uma posição específica na matriz.
void imprimirVizinhos(Matrix *matriz, int x, int y) {
    No *no = consultarPosicao(matriz, x, y);
    if (no != NULL) {
        if (no->direita != NULL) {
            printf("Vizinho direito: %d\n", no->direita->vlr);
        }
        if (no->abaixo != NULL) {
            printf("Vizinho abaixo: %d\n", no->abaixo->vlr);
        }
        if (x > 0) {
            No *vizinhoAcima = matriz->inicio;
            for (int i = 0; i < x - 1; i++) {
                vizinhoAcima = vizinhoAcima->abaixo;
            }
            for (int i = 0; i < y; i++) {
                vizinhoAcima = vizinhoAcima->direita;
            }
            printf("Vizinho acima: %d\n", vizinhoAcima->vlr);
        }
        if (y > 0) {
            No *vizinhoEsquerda = matriz->inicio;
            for (int i = 0; i < x; i++) {
                vizinhoEsquerda = vizinhoEsquerda->abaixo;
            }
            for (int i = 0; i < y - 1; i++) {
                vizinhoEsquerda = vizinhoEsquerda->direita;
            }
            printf("Vizinho à esquerda: %d\n", vizinhoEsquerda->vlr);
        }
        if (x < matriz->lin - 1) {
            No *vizinhoAbaixo = matriz->inicio;
            for (int i = 0; i < x + 1; i++) {
                vizinhoAbaixo = vizinhoAbaixo->abaixo;
            }
            for (int i = 0; i < y; i++) {
                vizinhoAbaixo = vizinhoAbaixo->direita;
            }
            printf("Vizinho abaixo: %d\n", vizinhoAbaixo->vlr);
        }
    } else {
        printf("Posição inválida na matriz.\n");
    }
}
