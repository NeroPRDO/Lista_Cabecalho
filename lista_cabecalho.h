#ifndef LISTA_CABECALHO_H
#define LISTA_CABECALHO_H

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* cabeca; // Nó de cabeçalho
} Lista;

// Cria uma nova lista com nó de cabeçalho
Lista* criarLista();

// Insere um elemento no início da lista
void inserirInicio(Lista* lista, int valor);

// Insere um elemento no final da lista
void inserirFim(Lista* lista, int valor);

// Imprime todos os elementos da lista
void imprimirLista(Lista* lista);

// Remove um valor específico da lista
int remover(Lista* lista, int valor);

// Libera toda a memória da lista
void liberarLista(Lista* lista);

// Conta quantos elementos estão na lista
int contarElementos(Lista* lista);

// Busca um valor na lista (retorna 1 se encontrado, 0 caso contrário)
int buscar(Lista* lista, int valor);

// Reverte a lista encadeada
void reverterLista(Lista* lista);

// Retorna o maior valor da lista
int obterMaior(Lista* lista);

// Retorna o menor valor da lista
int obterMenor(Lista* lista);

// Verifica se a lista está vazia
int estaVazia(Lista* lista);

// Cria uma cópia profunda da lista
Lista* copiarLista(Lista* lista);

// Concatena a lista l2 ao final da lista l1
void concatenarListas(Lista* l1, Lista* l2);

// Remove valores duplicados da lista
void removerDuplicatas(Lista* lista);

#endif
