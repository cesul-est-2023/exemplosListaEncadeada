#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int valor;
    struct Item* proximo;
} Item;

Item* inicio = NULL;
Item* final = NULL;
int tamanho = 0;

Item* criarItem(int valor) {
    Item* novoItem = malloc(sizeof(Item));
    novoItem->valor = valor;
    novoItem->proximo = NULL;

    return novoItem;
}

void adicionarItem(int valor) {
    Item* novoItem = criarItem(valor);

    if (inicio == NULL) {
        inicio = novoItem;
        final = novoItem;
    } else {
        final->proximo = novoItem;
        final = novoItem;
    }

    tamanho ++;
}

Item* obterItem(int pos) {
    Item* item = inicio;
    int i = 0;

    while (i < pos && item != NULL) {
        item = item->proximo;
        i ++;
    }

    return item;
}

void exibirLista() {
    Item* item = inicio;
    while (item != NULL) {
        printf("%d \n", item->valor);
        item = item->proximo;
    }
}

void removerItem(int pos) {
    Item* atual = inicio;

    if (pos == 0) {
        inicio = atual->proximo;
        free(atual);
        tamanho --;
        return;
    }

    atual = obterItem(pos - 1);

    if (atual != NULL) {
        Item* itemRemover = atual->proximo;
        Item* novoProximo = itemRemover->proximo;

        atual->proximo = novoProximo;
        free(itemRemover);
        tamanho --;
    }
}

int main() {
    adicionarItem(5);
    adicionarItem(3);
    adicionarItem(7);
    adicionarItem(10);
    adicionarItem(12);

    printf("Tamanho da lista: %d \n", tamanho);

    exibirLista();

    Item* item = obterItem(2);
    printf("A posicao 2 da lista tem o valor: %d\n", item->valor);

    printf("Removendo item da posição 0\n");

    removerItem(0);

    printf("Tamanho da lista: %d \n", tamanho);
    printf("Lista após remoção: \n");

    exibirLista();

    return 0;
}
