#include <stdio.h>
#include <stdlib.h>
#include "nodeGit.h"

Node *inserir(Node *raiz, int novoValor){
    if(raiz == NULL)
        return criar(novoValor);

    if (novoValor < raiz->valor )
        raiz->esq = inserir(raiz->esq, novoValor);

    if (novoValor > raiz->valor )
        raiz->dir = inserir(raiz->dir, novoValor);

    return raiz;
}

Node *criar(int novoValor){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->valor = novoValor;
    temp->esq = temp->dir = NULL;
    return temp;
}

void inOrder(Node *raiz){
    if (raiz != NULL) {
        inOrder(raiz->esq);
        printf("%d\n", raiz->valor);
        inOrder(raiz->dir);
    }
}

int removerMaior(Node *raiz, int maiorN){
    if (raiz != NULL){
       if(raiz->valor > maiorN){
       		maiorN = raiz->valor;
	   }
       removerMaior (raiz->esq, maiorN);
       removerMaior (raiz->dir, maiorN);

    }
    
    return maiorN;
}

int removerMenor(Node *raiz, int menorN){
    if (raiz != NULL){
       if(raiz->valor < menorN){
       		menorN = raiz->valor;
	   }
       removerMenor (raiz->esq, menorN);
       removerMenor (raiz->dir, menorN);

    }
    
    return menorN;
}

void pre_ordem (Node *raiz) {
    if (raiz != NULL){
       printf ("%d, ", raiz->valor);
       pre_ordem (raiz->esq);
       pre_ordem (raiz->dir);

    }
}

void pos_ordem (Node *raiz){
    if (raiz != NULL){
        pos_ordem (raiz->esq);
        pos_ordem (raiz->dir);
        printf("%d, ", raiz->valor);
    }
}

int min (Node *raiz){
    if( raiz->esq != NULL){
        return min(raiz->esq);
    }
    else{
         return raiz->valor;
    }
}

int max (Node *raiz){
    if (raiz->dir != NULL){
        return max(raiz->dir);
    }
    else{
        return raiz->valor;
    }
}

void imprime_decrescente (Node *raiz){
    if (raiz != NULL){
        printf("%d, ", max(raiz));
        imprime_decrescente(Remover(raiz, max(raiz)));

    }
}

Node* remover (Node *raiz, int v){
    if(raiz == NULL){
        return NULL;
    }
    else{
        if(raiz->valor >v){
            raiz->esq = remover (raiz->esq,v);
        }
        else if (raiz->valor <v){
            raiz->dir = remover (raiz->dir,v);
        }
        else{
            if((raiz->esq == NULL) && (raiz->dir == NULL)){
                free(raiz);
                raiz=NULL;
            }
            else if(raiz->dir == NULL){
                Node *tmp = raiz;
                raiz = raiz -> esq;
                free (tmp);
            }
            else if(raiz->esq == NULL){
                Node *tmp = raiz;
                raiz = raiz -> dir;
                free (tmp);
            }
            else{
                Node *tmp = raiz->esq;
                while(tmp->dir != NULL){
                    tmp=tmp->dir;
                }
                raiz->valor = tmp->valor;
                tmp->valor = v;
                raiz->esq = remover(raiz->esq,v);
            }
        }
    }
    return raiz;
}
