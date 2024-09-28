#ifndef QUICKSORTNAORECINTEL_HPP
#define QUICKSORTNAORECINTEL_HPP

#include "Item.hpp"
#include "desempenho.hpp"

//processa um vetor e encontra
//os indices i e j de particao
void particaoNaoRecIntel(Desempenho* desemp, int esq, int dir, int *i, int *j, Item *vetorDesordenado);

//faz a ordenacao do vetor de 
//acordo com o quicksort empilha inteligente
//guardando as particoes maiores na pilha
//PilhaNaoRec 
void quicksortNaoRecIntel(Desempenho* desemp, Item* vetorDesordenado, int tamanho);


#endif