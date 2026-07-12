/*
Atividade 8 - Musica Fila
Julia Soares Ribeiro - juliasr.aluno@unipampa.edu.br
*/

#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

int main() {
    TipoFila *fila = NULL;
    TipoItem *novoItem = NULL;
    TipoDado *novaMusica = NULL;
    int menu;

    do {
        printf(
            "\n============ MENU ============\n"
            "1- Criar fila\n"
            "2- Verifica fila vazia (Empty)\n"
            "3- Enfileirar (Push)\n" //cria item
            "4- Desenfileirar (Pop)\n"
            "5- Imprimit fila\n"
            "6- Imprime tamanho\n"
            "7- Deletar fila\n"
            "0- sair\n"
            "Escolha um numero: "
        );
        scanf("%d", &menu);

        switch (menu) {
            case 0:
                printf("Encerrando programa\n");
            break;
            case 1:
                if(fila == NULL) {
                    fila = criaFila();
                } else {
                    printf("Ja ha uma fila criada\n");
                }
            break;
            case 2:
                if(fila == NULL) {
                    printf("fila inexistente.\n");
                    break;
                }
                if (vazia(fila)) {
                    printf("fila nao vazia\n");
                } else {
                    printf("fila vazia\n");
                }
            break;
            case 3:
                if(fila == NULL) {
                    printf("fila inexistente.\n");
                    break;
                }
                novaMusica = criaDado();
                novoItem  = criaItem(novaMusica);
                enfileirar(fila, novoItem);
            break;
            case 4:
                if(fila == NULL) {
                    printf("fila inexistente.\n");
                    break;
                }
                desenfileirar(fila);
            break;
            case 5:
                if(fila == NULL) {
                    printf("fila inexistente.\n");
                    break;
                }
                imprimir(fila);
            break;
            case 6:
                if(fila == NULL) {
                    printf("fila inexistente.\n");
                    break;
                }
                printf("Tamanho da fila: %d\n", fila->tamanho);
            break;
            case 7:
                if(fila == NULL) {
                    printf("fila inexistente.\n");
                    break;
                }
                fila = deletar(fila);
            break;
            default: 
                printf("Numero invalido!");
            break;
        }
    } while (menu !=0);
    return 0;
}