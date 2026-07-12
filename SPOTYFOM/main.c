/*
SPOTYFOM - Aplicativo de execução de músicas
Julia Soares Ribeiro - juliasr.aluno@unipampa.edu.br
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bib.h"

int main() {
    srand(time(NULL));
    TipoLista *Lista = criar_lista();
    TipoLista *Pilha = criar_lista();
    TipoLista *Fila = criar_lista();
    int menu;

    carregar_dados(Lista);

    do {
        printf(
            "\n"
            "====== MENU SPOTYFOM ======\n"
            "1- Criar playlist\n"
            "2- Executar playlist\n"
            "3- Buscar musica no acervo\n"
            "4- Imprimir\n"
            "5- Relatório\n"
            "0- Sair\n"
            "===========================\n"
            "Escolha uma opcao: "
        );
        scanf("%d", &menu);
        
        switch (menu) {
            case 0: printf("Encerrando programa.\n"); break;
            case 1: menu_criar_playlist(Lista, Fila, Pilha); break;
            case 2: menu_executar(Fila, Pilha); break;
            case 3: menu_buscar(Lista); break;
            case 4: menu_imprimir(Lista, Fila, Pilha); break;
            case 5: menu_relatorio(Lista, Fila, Pilha); break;
            default: printf("Opcao invalida!"); break;
        }
    } while(menu);
    liberar_memoria(Lista, Fila, Pilha);
    return 0;
}