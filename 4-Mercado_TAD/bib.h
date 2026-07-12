#ifndef BIB_h
#define BIB_h

// STRUCTS
typedef enum{
    hortifruti=1, acougue, padaria, mercearia, higiene, limpeza, utensilios
} Setores;

typedef struct {
    char nome[15];
    Setores setor;
    int quantidade;
    float preco;
} Produtos;

//FUNCTIONS
void limpa_buffer();
void mostrar_setor();
char *converter_setor(Produtos produto[], int s);
void cadastrar_produto(Produtos produto[], int tamanhoEstoque, int *nProdutos);
void mostrar_produto(Produtos produto[], int i);
void buscar_codigo(Produtos produto[], int nProdutos);
void buscar_nome(Produtos produto[], int nProdutos);
void buscar_setor(Produtos produto[], int nProdutos);
int calcular_balanco(Produtos produto[], int nProdutos);
int calcular_valor(Produtos produto[], int nProdutos);
void calcular_estoque(Produtos produto[], int nProdutos);
void realizar_venda(Produtos produto[], int nProdutos);
void carregar_arquivo(Produtos produto[], int *nProdutos);
void gerar_arquivo(Produtos produto[], int nProdutos);

#endif