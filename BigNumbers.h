#ifndef BIGNUMBERS_H
#define BIGNUMBERS_H

typedef struct no* Lista;

struct no {
    int num;
    Lista prox;
};

// sinal sera 0 para um numero positivo e 1 para um numero negativo
struct BigNumber
{
    int sinal;
    Lista number;
};

typedef struct BigNumber BigNumber;

Lista criar_lista();

void destruir_lista(Lista L);

Lista criarNo(Lista L, int val);

Lista inverte(Lista anterior, Lista L);

#endif