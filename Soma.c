#include "BigNumbers.h"

#include <stdio.h>
#include <stdlib.h>

Lista soma(Lista a, Lista b, Lista resultado, int acumulado){

    if(a==NULL && b==NULL){
        if(acumulado == 0)
            return resultado;

        Lista novo_no = criarNo(resultado, acumulado);
        return novo_no;
    }

    else if(a==NULL){
        int temp = b->num + acumulado;
        Lista novo_no = criarNo(resultado, temp%10);
        return soma(a, b->prox, novo_no, temp/10);
    }

    else if(b==NULL){
        int temp = a->num + acumulado;
        Lista novo_no = criarNo(resultado, temp%10);
        return soma(a->prox, b, novo_no, temp/10);
    }

    else{
        int temp = a->num + b->num + acumulado;
        Lista novo_no = criarNo(resultado, temp%10);

        return soma(a->prox, b->prox, novo_no, temp/10);        
    }
}

BigNumber ChamarSoma(BigNumber a, BigNumber b){

    BigNumber result;
    result.sinal = a.sinal;
    result.number = criar_lista();
    result.number = soma(a.number, b.number, result.number, 0);

    destruir_lista(a.number);
    destruir_lista(b.number);

    return result;
}