#include "mergesort.hpp"
#include "desempenho.hpp"
#include "memlog.h"

void merge(Desempenho* desemp, Item* vetorDesordenado, int esq, int meio, int dir) {
    Item *result = new Item[dir - esq + 1];
    int i = esq;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= dir) {
        desemp->comparacoes++;
        LEMEMLOG((long int)(&(vetorDesordenado[i])), sizeof(Item), 0);
        LEMEMLOG((long int)(&(vetorDesordenado[j])), sizeof(Item), 0);
        if (vetorDesordenado[i].chave <= vetorDesordenado[j].chave) {
            desemp->copias++;
            LEMEMLOG((long int)(&(vetorDesordenado[i])), sizeof(Item), 0);
            result[k] = vetorDesordenado[i];
            i++;
        } else {
            desemp->copias++;
            LEMEMLOG((long int)(&(vetorDesordenado[j])), sizeof(Item), 0);
            result[k] = vetorDesordenado[j];
            j++;
        }
        k++;
    }

    if (k < dir - esq + 1) {
        while (i <= meio) {
            desemp->copias++;
            LEMEMLOG((long int)(&(vetorDesordenado[i])), sizeof(Item), 0);
            result[k] = vetorDesordenado[i];
            k++;
            i++;
        }
        while (j <= dir) {
            desemp->copias++;
            LEMEMLOG((long int)(&(vetorDesordenado[j])), sizeof(Item), 0);
            result[k] = vetorDesordenado[j];
            k++;
            j++;
        }
    }

    for (int l = 0; l < dir - esq + 1; l++) {
        ESCREVEMEMLOG((long int) (&(vetorDesordenado[esq + l])), sizeof(Item), 0);
        vetorDesordenado[esq + l] = result[l];
    }

    delete[] result;
}

void mergesortRecursivo(Desempenho* desemp, Item* vetorDesordenado, int esq, int dir) {
    if (esq < dir) {
        int meio = (esq + dir)/2;
        //divide o vetor em 2
        mergesortRecursivo(desemp, vetorDesordenado, esq, meio);
        mergesortRecursivo(desemp, vetorDesordenado, meio+1, dir);
        //une os vetores ordenados
        merge(desemp, vetorDesordenado, esq, meio, dir);
    }
}

void mergesort(Desempenho* desemp, Item* vetorDesordenado, int tamanho) {
    mergesortRecursivo(desemp, vetorDesordenado, 0, tamanho - 1);
}