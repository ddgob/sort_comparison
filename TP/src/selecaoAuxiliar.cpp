#include "selecaoAuxiliar.hpp"
#include "memlog.h"

#include <iostream>
using namespace std;

void selecaoAuxiliar(Desempenho* desemp, Item *vetorDesordenado, int esq, int dir) {
    int i, j, menor;
    Item aux;
    for (i = esq; i < dir; i++) {
        menor = i;
        for (j = i + 1 ; j < dir + 1; j++) {
            if (vetorDesordenado[j].chave < vetorDesordenado[menor].chave) {
                menor = j;
            }
            desemp->comparacoes++;
            LEMEMLOG((long int) (&(vetorDesordenado[menor])), sizeof(int), 0);
            LEMEMLOG((long int) (&(vetorDesordenado[j])), sizeof(int), 0);
        }
        if (i != menor) {
            aux = vetorDesordenado[menor];
            vetorDesordenado[menor] = vetorDesordenado[i];
            vetorDesordenado[i] = aux;
            LEMEMLOG((long int) (&(vetorDesordenado[i])), sizeof(Item), 0);
            LEMEMLOG((long int) (&(vetorDesordenado[menor])), sizeof(Item), 0);
            ESCREVEMEMLOG((long int) (&(vetorDesordenado[i])), sizeof(Item), 0);
            ESCREVEMEMLOG((long int) (&(vetorDesordenado[menor])), sizeof(Item), 0);
            desemp->copias++;
            desemp->copias++;
            desemp->copias++;
        }
    }
}