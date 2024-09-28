#ifndef SELECAOAUXILIAR_HPP
#define SELECAOAUXILIAR_HPP

#include "Item.hpp"
#include "desempenho.hpp"

//algoritmo de ordenacao por selecao
//que auxilia o quicksort selecao
void selecaoAuxiliar(Desempenho* desemp, Item *vetorDesordenado, int esq, int dir);

#endif