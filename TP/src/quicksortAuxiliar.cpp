#include "quicksortAuxiliar.hpp"

#include <iostream>
using namespace std;

void particaoAuxiliar(Desempenho* desemp, int esq, int dir, int *i, int *j, ItemAuxiliar *vetorDesordenado) {
    ItemAuxiliar pivo, aux;
    *i = esq; 
    *j = dir;
    //detrmina o pivo como o 
    //elemento do meio do vetor
    pivo = vetorDesordenado[(*i + *j)/2];
    do {
        //itera pelo vetor da esquerda pra direita 
        //ate que a condicao seja satisfeita
        while (pivo.chaveAuxiliar > vetorDesordenado[*i].chaveAuxiliar) {
            (*i)++;
            desemp->comparacoes++;
        }

        desemp->comparacoes++;
        //itera pelo vetor da direita pra esquerda 
        //ate que a condicao seja satisfeita
        while (pivo.chaveAuxiliar < vetorDesordenado[*j].chaveAuxiliar) {
            (*j)--;
            desemp->comparacoes++;
        }

        desemp->comparacoes++;
        //troca os itens nas posicoes i e j
        //caso i for menor ou igual a j. Tambem 
        // incrementa i e decrementa j
        if (*i <= *j) {
            desemp->copias++;
            desemp->copias++;
            desemp->copias++;
            aux = vetorDesordenado[*i]; 
            vetorDesordenado[*i] = vetorDesordenado[*j]; 
            vetorDesordenado[*j] = aux;
            (*i)++; 
            (*j)--;
        }
    //itera ate que i e j se cruzem
    } while (*i <= *j);
}

void ordenaAuxiliar(Desempenho* desemp, int esq, int dir, ItemAuxiliar *vetorDesordenado) {
    int i, j;
    particaoAuxiliar(desemp, esq, dir, &i, &j, vetorDesordenado);
    if (esq < j) ordenaAuxiliar(desemp, esq, j, vetorDesordenado);
    if (i < dir) ordenaAuxiliar(desemp, i, dir, vetorDesordenado);
}

void quicksortAuxiliar(Desempenho* desemp, ItemAuxiliar *vetorDesordenado, int tamanho) {
    ordenaAuxiliar(desemp, 0, tamanho-1, vetorDesordenado);
}