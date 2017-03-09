#include <stdio.h>
#include <stdlib.h>
#include "busca.h"



int busca (int n, int* vet, int elem)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (elem == vet[i])
            return i; /* elemento encontrado */
    }
    /* elemento n�o encontrado ap�s percorrer todo o vetor */
    return -1;
}


int busca_ord (int n, int* vet, int elem)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (elem == vet[i])
            return i; /* elemento encontrado */
        else if (elem < vet[i])
            return -1;/* interrompe busca */
    }
    /* percorreu todo o vetor e n�o encontrou elemento */
    return -1;
}


int busca_bin (int n, int* vet, int elem)
{
    /* no in�cio consideramos todo o vetor */
    int ini = 0;
    int fim = n-1;
    int meio;
    /* enquanto a parte restante for maior que zero */
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (elem < vet[meio])
            fim = meio - 1; /* ajusta posi��o final */
        else if (elem > vet[meio])
            ini = meio + 1; /* ajusta posi��o inicial */
        else
            return meio; /* elemento encontrado */
    }
    /* n�o encontrou: restou parte de tamanho zero */
    return -1;
}

int busca_bin_rec (int n, int* vet, int elem)
{
    /* testa condi��o de contorno: parte com tamanho zero */
    if (n <= 0)
        return -1;
    else
    {
        /* deve buscar o elemento do meio */
        int meio = n / 2;
        if (elem < vet[meio])
            return busca_bin_rec(meio,vet,elem);
        else if (elem > vet[meio])
        {
            int r = busca_bin_rec(n-1-meio, &vet[meio+1],elem);
            if (r<0) return -1;
            else return meio+1+r; /* corre��o do valor retornado */
        }
        else
            return meio; /* elemento encontrado */
    }
}
