#ifndef BIB_H
#define BIB_H

// STRUCTs
typedef struct {
    char titulo[256], artista[256], letra[256];
    int codigo, execucoes;
} Dado;
typedef struct nodo{
    Dado *dados;
    struct nodo *proxItem;
} Nodo;
typedef struct descritor{
    Nodo *inicio;
    int tamanho;
} Descritor;

// PROTOTIPOS
Descritor* criaLista(void);
Nodo* criaItem(Dado *novoDado);
void insere(Descritor *Lista, Nodo *novoItem, int posicao);
Nodo* removeItem(Descritor *Lista, int posicao);
Nodo* consulta(Descritor *Lista, int codigo);
void imprime(Descritor *Lista);

#endif