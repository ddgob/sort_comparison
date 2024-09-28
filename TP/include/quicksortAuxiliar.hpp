#ifndef QUICKSORTAUXILIAR_HPP
#define QUICKSORTAUXILIAR_HPP

#include "itemAuxiliar.hpp"
#include "desempenho.hpp"

//processa um vetor e econtra
//os indices i e j de particao
void particaoAuxiliar(Desempenho* desemp, int esq, int dir, int *i, int *j, ItemAuxiliar *vetorDesordenado);

//divide o vetor
void ordenaAuxiliar(Desempenho* desemp, int esq, int dir, ItemAuxiliar *vetorDesordenado);

//faz a ordenacao do vetor de 
//acordo com o quicksort recursivo
void quicksortAuxiliar(Desempenho* desemp, ItemAuxiliar *vetorDesordenado, int tamanho);


#endif