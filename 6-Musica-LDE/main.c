/*
Atividade 6 - Musica LSE
Julia Soares Ribeiro - juliasr.aluno@unipampa.edu.br
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

int main() {
    int menu, posicao, codigo;
    Descritor *lista = NULL;
    Nodo *nodo;
    Dado *musica = NULL;

    do {
        printf(
            "\n==== MENU ====\n"
            "1- Criar lista\n"
            "2- Inserir\n"
            "3- Remover\n"
            "4- Consultar\n"
            "5- Imprimir\n"
            "==============\n"
            "Escolha uma opcao: "
        );
        scanf("%d", &menu);
    
        switch(menu) {
            case 0: 
                printf("Encerrando programa\n"); 
            break;
            case 1:
            if (lista == NULL) {
                lista = criaLista();
                printf("Lista criada!\n");
            } else {
                printf("Ja existe uma lista\n");
            }
            break;
            case 2:
            if(lista == NULL) {
                printf("Nao existe lista para inserir itens\n");
            } else {
                musica = malloc(sizeof(Dado));
                if (musica == NULL) {
                    printf("Erro de memoria.\n");
                } else {
                    printf("Titulo: ");
                    scanf(" %255[^\n]", musica->titulo);
                    printf("Artista: ");
                    scanf(" %255[^\n]", musica->artista);
                    printf("Letra: ");
                    scanf(" %255[^\n]", musica->letra);
                    printf("Codigo: ");
                    scanf("%d", &musica->codigo);
                    printf("Execucoes: ");
                    scanf("%d", &musica->execucoes);
                    printf("Posicao (0 para inicio): ");
                    scanf("%d", &posicao);
                    
                    nodo = criaItem(musica);
                    insere(lista, nodo, posicao);
                }
            }
            break;
            case 3:
                if (lista == NULL) {
                    printf("Nao existe lista para remover\n");
                    break;
                }
                if(lista->inicio == NULL) {
                    printf("Lista vazia!\n");
                    break;
                }
                printf("Posicao para remover: ");
                scanf("%d", &posicao);
                if(posicao < 0 || posicao >= lista->tamanho) {
                    printf("Posicao invalida!\n");
                    break;
                }
                nodo = removeItem(lista, posicao);
            break;
            case 4:
                if (lista == NULL) {
                    printf("Nao existe lista para consultar\n");
                    break;
                }
                if(lista->inicio == NULL) {
                    printf("Lista vazia!\n");
                    break;
                }
                printf("Codigo a consultar: ");
                scanf("%d", &codigo);
                nodo = consulta(lista, codigo);
                if (nodo != NULL) {
                    printf(
                        "Titulo: %s\n"
                        "Artista: %s\n"
                        "Codigo: %d\n"
                        "Execucoes: %d\n",
                        nodo->dados->titulo,
                        nodo->dados->artista,
                        nodo->dados->codigo,
                        nodo->dados->execucoes
                    );
                }
            break; 
            case 5:
                if (lista == NULL) {
                    printf("Nao existe lista para imprimir\n");
                    break;
                } 
                if(lista->inicio == NULL) {
                    printf("Lista vazia!\n");
                    break;
                }
                imprime(lista);
            break;
            default: printf("Opcao invalida!");
        }
    } while(menu!=0);
    return 0;
}