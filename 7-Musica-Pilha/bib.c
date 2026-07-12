#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

// FUNCTIONS
TipoPilha* criaPilha() {
    TipoPilha *pilha = (TipoPilha*)malloc(sizeof(TipoPilha));
    if (pilha == NULL) {
        printf("Erro de memoria.\n");
        return NULL;
    }
    pilha->topo = NULL;
    pilha->tamanho = 0;
    printf("Pilha criada!\n");
    return pilha;
}
TipoDado* criaDado () {
    TipoDado *novoDado = (TipoDado*)malloc(sizeof(TipoDado));
    if (novoDado == NULL) {
        printf("Erro de memoria.\n");
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
TipoItem* criaItem (TipoDado *novoDado) {
    TipoItem *novoItem = (TipoItem*)malloc(sizeof(TipoItem));
    if (novoItem == NULL) {
        printf("Erro de memoria.\n");
        return NULL;
    }
    novoItem->dado = *novoDado;
    novoItem->prox = NULL;
    return novoItem;
}

void empilha(TipoPilha *pilha, TipoItem *item) {
    item->prox = pilha->topo;
    pilha->topo = item;
    pilha->tamanho++;
    printf("Dado inserido!\n");
}
TipoItem* desempilha (TipoPilha *pilha) {
    if (vazia(pilha)) {
        TipoItem *temp = pilha->topo; // aponta para o elemento a ser retirado
        pilha->topo = pilha->topo->prox; // novo topo eh o prox do topo: NULL
        pilha->tamanho--;
        printf("Dado retirado!\n");
        return temp;
    } else {
        printf("Pilha vazia\n");
    }
}

void imprime (TipoPilha* pilha) {
    if (vazia(pilha)) {
        TipoItem *temp = pilha->topo;
        while(temp != NULL) {
            printf(
                "\nTitulo: %s\n"
                "Artista: %s\n"
                "Letra: %s\n"
                "Codigo: %d\n"
                "Execucoes: %d\n",
                temp->dado.titulo,
                temp->dado.artista,
                temp->dado.letra,
                temp->dado.codigo,
                temp->dado.execucoes
            );
            temp = temp->prox;
        }
    } else {
        printf("Pilha vazia\n");
    }
}
void imprimeTopo(TipoPilha* pilha) {
    if (vazia(pilha)) {
        TipoItem *topo = pilha->topo;
        printf(
            "Titulo: %s\n"
            "Artista: %s\n"
            "Letra: %s\n"
            "Codigo: %d\n"
            "Execucoes: %d\n",
            topo->dado.titulo,
            topo->dado.artista,
            topo->dado.letra,
            topo->dado.codigo,
            topo->dado.execucoes
        );
    } else {
        printf("Pilha vazia\n");
    }
}

TipoPilha* deleta(TipoPilha *pilha) {
    while(pilha->tamanho != 0) {
        free(desempilha(pilha));
    }
    free(pilha);
    pilha = NULL;
    printf("Pilha deletada!\n");
    return pilha;
}

int vazia(TipoPilha *pilha) {
    if(pilha->tamanho) return 1;
    else return 0;
}