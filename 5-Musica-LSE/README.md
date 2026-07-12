Atividade Prática 5 - Prof. Julio S. Domingues Jr

**TAD de Lista Simplesmente Encadeada (LSE)**
DADOS:
struct musica {
  char titulo[256];
  char artista[256];
  char letra[256];
  int codigo;
  int execucoes;
}
struct desc_LSE{
  struct nodo_LSE *LSE;
  int tamanho;
}

OPERAÇÕES:
– Cria Lista
– Insere
– Remove
– Consulta
– Imprime
