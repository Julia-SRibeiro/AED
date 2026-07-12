#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

// GRAFO
TipoGrafo* criar_grafo() {
    TipoGrafo *grafo = (TipoGrafo*)malloc(sizeof(TipoGrafo));
    grafo->inicio = NULL;
    grafo->max_arestas = 0;
    grafo->max_vertices = 0;
    return grafo;
}
TipoItem* criar_item(int vertice) {
    TipoItem *item = (TipoItem*)malloc(sizeof(TipoItem));
    item->chave = vertice;
    item->adjacencias = NULL;
    item->prox = NULL;
    return item;
}
TipoDado* criar_dado(int origem, int destino, int peso) {
    TipoDado *dado = (TipoDado*)malloc(sizeof(TipoDado));
    dado->origem = origem;
    dado->destino = destino;
    dado->peso = peso;
    dado->prox = NULL;
    return dado;
}

TipoGrafo* inserir_vertice(TipoGrafo *grafo) {
    for (int i = 1; i <= grafo->max_vertices; i++) {
        TipoItem *novoVertice = criar_item(i); // Cria vertice
        // Insere vertice no inicio (pilha)
        novoVertice->prox = grafo->inicio;
        grafo->inicio = novoVertice;
    }
    return grafo;
}
TipoGrafo* inserir_aresta(TipoGrafo *grafo, int origem, int destino, int peso) {
    TipoItem *atual = grafo->inicio;
    while(atual && atual->chave != origem) {atual = atual->prox;} // Procura vertice
    if (atual) {
        TipoDado *novaAresta = criar_dado(origem, destino, peso); // Cria aresta
        // Insere aresta no inicio (pilha)
        novaAresta->prox = atual->adjacencias;
        atual->adjacencias = novaAresta;
        grafo->max_arestas++;
    }
    return grafo;
}
void carregar(TipoGrafo* grafo) {
    char arquivo[50];
    printf("Insira o nome do arquivo .txt: ");
    scanf(" %49[^\n]", arquivo);
    FILE *file = fopen(arquivo,"r");
    if (!file) {printf("Erro ao abrir o arquivo!\n"); return;}

    int origem, destino, peso;
	fscanf(file,"%d", &grafo->max_vertices);
    grafo = inserir_vertice(grafo); // Vertices
    while (fscanf(file, "%d %d %d", &origem, &destino, &peso) == 3) { 
        grafo = inserir_aresta(grafo, origem, destino, peso); // Arestas
    }
    fclose(file);
    printf("Grafo carregado!\n");
}
void imprimir(TipoGrafo* grafo) {
    printf(
        "\n"
        "Quantidade de vertices: %d\n"
        "Quantidade de arestas: %d\n"
        "\n",
        grafo->max_vertices,
        grafo->max_arestas
    );
    TipoItem *vertice = grafo->inicio;
    while (vertice) {
        TipoDado *aresta = vertice->adjacencias;
        while (aresta) {
            printf(
                "Origem: %d | Destino: %d | Peso: %d\n",
                aresta->origem,
                aresta->destino,
                aresta->peso
            );
            aresta = aresta->prox;
        }
        vertice = vertice->prox;
    }    
}

// DFS
void dfs_recursiva(TipoGrafo *grafo, int v_atual, int *visitado) {
    visitado[v_atual] = 1; // Marca o vértice atual como visitado

    // Acha o vértice na lista
    TipoItem *aux = grafo->inicio;
    while (aux && aux->chave != v_atual) aux = aux->prox;

    // Percorre as arestas
    if (aux) {
        for (TipoDado *ar = aux->adjacencias; ar; ar = ar->prox) {
            if (!visitado[ar->destino]) {
                printf("[%d -> %d] ", ar->origem, ar->destino);
                dfs_recursiva(grafo, ar->destino, visitado); 
            }
        }
    }
}
void dfs(TipoGrafo *grafo, int inicial) {
    int *visitado = calloc(grafo->max_vertices + 1, sizeof(int));
    printf("\nDFS (Caminho): ");
    dfs_recursiva(grafo, inicial, visitado);
    printf("\n");
    free(visitado);
}

// BFS
void bfs(TipoGrafo *grafo, int inicial) {
    int max = grafo->max_vertices + 1;
    int *visitado = calloc(max, sizeof(int));
    int *fila = malloc(max * sizeof(int));
    int ini = 0, fim = 0;

    fila[fim++] = inicial; 
    visitado[inicial] = 1;

    printf("\nBFS (Caminho): ");

    while (ini < fim) {
        int v_atual = fila[ini++]; // Retira da fila
        
        // Acha o vértice na lista
        TipoItem *aux = grafo->inicio;
        while (aux && aux->chave != v_atual) aux = aux->prox;
        
        // Percorre as arestas
        if (aux) {
            for (TipoDado *ar = aux->adjacencias; ar; ar = ar->prox) {
                if (!visitado[ar->destino]) {
                    printf("[%d -> %d] ", ar->origem, ar->destino);
                    visitado[ar->destino] = 1;
                    fila[fim++] = ar->destino;
                }
            }
        }
    }
    printf("\n");
    free(visitado); 
    free(fila);
}