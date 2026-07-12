/*
Atividade 10/11 - Grafos Lista de adjascencia
Julia Soares Ribeiro - juliasr.aluno@unipampa.edu.br
*/

/*
Implemente uma estrutura de grafos por lista de adjacência;
Seu programa deverá ser capaz de:
• Carregar a descrição do grafo como um arquivo de texto, onde:
    A primeira linha descreverá a quantidade de nodos;
    As próximas linhas descreverão as arestas entre os vértices e seu peso;
• Imprimir as relações do grafo (vértices e suas adjacências) da lista adjacência.
• Implemente um dos algoritmos:
    BFS – busca por largura na sua TAD de grafos.
    DFS – busca em profundidade na sua TAD de grafos.
*/

#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

int main() {
    int menu, vertice;
    TipoGrafo *grafo = NULL;

    do {
        printf(
            "\n"
            "====== MENU ======\n"
            "1- Carregar grafo\n"
            "2- Imprimir grafo\n"
            "3- Busca DSF\n"
            "4- Busca BSF\n"
            "0- Sair\n"
            "==================\n"
            "Insira um numero: "
        );
        scanf("%d", &menu);

        switch (menu) {
            case 0: printf("Encerrando programa\n"); break;
            case 1: 
                grafo = criar_grafo();
                carregar(grafo);
            break;
            case 2: 
                if (!grafo) {printf("Grafo inexixtente!\n"); break;}
                imprimir(grafo); 
            break;
            case 3: 
                printf("Insira o vertice: ");
                scanf("%d", &vertice);
                if (!grafo) {printf("Grafo inexixtente!\n"); break;}
                dfs(grafo, vertice);
            break;
            case 4:
                if (!grafo) {printf("Grafo inexixtente!\n"); break;}
                printf("Insira o vertice: ");
                scanf("%d", &vertice);
                bfs(grafo, vertice);
            break;
            default: printf("Opcao invalida\n"); break;
        }
    } while (menu);
    return 0;
}