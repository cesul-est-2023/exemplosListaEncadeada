#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int valor;
    struct Item* proximo;
} Item;

typedef struct List {
    Item *inicio;
    Item *final;
    int tamanho;
} List;

List lista = {NULL, NULL, 0};

Item* criarItem(int valor) {
    Item* novoItem = malloc(sizeof(Item));
    novoItem->valor = valor;
    novoItem->proximo = NULL;

    return novoItem;
}

void adicionarItem(int valor) {
    Item* novoItem = criarItem(valor);

    if (lista.inicio == NULL) {
        lista.inicio = novoItem;
        lista.final = novoItem;
    } else {
        lista.final->proximo = novoItem;
        lista.final = novoItem;
    }

    lista.tamanho ++;
}

Item* obterItem(int pos) {
    Item* item = lista.inicio;
    int i = 0;

    while (i < pos && item != NULL) {
        item = item->proximo;
        i ++;
    }

    return item;
}

void exibirLista() {
    Item* item = lista.inicio;
    while (item != NULL) {
        printf("%d \n", item->valor);
        item = item->proximo;
    }
}

void removerItem(int pos) {
    Item* atual = lista.inicio;

    if (pos == 0) {
        lista.inicio = atual->proximo;

        if (lista.inicio == NULL) {
            lista.final = NULL;
        }

        free(atual);
        lista.tamanho --;
        return;
    }

    atual = obterItem(pos - 1);

    if (atual != NULL) {
        Item* itemRemover = atual->proximo;
        Item* novoProximo = itemRemover->proximo;

        atual->proximo = novoProximo;
        if (atual->proximo == NULL) { //indica que atual passou a ser o último da lista
            lista.final = atual;
        }

        free(itemRemover);
        lista.tamanho --;
    }
}

int main() {

    adicionarItem(5);
    adicionarItem(3);
    adicionarItem(7);
    adicionarItem(10);
    adicionarItem(12);

    printf("Tamanho da lista: %d \n", lista.tamanho);

    exibirLista();

    Item* item = obterItem(2);
    printf("A posicao 2 da lista tem o valor: %d\n", item->valor);

    printf("Removendo item da posição 0\n");

    removerItem(0);

    printf("Tamanho da lista: %d \n", lista.tamanho);
    printf("Lista após remoção: \n");

    exibirLista();

    return 0;
}
