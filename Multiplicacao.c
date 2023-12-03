#include "BigNumbers.h"
#include "Soma.h"

#include <stdio.h>
#include <stdlib.h>

Lista Mult(Lista a, Lista b){

    Lista aux1=a, aux2=b, resultado = criar_lista(), help;
    int count=0, acumulado=0;
    
    while(aux1 != NULL){
        Lista SomaDaVez = criar_lista();

        for(int i=0;i<count;i++){
            Lista novo_no = criarNo(SomaDaVez, 0);
            SomaDaVez = novo_no;
        }

        while(aux2 != NULL){    
            int k = aux1->num * aux2->num;
            Lista novo_no = criarNo(SomaDaVez, (k%10)+acumulado);
            acumulado = k/10;
            SomaDaVez = novo_no;
            aux2 = aux2->prox;
        }
        
        if(acumulado != 0){
            Lista novo_no = criarNo(SomaDaVez, acumulado);
            SomaDaVez = novo_no;
        }

        SomaDaVez = inverte(criar_lista(), SomaDaVez);
        help = soma(SomaDaVez, resultado, criar_lista(), 0);

        destruir_lista(SomaDaVez);
        destruir_lista(resultado);

        resultado = help;
        resultado = inverte(criar_lista(), resultado);

        acumulado=0;
        count++;
        aux2 = b;
        aux1 = aux1->prox;
    }
    
    resultado = inverte(criar_lista(), resultado);
    return resultado;
}

BigNumber ChamarMult(BigNumber a, BigNumber b){
    BigNumber result;
    if(a.sinal == b.sinal)
        result.sinal = 0;
    else
        result.sinal = 1;

    result.number = Mult(a.number, b.number);

    destruir_lista(a.number);
    destruir_lista(b.number);

    return result;
}