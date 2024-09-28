#include <cstdlib>

#include "geradorDeVetorAleatorio.hpp"
#include "memlog.h"


Item* gerarVetorAleatorio(int tamanho, int semente) {

    Item *vetorDesordenado = new Item[tamanho];
    srand(semente);
    for (int i = 0; i < tamanho; i++) {
        ESCREVEMEMLOG((long int) (&(vetorDesordenado[i])), sizeof(Item), 0);
        vetorDesordenado[i].chave = rand() % tamanho;
        vetorDesordenado[i].numeroReal1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/tamanho));
        vetorDesordenado[i].numeroReal2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/tamanho));
        vetorDesordenado[i].numeroReal3 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/tamanho));
        vetorDesordenado[i].numeroReal4 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/tamanho));
        vetorDesordenado[i].numeroReal5 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/tamanho));
        vetorDesordenado[i].numeroReal6 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/tamanho));
        vetorDesordenado[i].numeroReal7 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/tamanho));
        vetorDesordenado[i].numeroReal8 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/tamanho));
        vetorDesordenado[i].numeroReal9 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/tamanho));
        vetorDesordenado[i].numeroReal10 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/tamanho));
        for (int j = 0; j < MAXCHAR; j++) {
            vetorDesordenado[i].cadeiaCaracter1[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter2[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter3[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter4[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter5[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter6[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter7[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter8[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter9[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter10[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter11[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter12[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter13[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter14[j] = char(32 + (rand() % 93));
            vetorDesordenado[i].cadeiaCaracter15[j] = char(32 + (rand() % 93));
        }
    }
    return vetorDesordenado;

}