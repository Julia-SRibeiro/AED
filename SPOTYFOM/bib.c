#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "bib.h"

// CRIACAO DAS ESTRUTURAS
TipoLista* criar_lista() {
    TipoLista *lista = (TipoLista*) malloc(sizeof(TipoLista));
    if (!lista) {printf("Erro de memoria.\n"); return NULL;}
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}
void carregar_dados(TipoLista *lista) {
    FILE *arquivo = fopen("musicas.txt", "r");
    if(!arquivo) {printf("Erro ao carrregar o acervo!\n"); return;}

    int tamanho;

    fscanf(arquivo, "%d\n", &tamanho);
    for(int i=0; i < tamanho; i++) { 
        TipoItem *novoItem = (TipoItem*) malloc(sizeof(TipoItem));
        TipoDado *novoDado = (TipoDado*) malloc(sizeof(TipoDado));
        if (!novoItem || !novoDado) {printf("Erro de memoria!\n"); return;}

        // Le os dados do arquivo
        fscanf(
            arquivo,
            "%[^;];%d;%[^;];%[^;];%*[^\n]\n",
            novoDado->artista,
            &novoDado->codigo,
            novoDado->titulo,
            novoDado->letra
        );
        novoDado->execucoes = 0;

        // Insere os dados lidos
        novoItem->dados = novoDado;
        if (!lista->tamanho) {lista->inicio = novoItem;} // Primeira musica, novoItem eh inicio
        else {lista->fim->prox = novoItem;}// Demais musicas, Ultimo item aponta para o novo item
        novoItem->prox = NULL;
        lista->fim = novoItem; // Novo item eh ultimo item
        lista->tamanho++;
    }
    fclose(arquivo);
    printf("Acervo carregado!\n");
}

void criar_playlist_aleatoria(TipoLista *lista, TipoLista *fila) {
    int n;
    printf("Numero de musicas: ");
    scanf("%d", &n);
    
    printf("\nMusica(s) inserida(s):\n");
    // Aleatoriza n elementos
    for(int i=0; i<n; i++) {
        TipoItem *musica = lista->inicio;
        int aleatorio = rand() % lista->tamanho; // Sorteia um índice de 0 até tamanho da lista
        for(int j = 0; j < aleatorio; j++) {musica = musica->prox;} // Percorre a lista até chegar na música sorteada

        TipoItem *novoItem = (TipoItem*) malloc(sizeof(TipoItem));
        if (!novoItem) {printf("Erro de memoria!\n"); return;}

        // Enfileirar
        novoItem->dados = musica->dados;
        if(!fila->tamanho) {fila->inicio = novoItem;} // Primeira musica
        else {fila->fim->prox = novoItem;} // Demais musicas, ultimo aponta para novo item
        novoItem->prox = NULL;
        fila->fim = novoItem; // novo item vira o ultimo
        fila->tamanho++;
        imprimir(musica->dados);
        
    }
}
void criar_playlist_pessoal(TipoLista *lista, TipoLista *pilha) {
    TipoItem *musica = NULL;
    int menu;
    do {
        printf(
            "\n"
            "<-- BUSCAR MUSICA -->\n"
            "0- Voltar\n"
            "1- Por código\n"
            "2- Por titulo\n"
            "<------------------->\n"
            "Escolha uma opcao: "
        );
        scanf("%d", &menu);
        printf("\n");
        
        switch(menu) {
            case 0: return;
            case 1: 
                musica = buscar_codigo(lista);
            break;
            case 2: 
                musica = buscar_titulo(lista); 
            break;
            default: printf("Opcao invalida!"); continue;
        }

        if (musica == NULL) {continue;}
        
        TipoItem *novoItem  = (TipoItem*)malloc(sizeof(TipoItem));
        if (!novoItem) { printf("Erro de memoria!\n"); return; }
        
        // Empilha
        novoItem->dados = musica->dados;
        novoItem->prox = pilha->inicio;  // Aponta para antigo topo
        pilha->inicio = novoItem; // Topo eh o novoItem
        pilha->tamanho++;
        printf("Musica inserida!\n");
    } while(menu);
}
void menu_criar_playlist(TipoLista *lista, TipoLista *fila, TipoLista *pilha) {
    int menu;
    do {
        printf(
            "\n"
            "<-- CRIAR PLAYLIST -->\n"
            "0- Voltar\n"
            "1- Aleatoria\n"
            "2- Pessoal\n"
            "<-------------------->\n"
            "Escolha uma opcao: "
        );
        scanf("%d", &menu);
        printf("\n");

        switch(menu) {
            case 0: break;
            case 1: criar_playlist_aleatoria(lista, fila); break;
            case 2: criar_playlist_pessoal(lista, pilha); break;
            default: printf("Opcao invalida!"); break;
        }
    } while (menu);
}

