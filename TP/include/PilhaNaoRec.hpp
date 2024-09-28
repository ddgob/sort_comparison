#ifndef PILHANAOREC_HPP
#define PILHANAOREC_HPP

#include "ItemQuicksortNaoRec.hpp"

//pilha usada para armazenar
//particoes a serem processadas 
//posteriormente no quicksort nao
//recursivo e empilha inteligente
class PilhaNaoRec {
    public:
        PilhaNaoRec();
        
        void Empilha(ItemQuicksortNaoRec itemASerEmpilhado_);

        void Desempilha();

        bool isVazia();

        ItemQuicksortNaoRec* topo;
};

#endif