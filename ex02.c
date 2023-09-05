#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int valor;
    struct Item* proximo;
    struct Item* anterior;
} Item;

Item* criarItem(int valor) {
    Item* novoItem = malloc(sizeof(Item));
    novoItem->valor = valor;
    novoItem->proximo = NULL;
    novoItem->anterior = NULL;

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
        novoItem->anterior = atual;
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

void exibirListaReversa(Item** final) {
    Item* item = *final;
    while (item != NULL) {
        printf("%d \n", item->valor);
        item = item->anterior;
    }
}

void removerItem(Item** inicio, int pos) {
    Item* atual = *inicio;

    if (pos == 0) {
        *inicio = atual->proximo;
        (*inicio)->anterior = NULL;
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
        novoProximo->anterior = atual;

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
    printf("A posicao 2 da lista tem o valor: %d\n", item->valor);

    removerItem(&inicio, 0);
    printf("Removendo item da posição 0\n");
    printf("Lista após remoção: \n");

    exibirLista(&inicio);

    Item* ultimo = obterItem(&inicio, 3); // obtém o ultimo item da lista
    printf("Exibindo a lista reversa: \n");
    exibirListaReversa(&ultimo);

    return 0;
}
