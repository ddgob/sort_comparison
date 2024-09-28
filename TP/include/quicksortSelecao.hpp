#ifndef QUICKSORTSELECAO_HPP
#define QUICKSORTSELECAO_HPP

#include "Item.hpp"
#include "desempenho.hpp"

//processa um vetor e encontra
//os indices i e j de particao
//baseados em um pivo escolhido
//como o elemento do meio do vetor
void particaoSelecao(Desempenho* desemp, int esq, int dir, int *i, int *j, Item *vetorDesordenado);

//divide o vetor
void ordenaSelecao(Desempenho* desemp, int esq, int dir, Item *vetorDesordenado, int m);

//faz a ordenacao do vetor de 
//acordo com o quicksort selecao
//mudando para a ordenacao por 
//selecao a partir de um certo valor m
//de numero de elementos do vetor
void quicksortSelecao(Desempenho* desemp, Item *vetorDesordenado, int tamanho, int m);

#endif