// EXECUCAO DAS PLAYLISTS
void executar_playlist_aleatoria(TipoLista *fila) {
    TipoItem  *musica_playlist = fila->inicio;

    printf("Musicas a serem tocadas: %d\n", fila->tamanho);
    while (musica_playlist) {
        musica_playlist->dados->execucoes++; // Incrementa execucoes no acervo
        printf("Tocando: "); imprimir(musica_playlist->dados); // Imprime musica

        // Desenfileira
        fila->inicio = fila->inicio->prox; // Proximo da fila vira o primeiro
        free(musica_playlist); // Libera o nó da memória
        fila->tamanho--;

        musica_playlist = fila->inicio;
    }
    fila->fim = NULL;
}
void executar_playlist_pessoal(TipoLista *pilha) {
    TipoItem  *musica_playlist = pilha->inicio;

    printf("Musicas a serem tocadas: %d\n", pilha->tamanho);
    while (musica_playlist) {
        musica_playlist->dados->execucoes++; // Incrementa execucoes no acervo
        printf("Tocando: "); imprimir(musica_playlist->dados); // Imprime musica

        // Desempilha
        pilha->inicio = pilha->inicio->prox; // Proximo da fila vira o primeiro
        free(musica_playlist); // Libera o nó da memória
        pilha->tamanho--;

        musica_playlist = pilha->inicio;
    }
    pilha->fim = NULL;
}
void menu_executar(TipoLista *fila, TipoLista *pilha) {
    int menu;
    do {
        printf(
            "\n"
            "<-- EXECUTAR PLAYLIST -->\n"
            "0- Voltar\n"
            "1- Aleatoria\n"
            "2- Pessoal\n"
            "<----------------------->\n"
            "Escolha uma opcao: "
        );
        scanf("%d", &menu);
        printf("\n");

        switch(menu) {
            case 0: break;
            case 1: executar_playlist_aleatoria(fila); break;
            case 2: executar_playlist_pessoal(pilha); break;
            default: printf("Opcao invalida!"); break;
        }
    } while (menu);
}

// IMPRESSAO DE MUSICAS
void imprimir(TipoDado *dado) {
    printf(
        "Titulo: %s | "
        "Artista: %s | "
        "Letra: %s | "
        "Codigo: %d | "
        "Execucoes: %d\n",
        dado->titulo,
        dado->artista,
        dado->letra,
        dado->codigo,
        dado->execucoes
    );
}
void menu_imprimir(TipoLista *lista, TipoLista *fila, TipoLista *pilha){
    TipoItem *Musica;
    int menu;
    do {
        printf(
            "\n"
            "<---- IMPRIMIR MUSICAS ---->\n"
            "0- Voltar\n"
            "1- Acervo (todas as musicas)\n"
            "2- Playlist aleatoria\n"
            "3- Playlist pessoal\n"
            "<-------------------------->\n"
            "Escolha uma opcao: "
        );
        scanf("%d", &menu);
        printf("\n");

        switch(menu) {
            case 0: break;
            case 1:
                Musica = lista->inicio;
                printf("Numero de musicas: %d\n",lista->tamanho);
                for (int i=0; i < lista->tamanho; i++) {
                    printf("%d. ", i+1);
                    imprimir(Musica->dados);
                    Musica = Musica->prox;
                }
            break;
            case 2:
                Musica = fila->inicio;
                printf("Numero de musicas: %d\n",fila->tamanho);
                for (int i=0; i < fila->tamanho; i++) {
                    printf("%d. ", i+1);
                    imprimir(Musica->dados);
                    Musica = Musica->prox;
                }
            break;
            case 3:
                Musica = pilha->inicio;
                printf("Numero de musicas: %d\n",pilha->tamanho);
                for (int i=0; i < pilha->tamanho; i++) {
                    printf("%d. ", i+1);
                    imprimir(Musica->dados);
                    Musica = Musica->prox;
                }
            break;
            default: printf("Opcao invalida!"); break;
        }
    } while (menu);
}

