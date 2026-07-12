Atividade Prática 7 - Prof. Julio S. Domingues Jr

**TAD de Pilha (STACK)**

DADOS:
struct musica {
  char titulo[256];
  char artista[256];
  char letra[256];
  int codigo;
  int execucoes;
}
struct nodo_pilha {
  struct nodo_pilha *prox;
  struct musica *info;
}
struct desc_pilha {
  struct nodo_pilha *topo;
  int tamanho;
}

OPERAÇÕES:
– CriaPilha
– PUSH
– POP
– TOP
– EMPTY
– Imprime
