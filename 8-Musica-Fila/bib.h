#ifndef BIB_H
#define BIB_H

// STRUCTs
typedef struct {
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes;
} TipoDado;
typedef struct tipoItem {
    TipoDado *dado;
    struct tipoItem *prox;
} TipoItem;
typedef struct tipoFila {
    TipoItem *topo, *fim;
    int tamanho;
} TipoFila;

// PROTOTIPOS
TipoFila* criaFila();
TipoDado* criaDado();
TipoItem* criaItem(TipoDado *novoDado);
void enfileirar(TipoFila *fila, TipoItem *novoItem);
TipoItem* desenfileirar(TipoFila *fila);
void imprimir(TipoFila *fila);
int vazia(TipoFila *fila);
TipoFila* deletar(TipoFila *fila);

#endif