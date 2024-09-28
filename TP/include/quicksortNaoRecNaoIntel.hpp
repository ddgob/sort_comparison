#ifndef QUICKSORTNAORECNAOINTEL_HPP
#define QUICKSORTNAORECNAOINTEL_HPP

#include "Item.hpp"
#include "desempenho.hpp"

//processa um vetor e encontra
//os indices i e j de particao
void quicksortNaoRecNaoIntel(Desempenho* desemp, Item* vetorDesordenado, int tamanho);

//faz a ordenacao do vetor de 
//acordo com o quicksort nao recursivo
//guardando as particoes da esquerda na pilha
//PilhaNaoRec 
void particaoNaoRecNaoIntel(Desempenho* desemp, int esq, int dir, int *i, int *j, Item *vetorDesordenado);

#endif