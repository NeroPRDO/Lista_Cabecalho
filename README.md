# Lista Encadeada com Cabeçalho - Projeto em C

Este projeto implementa uma lista encadeada com nó de cabeçalho em linguagem C, com foco educacional. A lista permite diversas operações, incluindo inserções, remoções, busca, contagem, reversão, cópia, concatenação e remoção de duplicatas.

## 🧾 Estrutura do Projeto

O projeto é composto por três arquivos principais:

- `lista_cabecalho.h`: Arquivo de cabeçalho com definições de estruturas e protótipos de funções.
- `lista_cabecalho.c`: Implementação das funções da lista encadeada.
- `main.c`: Menu interativo que demonstra o funcionamento de todas as funcionalidades implementadas.

---

## ✅ Funcionalidades Implementadas

### 1. Inserir no início
Insere um valor no começo da lista (após o cabeçalho).

### 2. Inserir no final
Insere um valor no fim da lista.

### 3. Remover valor
Remove a primeira ocorrência do valor especificado.

### 4. Imprimir lista
Mostra todos os elementos da lista na ordem em que estão armazenados.

### 5. Contar elementos
Conta e retorna o número de elementos (nós) da lista, desconsiderando o cabeçalho.

### 6. Buscar valor
Verifica se um valor está presente na lista.

### 7. Reverter lista
Inverte a ordem dos elementos da lista **sem criar uma nova lista**, usando três ponteiros: `anterior`, `atual` e `próximo`.

### 8. Maior valor
Percorre a lista e retorna o **maior valor** armazenado. Se a lista estiver vazia, retorna -1 e exibe uma mensagem.

### 9. Menor valor
Percorre a lista e retorna o **menor valor** armazenado. Se a lista estiver vazia, retorna -1 e exibe uma mensagem.

### 10. Verificar se está vazia
Retorna `1` se não houver elementos após o nó de cabeçalho, e `0` caso contrário.

### 11. Copiar lista
Cria uma **cópia profunda** da lista, com os mesmos dados mas novos nós, ou seja, sem compartilhar ponteiros.

### 12. Concatenar nova lista
Concatena os elementos de uma nova lista ao final da atual. A nova lista é liberada após a operação.

### 13. Remover duplicatas
Remove valores duplicados da lista, mantendo apenas a **primeira ocorrência** de cada valor.

---

## 🖥️ Instruções de Compilação e Execução

### Requisitos
- Compilador C (ex: `gcc`)
- Terminal ou shell

### Compilação
gcc -o app_lista_cabecalho main.c lista_cabecalho.c

### Execução
./app_lista_cabecalho


📋 Uso do Menu Interativo
O menu permite escolher operações numericamente. Exemplo de uso:


====== MENU - Lista com Cabecalho ======
1. Inserir no inicio
2. Inserir no final
...
13. Remover duplicatas
0. Sair
========================================
Escolha uma opcao: 1
Digite o valor a inserir no inicio: 42
🧠 Comentários e Explicações
Todas as funções estão comentadas no código-fonte explicando sua lógica e propósito.

A lista utiliza um nó de cabeçalho (sentinela) para simplificar as operações de inserção e remoção.

O tipo dado armazenado na lista está definido como char dado[TAM_NOME], mas o código utiliza int nas chamadas. A tipagem pode ser adaptada conforme necessidade (ex: para int dado).

📁 Entrega
Todos os arquivos .c e .h estão organizados.

O main.c demonstra claramente o uso de cada função.

O projeto cumpre todos os requisitos propostos nas atividades.

📌 Observações Finais
  Este projeto serve como uma excelente base para o aprendizado de estruturas de dados, ponteiros e alocação dinâmica em C. A modularidade facilita a extensão futura com novas funcionalidades, como ordenação, inserção ordenada ou exportação para arquivo.

Autor: Pedro Eduardo Dall' Agnol - GRR20240844
Disciplina: Estrutura de Dados | UFPR
