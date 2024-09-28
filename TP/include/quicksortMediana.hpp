#ifndef QUICKSORTMEDIANA_HPP
#define QUICKSORTMEDIANA_HPP

#include "Item.hpp"
#include "desempenho.hpp"

//processa um vetor e encontra
//os indices i e j de particao
//baseados em um pivo escolhido
//como a mediana de k
//elementos aleatorios do vetor
void particaoMediana(Desempenho* desemp, int esq, int dir, int *i, int *j, Item *vetorDesordenado, int k);

//divide o vetor
void ordenaMediana(Desempenho* desemp, int esq, int dir, Item *vetorDesordenado, int k);

//faz a ordenacao do vetor de 
//acordo com o quicksort mediana
void quicksortMediana(Desempenho* desemp, Item *vetorDesordenado, int k, int tamanho);

#endif