#include <cstdlib>

#include "quicksortMediana.hpp"
#include "pivoMediana.hpp"
#include "memlog.h"

#include <iostream>
using namespace std;

/* faz a particao de um vetor 
de itens a partir de um pivo 
arbitrario em dois vetores: 
um com itens de chave maior 
ou igual ao pivo e outro com 
itens de chave menor ou igual 
ao pivo */
void particaoMediana(Desempenho* desemp, int esq, int dir, int *i, int *j, Item *vetorDesordenado, int k) {
    Item pivo, aux;
    *i = esq; 
    *j = dir;
    //detrmina o pivo como a mediana de k
    //elementos do vetor escolhido aleatoriamente
    int posPivo = pivoMediana(desemp, vetorDesordenado, esq, dir, k);
    pivo = vetorDesordenado[posPivo];

    do {
        //itera pelo vetor da esquerda pra direita 
        //ate que a condicao seja satisfeita
        while (pivo.chave > vetorDesordenado[*i].chave) {
            desemp->comparacoes++;
            LEMEMLOG((long int) (&(vetorDesordenado[*i])), sizeof(int), 0);
            (*i)++;
        }
        LEMEMLOG((long int) (&(vetorDesordenado[*i])), sizeof(int), 0);
        desemp->comparacoes++;
        //itera pelo vetor da direita pra esquerda 
        //ate que a condicao seja satisfeita
        while (pivo.chave < vetorDesordenado[*j].chave) {
            desemp->comparacoes++;
            LEMEMLOG((long int) (&(vetorDesordenado[*j])), sizeof(int), 0);
            (*j)--;
        }
        LEMEMLOG((long int) (&(vetorDesordenado[*j])), sizeof(int), 0);
        desemp->comparacoes++;
        
        //troca os itens nas posicoes i e j
        //caso i for menor ou igual a j. Tambem 
        // incrementa i e decrementa j
        if (*i <= *j) {
            aux = vetorDesordenado[*i]; 
            vetorDesordenado[*i] = vetorDesordenado[*j]; 
            vetorDesordenado[*j] = aux;
            LEMEMLOG((long int) (&(vetorDesordenado[*i])), sizeof(Item), 0);
            LEMEMLOG((long int) (&(vetorDesordenado[*j])), sizeof(Item), 0);
            ESCREVEMEMLOG((long int) (&(vetorDesordenado[*i])), sizeof(Item), 0);
            ESCREVEMEMLOG((long int) (&(vetorDesordenado[*j])), sizeof(Item), 0);
            desemp->copias++;
            desemp->copias++;
            desemp->copias++;
            (*i)++; 
            (*j)--;
        }
    //itera ate que i e j se cruzem
    } while (*i <= *j);
}

void ordenaMediana(Desempenho* desemp, int esq, int dir, Item *vetorDesordenado, int k) {
    int i, j;
    particaoMediana(desemp, esq, dir, &i, &j, vetorDesordenado, k);
    if (esq < j) ordenaMediana(desemp, esq, j, vetorDesordenado, k);
    if (i < dir) ordenaMediana(desemp, i, dir, vetorDesordenado, k);
}

void quicksortMediana(Desempenho* desemp, Item *vetorDesordenado, int tamanho, int k) {
    ordenaMediana(desemp, 0, tamanho-1, vetorDesordenado, k);
}