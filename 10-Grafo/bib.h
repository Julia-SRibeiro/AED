#ifndef BIB_H
#define BIB_H

// STRUCTs
typedef struct tipoDado {
    int origem, destino, peso;
    struct tipoDado *prox;
} TipoDado;
typedef struct tipoItem {
    int chave;
    TipoDado *adjacencias;
    struct tipoItem *prox;
} TipoItem;
typedef struct {
    int max_vertices;
	int max_arestas;
    TipoItem *inicio;
} TipoGrafo;

// FUNCTIONs
TipoGrafo* criar_grafo();
TipoItem* criar_item(int vertice);
TipoDado* criar_dado(int origem, int destino, int peso);
TipoGrafo* inserir_vertice(TipoGrafo *grafo);
TipoGrafo* inserir_aresta(TipoGrafo *grafo, int origem, int destino, int peso);
void carregar(TipoGrafo* grafo);
void imprimir(TipoGrafo* grafo);
void dfs(TipoGrafo *grafo, int inicial);
void dfs_recursiva(TipoGrafo *grafo, int v_atual, int *visitado);
void bfs(TipoGrafo *grafo, int inicial);

#endif