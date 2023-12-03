#include <stdlib.h>
#include <stdio.h>
#include "BigNumbers.h"

Lista criar_lista () {
    return NULL;
}

void destruir_lista(Lista L){
    if(L != NULL){
        Lista atual = L;
        Lista next = atual->prox;

        while (atual != NULL){
            next = atual->prox;
            free(atual);
            atual = next;
        }
        free(next);
        free(atual);
    }
    else
        free(L);
}
Lista criarNo(Lista L, int val){

    Lista novo_no = malloc(sizeof(struct no));
    novo_no->num = val;
    novo_no->prox = L;
    return novo_no;
}

Lista inverte(Lista anterior, Lista L){

    if(L->prox == NULL){
        free(L->prox);
        L->prox = anterior;
        return L;
    }
    else{
        Lista finalVal = inverte(L, L->prox);
        L->prox = anterior;
        return finalVal;
    }    
}