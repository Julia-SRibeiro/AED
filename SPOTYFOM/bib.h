#ifndef BIB_H
#define BIB_H

// STRUCTs
typedef struct {
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes; //numero de execuções da musica em playlists
} TipoDado;
typedef struct tipoItem {
    TipoDado *dados;
    struct tipoItem *prox;
} TipoItem;
typedef struct tipoLista {
    TipoItem *inicio, *fim;
    int tamanho;
} TipoLista;

//FUNCTIONs
TipoLista *criar_lista(void);
void carregar_dados(TipoLista *lista);
void menu_criar_playlist(TipoLista *lista, TipoLista *fila, TipoLista *pilha);
void criar_playlist_aleatoria(TipoLista *lista, TipoLista *fila);
void criar_playlist_pessoal(TipoLista *lista, TipoLista *pilha);
void menu_executar(TipoLista *fila, TipoLista *pilha);
void executar_playlist_aleatoria(TipoLista *fila);
void executar_playlist_pessoal(TipoLista *pilha);
void menu_buscar(TipoLista *lista);
TipoItem* buscar_codigo(TipoLista *lista);
TipoItem* buscar_titulo(TipoLista *lista);
void buscar_artista(TipoLista *lista);
void menu_imprimir(TipoLista *lista, TipoLista *fila, TipoLista *pilha);
void imprimir(TipoDado *dado);
void menu_relatorio(TipoLista *lista, TipoLista *fila, TipoLista *pilha);
void gerar_relatorio(TipoLista *lista);
void liberar_memoria(TipoLista *lista, TipoLista *fila, TipoLista *pilha);

#endif