// BUSCA DE MUSICAS
TipoItem* buscar_codigo(TipoLista *lista) {
    TipoItem *musica = lista->inicio;
    int codigo;
    printf("Insira o codigo da musica: ");
    scanf ("%d", &codigo);

    while (musica) {
        if(musica->dados->codigo == codigo) {
            return musica;
        }
        musica = musica->prox;
    }
    printf("Musica nao encontrada!\n");
    return NULL;
}
TipoItem* buscar_titulo(TipoLista *lista) {
    TipoItem *musica = lista->inicio;
    char titulo[256];
    printf("Insira o titulo da musica: ");
    scanf (" %255[^\n]", titulo);

    while (musica) {
        if((strcasecmp(musica->dados->titulo, titulo) == 0)) {
            return musica;
        }
        musica = musica->prox;
    }
    printf("Musica nao encontrada!\n");
    return NULL;
}
void buscar_artista(TipoLista *lista) {
    TipoItem *musica = lista->inicio;
    int valida=0;
    char artista[256];
    printf("Insira o artista da musica: ");
    scanf (" %255[^\n]", artista);

    while (musica) {
        if((strcasecmp(musica->dados->artista, artista) == 0)) {
            imprimir(musica->dados);
            valida++;
        }
        musica = musica->prox;
    }
    if(!valida) {printf("Artista nao encontrado!\n");}
    else {printf("\nMusicas encontradas: %d\n", valida);}
}
void menu_buscar(TipoLista *lista) {
    TipoItem *musica = NULL;
    int menu;
    do {
        printf(
            "\n"
            "<-- BUSCAR MUSICA -->\n"
            "0- Voltar\n"
            "1- Código\n"
            "2- Titulo\n"
            "3- Artista\n"
            "<------------------->\n"
            "Escolha uma opcao: "
        );
        scanf("%d", &menu);
        printf("\n");

        switch(menu) {
            case 0: break;
            case 1:
                musica = buscar_codigo(lista); 
                if(musica) {imprimir(musica->dados);}
            break;
            case 2: 
                musica = buscar_titulo(lista); 
                if(musica) {imprimir(musica->dados);}
            break;
            case 3: 
                buscar_artista(lista);
            break;
            default: printf("Opcao invalida!"); break;
        }
    } while (menu);
}

// GERACAO DE RELATORIOS
void gerar_relatorio(TipoLista *lista) {
    FILE *arquivo = fopen("relatorio.txt", "w");
    if(!arquivo) {printf("Erro ao gerar relatorio!\n"); return;}

    TipoItem *musica = lista->inicio;
    fprintf(arquivo, "%d\n", lista->tamanho);
    while(musica) {
        fprintf(
            arquivo,
            "%s;%d;%s;%s;%d\n",
            musica->dados->artista,
            musica->dados->codigo,
            musica->dados->titulo,
            musica->dados->letra,
            musica->dados->execucoes
        );
        musica = musica->prox;
    }
    fclose(arquivo);
    printf("Relatorio .txt gerado!\n");
}
void menu_relatorio(TipoLista *lista, TipoLista *fila, TipoLista *pilha) {
    int menu;
    do {
        printf(
            "\n"
            "<-- ARQUIVO DE RELATORIO -->\n"
            "0- Voltar\n"
            "1- Acervo\n"
            "2- Playlist Aleatoria\n"
            "3- Playlist Pessoal\n"
            "<-------------------------->\n"
            "Escolha uma opcao: "
        );
        scanf("%d", &menu);
        printf("\n");

        switch(menu) {
            case 0: break;
            case 1: gerar_relatorio(lista); break;
            case 2: gerar_relatorio(fila); break;
            case 3: gerar_relatorio(pilha); break;
            default: printf("Opcao invalida!"); break;
        }
    } while (menu);
}

void liberar_memoria(TipoLista *lista, TipoLista *fila, TipoLista *pilha) {
TipoItem *atual, *proximo;
    atual = lista->inicio;      
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual->dados); // Libera o conteúdo da música
        free(atual); // Libera o nó da lista
        atual = proximo;
    }
    free(lista);
}