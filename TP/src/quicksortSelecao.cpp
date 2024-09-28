#include "quicksortSelecao.hpp"
#include "selecaoAuxiliar.hpp"
#include "memlog.h"

void particaoSelecao(Desempenho* desemp, int esq, int dir, int *i, int *j, Item *vetorDesordenado) {
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

void ordenaSelecao(Desempenho* desemp, int esq, int dir, Item *vetorDesordenado, int m) {
    //passa a ordenar por selecao
    //se o vetor tiver m ou menos
    //elementos
    if (dir - esq + 1 <= m) {
        selecaoAuxiliar(desemp, vetorDesordenado, esq, dir);
    } else {
        int i, j;
        particaoSelecao(desemp, esq, dir, &i, &j, vetorDesordenado);
        if (esq < j) ordenaSelecao(desemp, esq, j, vetorDesordenado, m);
        if (i < dir) ordenaSelecao(desemp, i, dir, vetorDesordenado, m);
    }
    
}

void quicksortSelecao(Desempenho* desemp, Item *vetorDesordenado, int tamanho, int m) {
    ordenaSelecao(desemp, 0, tamanho-1, vetorDesordenado, m);
}