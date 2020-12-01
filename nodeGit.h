#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct node {
    struct node *esq;
    int valor;
    struct node *dir;
} Node;

Node *criar(int valor);

Node *inserir(Node *raiz, int novoValor);

void inOrder(Node *raiz);

void buscar(int valorDesejado);

void pre_ordem (Node *raiz);

void pos_ordem (Node *raiz);

//int buscar (Node *raiz, int v);

int removerMaior(Node *raiz, int maiorN);

int removerMenor(Node *raiz, int maiorN);

void imprime_decrescente (Node *raiz);

Node *remover (Node *raiz, int v);

#endif // NODE_H_INCLUDED
