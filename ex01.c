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

void exibirLista(Item* inicio) {
    Item* item = inicio;
    while (item != NULL) {
        printf("%d \n", item->valor);
        item = item->proximo;
    }
}

int main() {
    Item* inicio = NULL;
    adicionarItem(&inicio, 5);
    adicionarItem(&inicio, 3);
    adicionarItem(&inicio, 7);
    adicionarItem(&inicio, 10);
    adicionarItem(&inicio, 12);

    exibirLista(inicio);

    Item* item = obterItem(&inicio, 2);
    printf("A posicao 2 da lista tem o valor: %d", item->valor);

    return 0;
}
