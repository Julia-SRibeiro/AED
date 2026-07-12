#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

TipoAVL* criar_arvore() {
    TipoAVL *avl = (TipoAVL*) malloc(sizeof(TipoAVL));
    avl->raiz = NULL;
    printf("AVL criada!\n");
    return avl;
}
TipoItem* criar_item(int dado) {
    TipoItem *chave = (TipoItem*) malloc(sizeof(TipoItem));
    chave->dado = dado;
    chave->esq = chave->dir = chave->pai = NULL;
    chave->altura = 0;
    chave->balanco = 0;
    return chave;
}

TipoItem* inserir(TipoItem *atual, TipoItem *pai, int novoDado) {
    if(atual == NULL) { // Dado nao esta na arvore, insere
        TipoItem *novaChave = criar_item(novoDado);
        novaChave->pai = pai;
        return novaChave;
	}

    if(novoDado < atual->dado) {atual->esq = inserir(atual->esq, atual, novoDado);} // Menor, navega para esquerda
    else if(novoDado > atual->dado) {atual->dir = inserir(atual->dir, atual, novoDado);} // Maior, navega para direita

    else {return atual;} // Dado ja esta na arvore, nao faz nada
    return balancear(atual);
}
TipoItem* remover(TipoItem *atual, int dado) {
    if(atual == NULL) {return NULL;} // Dado não esta na arvore, nao faz nada

    if(dado < atual->dado) {atual->esq = remover(atual->esq, dado);} // Menor, navega para esquerda 
    else if(dado > atual->dado) {atual->dir = remover(atual->dir, dado);} // Maior, navega para direita

    else { // Dado esta na arvore, remove
        if(!atual->esq || !atual->dir) { // Filhos: 0 ou 1
            TipoItem* temp = atual->esq ? atual->esq : atual->dir;
            if (temp) {temp->pai = atual->pai;} // Se houver filho, avo adota
            free(atual);
            return temp; // Retorna filho do deletado
        } else {
            TipoItem* temp = maiorEsq(atual); // Acha antecessor, maior valor menor que o atual
            atual->dado = temp->dado; // Substitui atual pelo antecessor
            atual->esq = remover(atual->esq, temp->dado); // Navega novamente ate o antecessor Remove antigo posicao do antecessor
        }
    }
    return balancear(atual);
}
TipoItem* maiorEsq(TipoItem *atual) {
    atual = atual->esq;
    while (atual != NULL && atual->dir != NULL) {atual = atual->dir;}
    return atual;
}

TipoItem* rotacaoEsquerda(TipoItem* x) {
    printf("Rotacao a esquerda!\n");
    TipoItem* y = x->dir;

    x->dir = y->esq;
    if (y->esq) {y->esq->pai = x;}
    y->esq = x;
    y->pai = x->pai;
    x->pai = y;

    atualizar_rotacao_altura(x);
    atualizar_rotacao_altura(y);

    return y;
}
TipoItem* rotacaoDireita(TipoItem* x) {
    printf("Rotacao a direita!\n");
    TipoItem* y = x->esq;

    x->esq = y->dir;
    if (y->dir) {y->dir->pai = x;}
    y->dir = x;
    y->pai = x->pai;
    x->pai = y;

    atualizar_rotacao_altura(x);
    atualizar_rotacao_altura(y);

    return y;
}
TipoItem* rotacaoDuplaEsquerda(TipoItem* x) {
    printf("Rotacao DUPLA ESQUERDA!\n");
    x->dir = rotacaoDireita(x->dir);
    return rotacaoEsquerda(x);
}
TipoItem* rotacaoDuplaDireita(TipoItem* x) {
    printf("Rotacao DUPLA DIREITA!\n");
    x->esq = rotacaoEsquerda(x->esq);
    return rotacaoDireita(x);
}

int obter_altura(TipoItem* no) {
    return no ? no->altura : -1;
}

void atualizar_rotacao_altura(TipoItem* no) {
    // Altura
    int altEsq = obter_altura(no->esq);
    int altDir = obter_altura(no->dir);
    no->altura = (altEsq > altDir ? altEsq : altDir) + 1;
    
    // Fator de balanceamento
    no->balanco = altEsq - altDir;
}

TipoItem* balancear(TipoItem* no) {
    if (no == NULL) return NULL;

    atualizar_rotacao_altura(no);

    // Desbalanceado para a ESQUERDA (Fator positivo: +2)
    if (no->balanco == 2) {
        atualizar_rotacao_altura(no->esq); 
        if (no->esq->balanco >= 0) { // Se o filho esquerdo tiver FB >= 0, é rotação simples. Caso contrário, dupla.
            return rotacaoDireita(no);         
        } else {
            return rotacaoDuplaDireita(no);
        }
    } 
    // Desbalanceado para a DIREITA (Fator negativo: -2)
    else if (no->balanco == -2) {
        atualizar_rotacao_altura(no->dir); 
        if (no->dir->balanco <= 0) { // Se o filho direito tiver FB <= 0, é rotação simples. Caso contrário, dupla.
            return rotacaoEsquerda(no);        
        } else {
            return rotacaoDuplaEsquerda(no);  
        }
    }
    return no;
}

void emOrdem(TipoItem* raiz) {
    if (raiz) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->dado);
        emOrdem(raiz->dir);
    }
}
void preOrdem(TipoItem* raiz) {
    if (raiz) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}
void exibirArvore(TipoItem* raiz, int nivel) {
    if (raiz) {
        exibirArvore(raiz->dir, nivel + 1);
        for (int i = 0; i < nivel; i++) {printf("    ");}
        printf("%d\n", raiz->dado);
        exibirArvore(raiz->esq, nivel + 1);
    }
}
void menu_percursos(TipoItem* raiz) {
    int menu;
    do {
        printf(
            "\n"
            "<--- MENU PERCURSOS --->\n"
            "1- Em ordem (In-order)\n"
            "2- Pre ordem (Pre order)\n"
            "<---------------------->\n"
            "Escolha uma opcao: "
        );
        scanf("%d", &menu);
        printf("\n");

        switch(menu) {
            case 0: break;
            case 1: emOrdem(raiz); break;
            case 2: preOrdem(raiz); break;
            default: printf("Opcao invalida!"); break;
        }
    } while (menu);
}