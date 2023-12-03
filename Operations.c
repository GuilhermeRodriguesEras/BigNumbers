#include "Operations.h"
#include "Soma.h"
#include "Subtracao.h"
#include "Multiplicacao.h"
#include "BigNumbers.h"
#include <stdio.h>
#include <stdlib.h>

BigNumber ChamaOperacao(BigNumber a, BigNumber b, char operation){

    if(operation == 'x')
        return ChamarMult(a,b);
    if(operation == '-'){
        if(b.sinal)
            b.sinal = 0;
        else
            b.sinal =1;
    }

    if (a.sinal == b.sinal)
        return ChamarSoma(a,b);
    else
        return ChamarSub(a,b);
}


int main(){
    Lista L1 = criar_lista();
    Lista L2 = criar_lista();
    BigNumber a, b, result;
    result.sinal = a.sinal = b.sinal = 0;

    int n1;
    int n2;

    printf("Digite quantos valores voce quer inserir na primeira lista: ");
    scanf("%d", &n1);

    L1 = insere_vals_lista(L1,n1);

    printf("Digite quantos valores voce quer inserir na segunda lista: ");
    scanf("%d", &n2);

    L2 = insere_vals_lista(L2,n2);

    a.number = L1;
    b.number = L2;

    //L1 = Sub(L1, L2);
    result = ChamarSoma(a,b);

    //L1 = inverte(NULL, L1);

    printf("Essa eh a nossa soma: \n");
    imprimirLista(result.number);

    destruir_lista(result.number);

    return 0;
}

