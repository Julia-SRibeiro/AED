#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

// FUNCTIONs
Descritor *criaLista(void) {
    Descritor *novaLista = (Descritor*)malloc(sizeof(Descritor));
    novaLista->inicio = NULL;
    novaLista->tamanho = 0;
    return novaLista;
}
Nodo *criaItem(Dado *novoDado) {
    Nodo *novoItem = (Nodo*)malloc(sizeof(Nodo));
    novoItem->dados = novoDado;
    novoItem->proxItem = NULL;
    return novoItem;
}

void insere(Descritor *Lista, Nodo *novoItem, int posicao) {
    if(Lista->inicio == NULL || posicao == 0) { // insere no inicio
        novoItem->proxItem = Lista->inicio; // aponta para o antigo inicio
        Lista->inicio = novoItem; // passa a ser o novo inicio
    } else { // insere em x (caso maior que a lista, insere no final)
        Nodo *temp = Lista->inicio;
        for(int i=1; i < posicao && temp->proxItem != NULL; i++) {
            temp = temp->proxItem;
        }
        novoItem->proxItem = temp->proxItem; // proximo do novo aponta para proximo do anterior
        temp->proxItem = novoItem; // proximo do anterior aponta para novo
    }
    Lista->tamanho++;
}
Nodo *removeItem(Descritor *Lista, int posicao) {
    if(posicao < 0 || posicao >= Lista->tamanho) {
        printf("Posicao invalida!\n ");
        return NULL;
    } else {
        Nodo *temp = Lista->inicio;
        if(posicao == 0) { // Remove do inicio
            Lista->inicio = Lista->inicio->proxItem; // aponta para o proximo do inicio
            Lista->tamanho--;
            printf("Item removido.\n");
            return temp;
        } else { // Remove do meio ou do fim
            for (int i=0; i < posicao - 1; i++) { // procura anterior
                temp = temp->proxItem;
            }
            Nodo *atual = temp->proxItem;
            temp->proxItem = atual->proxItem; // proximo do anterior aponta para proximo do atual
            Lista->tamanho--;
            printf("Item removido.\n");
            return atual;
        }
    }   
}

Nodo *consulta(Descritor *Lista, int codigo) {
    Nodo *temp = Lista->inicio;
    while (temp != NULL) {
        if (temp->dados->codigo == codigo) {
            return temp;
        }
        temp = temp->proxItem;
    }
    printf("Codigo nao encontrado!\n");
    return NULL;
}

void imprime(Descritor *Lista) {
    Nodo *temp = Lista->inicio;
    while(temp != NULL) {
        printf(
            "\nTitulo: %s\n"
            "Artista: %s\n"
            "Letra:%s\n"
            "Codigo: %d\n"
            "Execucoes: %d\n",
            temp->dados->titulo,
            temp->dados->artista,
            temp->dados->letra,
            temp->dados->codigo,
            temp->dados->execucoes
        );
        temp = temp->proxItem;
    }
}