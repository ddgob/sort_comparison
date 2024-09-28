#include "quicksortNaoRecNaoIntel.hpp"
#include "PilhaNaoRec.hpp"
#include "ItemQuicksortNaoRec.hpp"
#include "memlog.h"

#include <iostream>
using namespace std;

void particaoNaoRecNaoIntel(Desempenho* desemp, int esq, int dir, int *i, int *j, Item *vetorDesordenado) {
    Item pivo, aux;
    *i = esq; 
    *j = dir;
    //detrmina o pivo como o 
    //elemento do meio do vetor
    pivo = vetorDesordenado[(*i + *j)/2];
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

void quicksortNaoRecNaoIntel(Desempenho* desemp, Item* vetorDesordenado, int tamanho) { 

    PilhaNaoRec pilha;
    ItemQuicksortNaoRec item;
    int esq, dir, i, j;

    esq = 0;
    dir = tamanho-1;
    item.dir = dir;
    item.esq = esq;
    pilha.Empilha(item);

    do {
        if(dir>esq) { 
            particaoNaoRecNaoIntel(desemp, esq, dir, &i, &j, vetorDesordenado); 
            //empilha particao da esquerda
            item.dir = j;
            item.esq = esq;
            pilha.Empilha(item);
            esq = i;
        } else {
            item.dir = pilha.topo->dir;
            item.esq = pilha.topo->esq;
            pilha.Desempilha(); 
            dir = item.dir;
            esq = item.esq;
        }

    } while (!pilha.isVazia());
}