/*
Atividade 5 - Mercado TAD
Julia Soares Ribeiro - juliasr.aluno@unipampa.edu.br
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"


int main() {
    int menu, tamanhoEstoque, nProdutos=0;

    printf("Insira o tamanho do estoque: ");
    scanf("%d", &tamanhoEstoque);
    limpa_buffer();
    Produtos *produto = (Produtos*) malloc(sizeof(Produtos) * tamanhoEstoque);
    if (produto == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }
    
    do {
        printf(
            "\n============= MENU ==============\n"
            "1- Carregar produtos de arquivo\n"
            "2- Adicionar produto\n"
            "3- Mostrar produtos\n"
            "4- Buscar produto por codigo\n"
            "5- Buscar produtos por nome\n"
            "6- Buscar produto por setor\n"
            "7- Calcular total em estoque\n"
            "8- Realizar venda\n"
            "9- Gerar arquivo de produtos\n"
            "0- Sair\n"
            "==================================\n"
            "Escolha uma opcao: "
        );
        scanf("%d", &menu);
        limpa_buffer();
        printf("\n");
        
        switch(menu) {
            case 0:
                free(produto);
                printf("Encerrando programa\n");
            break;
            case 1:
                carregar_arquivo(produto, &nProdutos);
            break;
            case 2:
                cadastrar_produto(produto, tamanhoEstoque, &nProdutos);
            break;
            case 3:
                printf("QUANTIDADE DE PRODUTOS: %d\n", nProdutos);
                for(int i=0; i<nProdutos; i++) {
                    mostrar_produto(produto, i);
                }
            break;
            case 4:
                buscar_codigo(produto, nProdutos);
            break;
            case 5:
                buscar_nome(produto, nProdutos);
            break;
            case 6:
                buscar_setor(produto, nProdutos);
            break;
            case 7:
                calcular_estoque(produto, nProdutos);
                break;
            case 8:
                realizar_venda(produto, nProdutos);
            break;
            case 9:
                gerar_arquivo(produto, nProdutos);
            break;
            default: printf("Numero invalido!\n");
        }
    } while (menu != 0);
    return 0;
}