#include <stdio.h>
#include <stdlib.h>
#include "lista_cabecalho.h"

// Exibe o menu interativo sem acentos
void mostrarMenu() {
    printf("\n====== MENU - Lista com Cabecalho ======\n");
    printf("1. Inserir no inicio\n");
    printf("2. Inserir no final\n");
    printf("3. Remover valor\n");
    printf("4. Imprimir lista\n");
    printf("5. Contar elementos\n");
    printf("6. Buscar valor\n");
    printf("7. Reverter lista\n");
    printf("8. Maior valor\n");
    printf("9. Menor valor\n");
    printf("10. Verificar se esta vazia\n");
    printf("11. Copiar lista\n");
    printf("12. Concatenar nova lista\n");
    printf("13. Remover duplicatas\n");
    printf("0. Sair\n");
    printf("========================================\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Lista* lista = criarLista();
    Lista* copia = NULL;
    int opcao, valor, resultado;

    int valoresIniciais[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        inserirFim(lista, valoresIniciais[i]);
    }
    do {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir no inicio: ");
                scanf("%d", &valor);
                inserirInicio(lista, valor);
                break;

            case 2:
                printf("Digite o valor a inserir no final: ");
                scanf("%d", &valor);
                inserirFim(lista, valor);
                break;

            case 3:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                resultado = remover(lista, valor);
                if (resultado)
                    printf("Valor removido com sucesso.\n");
                else
                    printf("Valor nao encontrado.\n");
                break;

            case 4:
                imprimirLista(lista);
                break;

            case 5:
                printf("A lista contem %d elemento(s).\n", contarElementos(lista));
                break;

            case 6:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                resultado = buscar(lista, valor);
                if (resultado)
                    printf("Valor encontrado.\n");
                else
                    printf("Valor nao encontrado.\n");
                break;

            case 7:
                reverterLista(lista);
                printf("Lista revertida.\n");
                break;

            case 8:
                resultado = obterMaior(lista);
                if (resultado != -1)
                    printf("Maior valor: %d\n", resultado);
                break;

            case 9:
                resultado = obterMenor(lista);
                if (resultado != -1)
                    printf("Menor valor: %d\n", resultado);
                break;

            case 10:
                if (estaVazia(lista))
                    printf("A lista esta vazia.\n");
                else
                    printf("A lista NAO esta vazia.\n");
                break;

            case 11:
                copia = copiarLista(lista);
                printf("Lista copiada:\n");
                imprimirLista(copia);
                break;

            case 12: {
                Lista* nova = criarLista();
                int qtd, val;
                printf("Quantos valores inserir na nova lista para concatenar? ");
                scanf("%d", &qtd);
                for (int i = 0; i < qtd; i++) {
                    printf("Valor %d: ", i + 1);
                    scanf("%d", &val);
                    inserirFim(nova, val);
                }
                concatenarListas(lista, nova);
                printf("Listas concatenadas.\n");
                break;
            }

            case 13:
                removerDuplicatas(lista);
                printf("Duplicatas removidas.\n");
                break;

            case 0:
                liberarLista(lista);
                if (copia != NULL)
                    liberarLista(copia);
                printf("Encerrando programa.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
