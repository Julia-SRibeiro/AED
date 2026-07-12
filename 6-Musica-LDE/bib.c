#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

// FUNCTIONs
Descritor *criaLista(void) {
    Descritor *novaLista = (Descritor*)malloc(sizeof(Descritor));
    novaLista->inicio = NULL;
    novaLista->fim = NULL;
    novaLista->tamanho = 0;
    return novaLista;
};
Nodo *criaItem(Dado *novoDado) {
    Nodo *novoItem = (Nodo*)malloc(sizeof(Nodo));
    novoItem->dados = novoDado;
    novoItem->ant = NULL;
    novoItem->proxItem = NULL;
    return novoItem;
}

void insere(Descritor *Lista, Nodo *novoItem, int posicao) {
    // INSERE NO INICIO
    if (Lista->inicio == NULL || posicao == 0) {
        novoItem->proxItem = Lista->inicio; // prox item eh o primeiro item
        novoItem->ant = NULL; // anterior nao existe
        if(Lista->inicio == NULL) {
            Lista->fim = novoItem; // se lista vazia, fim aponta para novoItem
        } else {
            Lista->inicio->ant = novoItem; // se nao vazia, atualiza ant do prox (antigo início)
        }
        Lista->inicio = novoItem;
    }
    // INSERE NO FINAL
    else if (posicao >= Lista->tamanho){
        Lista->fim->proxItem = novoItem; // ajusta prox do anterior
        novoItem->ant = Lista->fim; // aponta para anterior (antigo fim)
        Lista->fim = novoItem; // fim aponta para novo item
    } 
    // INSERE NA POSICAO X
    else {
        Nodo *temp = Lista->inicio;
        for(int i=0; i < posicao-1 && temp->proxItem != NULL; i++) { // procura anterior
            temp = temp->proxItem;
        }
        novoItem->proxItem = temp->proxItem; // aponta para proximo
        novoItem->ant = temp; // aponta para anterior
        temp->proxItem->ant = novoItem; // ajusta ant do proximo
        temp->proxItem = novoItem; // ajusta prox do anterior
    }
    Lista->tamanho++;
}
Nodo *removeItem(Descritor *Lista, int posicao) {  
    Nodo *temp = Lista->inicio;
    //REMOVE DO INICIO
    if(posicao == 0) {
        Lista->inicio = Lista->inicio->proxItem;
        if(Lista->inicio == NULL) {
            Lista->fim = NULL; // lista esvaziou
        } else {
            Lista->inicio->ant = NULL; // novo início não tem anterior
        }
    } 
    // REMOVE DO FINAL
    else if (posicao == Lista->tamanho-1) {
        temp = Lista->fim;
        Lista->fim = Lista->fim->ant; // fim recua para penultimo
        Lista->fim->proxItem = NULL; // novo fim aponta para NULL
    } 
    // REMOVE DA POSICAO X
    else {
        for (int i=0; i < posicao; i++) { // procura atual
            temp = temp->proxItem;
        }
        temp->ant->proxItem = temp->proxItem; // ajusta anterior
        temp->proxItem->ant = temp->ant; // ajusta proximo
    }
    Lista->tamanho--;
    printf("Item removido.\n");
    return temp;
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