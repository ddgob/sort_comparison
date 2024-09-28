#ifndef QUICKSORTRECURSIVO_HPP
#define QUICKSORTRECURSIVO_HPP

#include "Item.hpp"
#include "desempenho.hpp"

//processa um vetor e encontra
//os indices i e j de particao
//baseados em um pivo escolhido
//como o elemento do meio do vetor
void particaoRecursivo(Desempenho* desemp, int esq, int dir, int *i, int *j, Item *vetorDesordenado);

//divide o vetor
void ordenaRecursivo(Desempenho* desemp, int esq, int dir, Item *vetorDesordenado);

//faz a ordenacao do vetor de 
//acordo com o quicksort recursivo
void quicksortRecursivo(Desempenho* desemp, Item *vetorDesordenado, int tamanho);

#endif