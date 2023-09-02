#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int valor;
    struct Item* proximo;
} Item;


Item* criarItem(int valor) {
    Item* novoItem = malloc(sizeof(Item));
    novoItem->valor = valor;
    novoItem->proximo = NULL;

    return novoItem;
}

void adicionarItem(Item** inicio, int valor) {
    Item* novoItem = criarItem(valor);

    if (*inicio == NULL) {
        *inicio = novoItem;
    } else {
        Item* atual = *inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }

        atual->proximo = novoItem;
    }
}

Item* obterItem(Item** inicio, int pos) {
    Item* item = *inicio;
    int i = 0;

    while (i < pos && item != NULL) {
        item = item->proximo;
        i ++;
    }

    return item;
}

void exibirLista(Item** inicio) {
    Item* item = *inicio;
    while (item != NULL) {
        printf("%d \n", item->valor);
        item = item->proximo;
    }
}

void removerItem(Item** inicio, int pos) {
    Item* atual = *inicio;

    if (pos == 0) {
        *inicio = atual->proximo;
        free(atual);
        return;
    }

    int i = 0;

    while (atual->proximo != NULL && i < pos - 1) {
        atual = atual->proximo;
        i++;
    }

    if (atual != NULL) {
        Item* itemRemover = atual->proximo;
        Item* novoProximo = itemRemover->proximo;

        atual->proximo = novoProximo;
        free(itemRemover);
    }
}

int main() {
    Item* inicio = NULL;
    adicionarItem(&inicio, 5);
    adicionarItem(&inicio, 3);
    adicionarItem(&inicio, 7);
    adicionarItem(&inicio, 10);
    adicionarItem(&inicio, 12);

    exibirLista(&inicio);

    Item* item = obterItem(&inicio, 2);
    printf("A posicao 2 da lista tem o valor: %d", item->valor);

    removerItem(&inicio, 0);
    printf("Removendo item da posição 0\n");
    printf("Lista após remoção: \n");

    exibirLista(&inicio);

    return 0;
}
