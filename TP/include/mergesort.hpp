#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include "Item.hpp"
#include "desempenho.hpp"

//faz a juncao dos vetores ja ordenados
void merge(Desempenho* desemp, Item* vetorDesordenado, int esq, int meio, int dir);

//divide e o vetor
void mergesortRecursivo(Desempenho* desemp, Item* vetorDesordenado, int esq, int dir);

// faz a ordenacao de acordo com o mergesort
void mergesort(Desempenho* desemp, Item* vetorDesordenado, int tamanho);

#endif