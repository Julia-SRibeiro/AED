#ifndef BIB_H
#define BIB_H

//STRUCTs
typedef struct tipoItem{
    struct tipoItem *esq, *pai, *dir;
    int dado, altura, balanco;
} TipoItem;
typedef struct tipoAVL{
    TipoItem *raiz;
} TipoAVL;

// FUNCITIONs
TipoAVL* criar_arvore();
TipoItem* criar_item(int dado);
TipoItem* inserir(TipoItem *atual, TipoItem *pai, int novoDado);
TipoItem* remover(TipoItem *atual, int dado);
TipoItem* balancear(TipoItem *atual);
TipoItem* maiorEsq(TipoItem *atual);
int obter_altura(TipoItem *no);
void atualizar_rotacao_altura(TipoItem *no);
TipoItem* rotacaoEsquerda(TipoItem *x);
TipoItem* rotacaoDireita(TipoItem *x);
TipoItem* rotacaoDuplaEsquerda(TipoItem *x);
TipoItem* rotacaoDuplaDireita(TipoItem *x);
void menu_percursos(TipoItem* raiz);
void emOrdem(TipoItem *raiz);
void preOrdem(TipoItem *raiz);
void exibirArvore(TipoItem* raiz, int nivel);

#endif