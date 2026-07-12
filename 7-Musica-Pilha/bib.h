#ifndef BIB_H
#define BIB_H

//STRUCTS
typedef struct {
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes;
} TipoDado;
typedef struct tipoItem {
    TipoDado dado;
    struct tipoItem *prox;
} TipoItem;
typedef struct tipoPilha {
    TipoItem *topo;
    int tamanho;
} TipoPilha;


// PROTOTIPOS
TipoPilha* criaPilha();
TipoDado* criaDado();
TipoItem* criaItem(TipoDado *novoDado);
void empilha(TipoPilha *pilha, TipoItem *novoItem); // Push
TipoItem* desempilha (TipoPilha *pilha); // Pop
TipoPilha* deleta(TipoPilha *pilha); // Delete
void imprime(TipoPilha *pilha); // Show
void imprimeTopo(TipoPilha *pilha); // Top
int vazia(TipoPilha *pilha); // Empty

#endif