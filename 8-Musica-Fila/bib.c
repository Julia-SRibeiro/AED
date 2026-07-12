#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

// FUNCTIONs
TipoFila* criaFila() {
    TipoFila *novaFila = (TipoFila*)malloc(sizeof(TipoFila));
    if(novaFila == NULL) {
        printf("Erro de memoria!");
        return NULL;
    }
    novaFila->topo = NULL;
    novaFila->fim = NULL;
    novaFila->tamanho = 0;
    printf("Fila criada!\n");
    return novaFila;
}
TipoDado* criaDado() {
    TipoDado *novoDado = (TipoDado*)malloc(sizeof(TipoDado));
    if(novoDado == NULL) {
        printf("Erro de memoria!");
        return NULL;
    }
    printf("Titulo: ");
    scanf(" %255[^\n]", novoDado->titulo);
    printf("Artista: ");
    scanf(" %255[^\n]", novoDado->artista);
    printf("Letra: ");
    scanf(" %255[^\n]", novoDado->letra);
    printf("Codigo: ");
    scanf("%d", &novoDado->codigo);
    printf("Execucoes: ");
    scanf("%d", &novoDado->execucoes);
    return novoDado;
}
TipoItem* criaItem(TipoDado *novoDado) {
    TipoItem *novoItem = (TipoItem*)malloc(sizeof(TipoItem));
        if(novoItem == NULL) {
        printf("Erro de memoria!");
        return NULL;
    }
    novoItem->dado = novoDado;
    novoItem->prox = NULL;
    return novoItem;
}

void enfileirar(TipoFila *fila, TipoItem *novoItem) {
    if(fila->tamanho == 0) {
        fila->topo = novoItem;
        fila->fim = novoItem;
    } else {
        fila->fim->prox = novoItem; // ultimo aponta para novo item
        fila->fim = novoItem; // novo item vira o ultimo
    }
    fila->tamanho++;
    printf("Dado inserido!\n");
}
TipoItem* desenfileirar(TipoFila *fila) {
    if (vazia(fila)) {
        TipoItem *temp = fila->topo; // aponta para o elemento a ser retirado
        fila->topo = fila->topo->prox; // novo topo eh prox do topo
        if(fila->topo == NULL) {fila->fim = fila->topo;}
        fila->tamanho--;
        printf("Dado retirado!\n");
        return temp;
    } else {printf("Pilha vazia\n");}
}

void imprimir(TipoFila *fila) {
    if (vazia(fila)) {
        TipoItem *temp = fila->topo;
        while(temp != NULL) {
            printf(
                "\nTitulo: %s\n"
                "Artista: %s\n"
                "Letra: %s\n"
                "Codigo: %d\n"
                "Execucoes: %d\n",
                temp->dado->titulo,
                temp->dado->artista,
                temp->dado->letra,
                temp->dado->codigo,
                temp->dado->execucoes
            );
            temp = temp->prox;
        }
    } else {
        printf("Fila vazia\n");
    }
}

TipoFila* deletar(TipoFila *fila) {
    while(fila->tamanho != 0) {
        free(desenfileirar(fila));
    }
    free(fila);
    fila = NULL;
    printf("Fila deletada!\n");
    return fila;
}

int vazia(TipoFila *fila) {
    if(fila->tamanho) return 1;
    else return 0;
}