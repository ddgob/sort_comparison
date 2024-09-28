#ifndef PIVOMEDIANA_HPP
#define PIVOMEDIANA_HPP

#include "Item.hpp"
#include "desempenho.hpp"

//calcula o pivo como a mediana
//de k elementos do vetor escolhidos
//aleatoriamente, com auxilio de um 
//quicksort (o quicksort auxiliar)
int pivoMediana(Desempenho* desemp, Item *vetorDesordenado, int esq, int dir, int k);

#endif