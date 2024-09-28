#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include "Item.hpp"
#include "desempenho.hpp"

//constroi o heap
void constroi(Desempenho* desemp, Item *vetorDesordenado, int tamanho);

//reestabelece o heap de acordo com:
//item na posição i é sempre maior 
//do que os itens na posição 2i e 2i + 1
void refaz(Desempenho* desemp, int esq, int dir, Item *vetorDesordenado);

//faz a ordenacao heapsort
void heapsort(Desempenho* desemp, Item *vetorDesordenado, int tamanho);

#endif