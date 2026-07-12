Atividade Prática 8 - Prof. Julio S. Domingues Jr

**Implemente uma TAD de Fila (Queue)**

DADOS:
struct musica{
  char titulo[256];
  char artista[256];
  char letra[256];
  int codigo;
  int execucoes;
}
struct nodo_queue{
  struct nodo_queue *prox;
  struct musica *info;
}
struct desc_queue{
  struct nodo_queue *head;
  struct nodo_queue *tail;
  int tamanho;
}

OPERAÇÕES:
– CreateQueue
– DELETE(Fila)
– EMPTY (Fila)
– ENQUEUE (x, Fila)
– DEQUEUE (Fila, x)
– LENGHT (Fila)
– ShowQueue
