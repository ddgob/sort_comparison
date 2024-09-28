#include "heapsort.hpp"
#include "memlog.h"

void constroi(Desempenho* desemp, Item *vetorDesordenado, int tamanho) { 
    int esq;
    esq = tamanho / 2 + 1; 
    while (esq > 1) {
        esq--;
        refaz(desemp, esq, tamanho, vetorDesordenado);
    }
}

void refaz(Desempenho* desemp, int esq, int dir, Item *vetorDesordenado) { 
    int i, j;
    Item aux;
    i = esq;
    j = i * 2;
    aux = vetorDesordenado[i-1];
    LEMEMLOG((long int) (&(vetorDesordenado[i-1])), sizeof(int), 0);
    while (j <= dir){
        if (j < dir) {
            desemp->comparacoes++;
            LEMEMLOG((long int) (&(vetorDesordenado[j - 1])), sizeof(int), 0);
            LEMEMLOG((long int) (&(vetorDesordenado[j])), sizeof(int), 0);
            if (vetorDesordenado[j-1].chave < vetorDesordenado[j].chave) {
                j++;
            }
        }
        desemp->comparacoes++;
        LEMEMLOG((long int) (&(vetorDesordenado[j - 1])), sizeof(int), 0);
        if (aux.chave >= vetorDesordenado[j-1].chave) {
            break; 
        }
        desemp->copias++;
        LEMEMLOG((long int) (&(vetorDesordenado[j - 1])), sizeof(int), 0);
        ESCREVEMEMLOG((long int) (&(vetorDesordenado[i - 1])), sizeof(Item), 0);
        vetorDesordenado[i-1] = vetorDesordenado[j-1];
        i = j;
        j = i * 2;
    }
    ESCREVEMEMLOG((long int) (&(vetorDesordenado[i - 1])), sizeof(Item), 0);
    vetorDesordenado[i-1] = aux;
}

void heapsort(Desempenho* desemp, Item *vetorDesordenado, int tamanho) { 
    int esq, dir;
    Item aux;
    //constroi o heap
    constroi(desemp, vetorDesordenado, tamanho);
    esq = 1; 
    dir = tamanho;
    //ordena o vetor
    while (dir > 1) { 
        LEMEMLOG((long int) (&(vetorDesordenado[0])), sizeof(Item), 0);
        LEMEMLOG((long int) (&(vetorDesordenado[dir - 1])), sizeof(Item), 0);
        ESCREVEMEMLOG((long int) (&(vetorDesordenado[0])), sizeof(Item), 0);
        ESCREVEMEMLOG((long int) (&(vetorDesordenado[dir - 1])), sizeof(Item), 0);
        desemp->copias++;
        desemp->copias++;
        desemp->copias++;
        aux = vetorDesordenado[0];
        vetorDesordenado[0] = vetorDesordenado[dir - 1];
        vetorDesordenado[dir - 1] = aux;
        dir--;
        refaz(desemp, esq, dir, vetorDesordenado);
    }
}