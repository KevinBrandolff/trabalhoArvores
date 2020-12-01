#include <stdio.h>
#include <stdlib.h>
#include "nodeGit.h"

int main()
{
    Node *raiz = NULL;
    raiz = inserir(raiz, 25);
    inserir(raiz, 22);
    inserir(raiz, 40);
    inserir(raiz, 30);
    inserir(raiz, 45);
    inserir(raiz, 27);
    inserir(raiz, 20);

    inOrder(raiz);
    
    
    int maiorN = 0;
    int menorN = 0;
    
    pre_ordem (raiz);
    pos_ordem (raiz);
    
    imprime_decrescente(raiz);
    maiorN = removerMaior(raiz, maiorN);
	remover(raiz, maiorN);
	imprime_decrescente(raiz);
	menorN = removerMenor(raiz, menorN);
	remover(raiz, menorN);
    

    return 0;
}
