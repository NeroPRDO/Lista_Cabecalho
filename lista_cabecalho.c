#include <stdio.h>
#include <stdlib.h>
#include "lista_cabecalho.h"

// Cria uma nova lista com nó de cabeçalho (sentinela)
Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->cabeca = (No*)malloc(sizeof(No)); // nó de cabeçalho
    lista->cabeca->prox = NULL;
    return lista;
}

// Insere um novo elemento no início da lista
void inserirInicio(Lista* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = lista->cabeca->prox;
    lista->cabeca->prox = novo;
}

// Insere um novo elemento no final da lista
void inserirFim(Lista* lista, int valor) {
    No* atual = lista->cabeca;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    atual->prox = novo;
}

// Imprime todos os elementos da lista
void imprimirLista(Lista* lista) {
    No* atual = lista->cabeca->prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Remove o primeiro nó que contém o valor especificado
int remover(Lista* lista, int valor) {
    No* ant = lista->cabeca;
    No* atual = ant->prox;
    while (atual != NULL && atual->dado != valor) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return 0; // Valor não encontrado
    ant->prox = atual->prox;
    free(atual);
    return 1; // Removido com sucesso
}

// Libera todos os nós da lista, incluindo o nó de cabeçalho
void liberarLista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}

// Conta e retorna o número de elementos na lista (excluindo o cabeçalho)
int contarElementos(Lista* lista) {
    int count = 0;
    No* atual = lista->cabeca->prox;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

// Busca por um valor na lista. Retorna 1 se encontrado, 0 caso contrário.
int buscar(Lista* lista, int valor) {
    No* atual = lista->cabeca->prox;
    while (atual != NULL) {
        if (atual->dado == valor) return 1;
        atual = atual->prox;
    }
    return 0;
}

// Reverte a lista encadeada in-place, sem criar uma nova lista
void reverterLista(Lista* lista) {
    No* anterior = NULL;
    No* atual = lista->cabeca->prox;
    No* proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    lista->cabeca->prox = anterior;
}

// Retorna o maior valor presente na lista. Retorna -1 se a lista estiver vazia.
int obterMaior(Lista* lista) {
    if (lista->cabeca->prox == NULL) {
        printf("Lista vazia.\n");
        return -1;
    }
    int maior = lista->cabeca->prox->dado;
    No* atual = lista->cabeca->prox->prox;
    while (atual != NULL) {
        if (atual->dado > maior) maior = atual->dado;
        atual = atual->prox;
    }
    return maior;
}

// Retorna o menor valor presente na lista. Retorna -1 se a lista estiver vazia.
int obterMenor(Lista* lista) {
    if (lista->cabeca->prox == NULL) {
        printf("Lista vazia.\n");
        return -1;
    }
    int menor = lista->cabeca->prox->dado;
    No* atual = lista->cabeca->prox->prox;
    while (atual != NULL) {
        if (atual->dado < menor) menor = atual->dado;
        atual = atual->prox;
    }
    return menor;
}

// Verifica se a lista está vazia (sem nós de dados)
int estaVazia(Lista* lista) {
    return lista->cabeca->prox == NULL;
}

// Cria uma cópia profunda da lista (sem compartilhar ponteiros)
Lista* copiarLista(Lista* lista) {
    Lista* nova = criarLista();
    No* atual = lista->cabeca->prox;
    No* fim = nova->cabeca;
    while (atual != NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->dado = atual->dado;
        novo->prox = NULL;
        fim->prox = novo;
        fim = novo;
        atual = atual->prox;
    }
    return nova;
}

// Concatena a lista l2 ao final da lista l1. Esvazia l2 ao final.
void concatenarListas(Lista* l1, Lista* l2) {
    No* atual = l1->cabeca;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = l2->cabeca->prox;
    free(l2->cabeca);
    free(l2);
}

// Remove nós com valores duplicados, mantendo apenas a primeira ocorrência
void removerDuplicatas(Lista* lista) {
    No* atual = lista->cabeca->prox;
    while (atual != NULL) {
        No* ant = atual;
        No* temp = atual->prox;
        while (temp != NULL) {
            if (temp->dado == atual->dado) {
                ant->prox = temp->prox;
                free(temp);
                temp = ant->prox;
            } else {
                ant = temp;
                temp = temp->prox;
            }
        }
        atual = atual->prox;
    }
}
