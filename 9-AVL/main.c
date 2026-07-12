/*
Atividade 9 - AVL
Julia Soares Ribeiro - juliasr.aluno@unipampa.edu.br
*/

#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

int main() {
    TipoAVL *avl = NULL;
    int menu, dado;

    do {
        printf(
            "\n"
            "=== MENU AVL ===\n"
            "1- Criar AVL\n"
            "2- Inserir\n"
            "3- Remover\n"
            "4- Percursos\n"
            "================\n"
            "Escolha uma opcao: "
        );
        scanf("%d", &menu);
        printf("\n");

        switch(menu) {
            case 0: printf("Encerrando programa.\n"); break;
            case 1: 
                if (avl == NULL) {avl = criar_arvore(); break;}
                printf("Arvore ja existe!\n");
                break;
            case 2:
                if (avl == NULL) {printf("Arvore inexistente!\n"); break;}
                printf("Insira o numero: ");
                scanf("%d", &dado);
                avl->raiz = inserir(avl->raiz, NULL, dado);
                exibirArvore(avl->raiz, 0);
            break;
            case 3:
                if (avl == NULL) {printf("Arvore inexistente!\n"); break;}
                printf("Insira o numero: ");
                scanf("%d", &dado);
                avl->raiz = remover(avl->raiz, dado);
                exibirArvore(avl->raiz, 0);
            break;
            case 4: 
                if (avl == NULL) {printf("Arvore inexistente!\n"); break;}
                menu_percursos(avl->raiz); break;
            default: printf("Opcao invalida!"); break;
        }
    } while(menu);

    return 0;
}