/*
Atividade 7 - Musica Pilha
Julia Soares Ribeiro - juliasr.aluno@unipampa.edu.br
*/

#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

int main() {
    TipoPilha *pilha = NULL;
    TipoItem *novoItem = NULL;
    TipoDado *novaMusica = NULL;
    int menu;

    do {
        printf(
            "\n============ MENU ============\n"
            "1- Criar Pilha\n"
            "2- Verifica pilha vazia (Empty)\n"
            "3- Empilhar (Push)\n"
            "4- Desempilha (Pop)\n"
            "5- Imprimir pilha\n"
            "6- Imprime tamanho\n"
            "7- Imprime topo\n"
            "8- Deletar Pilha\n"
            "0- sair\n"
            "Escolha um numero: "
        );
        scanf("%d", &menu);

        switch (menu) {
            case 0:
                printf("Encerrando programa\n");
            break;
            case 1:
                if(pilha == NULL) {
                    pilha = criaPilha();
                } else {
                    printf("Ja ha uma pilha criada\n");
                }
            break;
            case 2:
                if(pilha == NULL) {
                    printf("Pilha inexistente.\n");
                    break;
                }
                if (vazia(pilha)) {
                    printf("Pilha nao vazia\n");
                } else {
                    printf("Pilha vazia\n");
                }
            break;
            case 3:
                if(pilha == NULL) {
                    printf("Pilha inexistente.\n");
                    break;
                }
                novaMusica = criaDado();
                novoItem  = criaItem(novaMusica);
                empilha(pilha, novoItem);
            break;
            case 4:
                if(pilha == NULL) {
                    printf("Pilha inexistente.\n");
                    break;
                }
                desempilha(pilha);
            break;
            case 5:
                if(pilha == NULL) {
                    printf("Pilha inexistente.\n");
                    break;
                }
                imprime(pilha);
            break;
            case 6:
                if(pilha == NULL) {
                    printf("Pilha inexistente.\n");
                    break;
                }
                printf("Tamanho da pilha: %d\n", pilha->tamanho);
            break;
            case 7:
                if(pilha == NULL) {
                    printf("Pilha inexistente.\n");
                    break;
                }
                imprimeTopo(pilha);
            break;
            case 8:
                if(pilha == NULL) {
                    printf("Pilha inexistente.\n");
                    break;
                }
                pilha = deleta(pilha);
            break;
            default: 
                printf("Numero invalido!");
            break;
        }
    } while (menu !=0);
    return 0;
}