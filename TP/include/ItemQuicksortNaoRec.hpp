#ifndef ITEMQUICKSORTNAOREC_HPP
#define ITEMQUICKSORTNAOREC_HPP

//item utilizado para construir a pilha
//do quicksort nao recursivo
//e do quicksort empilha inteligente
typedef struct ItemQuicksortNaoRec {
    int dir;
    int esq;
    ItemQuicksortNaoRec* proximoItem;
} ItemQuicksortNaoRec;

#endif