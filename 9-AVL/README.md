Atividade Prática 9 - Prof. Julio S. Domingues Jr

**TAD de Árvore AVL**

DADOS:
struct nodo {
  struct nodo *pai;
  int chave;
  strcut nodo *esq;
  struct nodo *dir;
  int fator; //opcional
  int balanco; //opcional
}
struct desc_avl {
  struct nodo *raiz;
  int tamanho;
}

OPERAÇÕES:
– Create AVL
– REMOVE(Avl, chave)
– INSERT (Avl, chave)
– Percursos:
  • Inorder
  • Preorder
  • Postorder
