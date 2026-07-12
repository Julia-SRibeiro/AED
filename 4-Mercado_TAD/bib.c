#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

void limpa_buffer(){int c; while((c=getchar())!='\n'&&c!=EOF);}

void mostrar_setor() {
    printf(
        "=== SETORES ===\n"
        "1- Hortifruti\n"
        "2- Acougue\n"
        "3- Padaria\n"
        "4- Mercearia\n"
        "5- Higiene\n"
        "6- Limpeza\n"
        "7- Utensilios\n"
    );
}
char *converter_setor(Produtos produto[], int s) {
    char *nomes[] = {"Invalido", "Hortifruti", "Acougue", "Padaria", "Mercearia", "Higiene", "Limpeza", "Utensilios"};
    return (s >= 1 && s <= 7) ? nomes[s] : nomes[0];
}
void cadastrar_produto(Produtos produto[], int tamanhoEstoque, int *nProdutos) {
    if ((*nProdutos) >= tamanhoEstoque) {
        printf("Limite de produtos atingido!\n");
        return;
    }
    int i = (*nProdutos), s;

    printf("Produto %d\n", i+1);
    printf("Nome do produto: ");
    scanf(" %14[^\n]", produto[i].nome);
    limpa_buffer();

    do {
        mostrar_setor();
        printf("Insira um numero: ");
        scanf("%d", &s);
        limpa_buffer();
    } while(s < 1 || s > 7);
    
    produto[i].setor = s; // Int

    printf("Quantidade: ");
    scanf("%d", &produto[i].quantidade);
    limpa_buffer();

    printf("Preco unitario: ");
    scanf("%f", &produto[i].preco);
    limpa_buffer();
    (*nProdutos)++;
    printf("\n");
}

void mostrar_produto(Produtos produto[], int i) {
    printf(
        "\n-> Produto %d\n"
        "Nome: %s\n"
        "Setor: %s\n"
        "Quantidade: %d\n"
        "Preco unitario: %.2f\n",
        i+1, 
        produto[i].nome,
        converter_setor(produto, produto[i].setor),
        produto[i].quantidade,
        produto[i].preco
    );
}
void buscar_codigo(Produtos produto[], int nProdutos) {
    int codigo;

    printf("Insira o codigo do produto: (1-%d): ", nProdutos);
    scanf("%d", &codigo);
    limpa_buffer();
    if(codigo < 1 || codigo > nProdutos) {
        printf("Codigo invalido!\n");
        return;
    }
    mostrar_produto(produto, codigo-1);
}
void buscar_nome(Produtos produto[], int nProdutos) {
    int check=0;
    char n[15];
    
    printf("Insira o nome do produto: ");
    scanf(" %14[^\n]", n);
    limpa_buffer();

    for(int i=0; i<nProdutos; i++) {
        if((strcasecmp(produto[i].nome, n)) == 0) {
            mostrar_produto(produto, i);
            check ++;
        }
    }
    if(check==0) {
        printf("Nenhum produto encontrado!\n");
    }
}
void buscar_setor(Produtos produto[], int nProdutos) {
    int n, check=0;
    do {
        mostrar_setor();
        printf("Insira um numero: ");
        scanf("%i", &n);
        limpa_buffer();
    } while(n < 1 || n > 7);

    for(int i=0; i<nProdutos; i++) {
        if(produto[i].setor == n) {
            mostrar_produto(produto, i);
            check ++;
        }
    }
    if(check==0) {
        printf("Nenhum produto encontrado!\n");
    }
}

int calcular_balanco(Produtos produto[], int nProdutos) {
    if(nProdutos == 0) {
        return 0;
    }
    return produto[nProdutos-1].quantidade + calcular_balanco(produto, nProdutos-1);
}
int calcular_valor(Produtos produto[], int nProdutos) {
    if(nProdutos == 0) {
        return 0;
    }
    int valor = produto[nProdutos-1].quantidade * produto[nProdutos-1].preco;
    return valor + calcular_valor(produto, nProdutos-1);
}
void calcular_estoque(Produtos produto[], int nProdutos) {
    int balanco = calcular_balanco(produto, nProdutos);
    printf("QUANTIDADE TOTAL DE PRODUTOS: %d\n", balanco);
    float valor = calcular_valor(produto, nProdutos);
    printf("VALOR TOTAL: %.2f\n", valor);
}

void realizar_venda(Produtos produto[], int nProdutos) {
    int codigo, venda;

    printf("Insira o codigo do produto: (1-%d): ", nProdutos);
    scanf("%d", &codigo);
    limpa_buffer();
    if(codigo < 1 || codigo > nProdutos) {
        printf("Codigo invalido!\n");
        return;
    }

    int i = codigo-1;
    printf("Produto: %s\n", produto[i].nome);
    printf("Quantidade em estoque: %d\n", produto[i].quantidade);

    printf("Quantidade para venda: ");
    scanf("%d", &venda);
    limpa_buffer();
    if(venda > produto[i].quantidade) {
        printf("Estoque insuficiente!\n");
        return;
    }

    produto[i].quantidade -= venda;
    printf("Venda realizada!\n");
}

void carregar_arquivo(Produtos produto[], int *nProdutos) {
    FILE *arquivo = fopen("estoque.txt", "r");
    if(arquivo == NULL) {
        printf("Erro no arquivo de entrada!");
        exit;
    }

    int tamanho;
    fscanf(arquivo, "%d\n", &tamanho);
    for(int i=0;  i<tamanho; i++) {
        fscanf(
            arquivo,"%[^\n]\n%d\n%d\n%f\n",
            produto[i].nome,
            (int*)&produto[i].setor,
            &produto[i].quantidade,
            &produto[i].preco
        );
    }
    *nProdutos = tamanho;
    fclose(arquivo);
    printf("Arquivo 'estoque.txt' carregado com sucesso!\n");
}
void gerar_arquivo(Produtos produto[], int nProdutos) {
    FILE *arquivo = fopen("estoque.txt", "w");
    if(arquivo == NULL) {
        printf("Erro no arquivo de saída!");
        exit;
    }

    fprintf(arquivo, "%d\n", nProdutos);
    for(int i=0; i < nProdutos; i++) {
        fprintf(
            arquivo, "%s\n%d\n%d\n%.2f\n", 
            produto[i].nome,
            produto[i].setor,
            produto[i].quantidade,
            produto[i].preco
        );
    }
    fclose(arquivo);
    printf("Arquivo 'estoque.txt' salvo com sucesso!.\n");
}