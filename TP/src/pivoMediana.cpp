#include "pivoMediana.hpp"
#include "quicksortAuxiliar.hpp"
#include "itemAuxiliar.hpp"
#include "memlog.h"

#include <iostream>
using namespace std;

#include <cstdlib>

int pivoMediana(Desempenho* desemp, Item *vetorDesordenado, int esq, int dir, int k) {

    ItemAuxiliar *vetorKPivos = new ItemAuxiliar[k];
    srand(1);
    int posicaoAleatoria;
    //cria um vetor auxiliar com k
    //elementos do vetor original
    //escolhidos aleatoriamente
    for (int i = 0; i < k; i++) {
        posicaoAleatoria = esq + (rand() % (dir - esq + 1));
        LEMEMLOG((long int) (&(vetorDesordenado[posicaoAleatoria])), sizeof(int), 0);
        vetorKPivos[i].chaveAuxiliar = vetorDesordenado[posicaoAleatoria].chave;
        vetorKPivos[i].posicaoNoVetorDesordenado = posicaoAleatoria;
    }
    //ordena o vetor auxiliar
    quicksortAuxiliar(desemp, vetorKPivos, k);

    //retorna a chave da posicao do 
    //item da mediana do vetor auxiliar 
    //no vetor original
    return vetorKPivos[k / 2].posicaoNoVetorDesordenado;
}