#include "BigNumbers.h"

#include <stdio.h>
#include <stdlib.h>

int size(Lista L){
    int count=0;
    while (L != NULL){
        L = L->prox;
        count++;
    }
    return count;
}

//retorna 1 se a for maior que b, 0 se o contrario, e 2 se for ==
int Maior(BigNumber a, BigNumber b){
    int sizeA = size(a.number), sizeB = size(b.number);
    if(sizeA>sizeB)
        return 1;
    else if(sizeA<sizeB)
        return 0;
    else{
        a.number = inverte(NULL, a.number);
        b.number = inverte(NULL, b.number);

        Lista aux1 = a.number;
        Lista aux2 = b.number;
        int retorno = 2;

        while (aux1->prox != NULL){
            if(aux1->num > aux2->num){
                retorno = 1;
                break;
            }
            if(aux1->num < aux2->num){
                retorno = 0;
                break;
            }
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
        a.number = inverte(NULL, a.number);
        b.number = inverte(NULL, b.number);

        return retorno;
    }
}

Lista FormatNum(Lista a){
    Lista atual = a, aux;
    while (1){
        if(atual != 0)
            return atual;
        aux = atual;
        atual = atual->prox;
        free(aux);
    }
}

//sempre passar A como o maior numero, e o resultado como NULL
Lista Sub(Lista a, Lista b, Lista resultado){

    if(a==NULL && b==NULL)
        return resultado;
    else if(b==NULL){
        Lista novo_no = criarNo(resultado, a->num);
        return Sub(a->prox, b, novo_no);
    }
    else{
        int temp = a->num - b->num;
        Lista novo_no;
        if(temp < 0){
            (a->prox)->num--;
            novo_no = criarNo(resultado, temp+10);
        }
        else
            novo_no = criarNo(resultado, temp); 

        return Sub(a->prox, b->prox, novo_no);
    }
}

BigNumber ChamarSub(BigNumber a, BigNumber b){

    BigNumber result;
    result.number = criar_lista();

    int cond = Maior(a,b);

    if(cond == 2){
        result.sinal = 0;
        Lista novo_no = criarNo(result.number, 0);
        result.number = novo_no;
    }
    else if(cond == 1){
        result.sinal = a.sinal;
        result.number = Sub(a.number, b.number, result.number);
    }
    else{
        result.sinal = b.sinal;
        result.number = Sub(b.number, a.number, result.number);
    }

    destruir_lista(a.number);
    destruir_lista(b.number);

    result.number = FormatNumber(result.number);
    return result;
}
