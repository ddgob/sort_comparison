#include "PilhaNaoRec.hpp"

#include <iostream>
using namespace std;


PilhaNaoRec::PilhaNaoRec() {
    topo = nullptr;
}

void PilhaNaoRec::Empilha(ItemQuicksortNaoRec itemASerEmpilhado_) {
    ItemQuicksortNaoRec *itemASerEmpilhado = new ItemQuicksortNaoRec();
    itemASerEmpilhado->dir = itemASerEmpilhado_.dir;
    itemASerEmpilhado->esq = itemASerEmpilhado_.esq;
    if (isVazia()) {
        topo = itemASerEmpilhado;
    } else {
        itemASerEmpilhado->proximoItem = topo;
        topo = itemASerEmpilhado;
    }
}

void PilhaNaoRec::Desempilha() {
    if (!isVazia()) {
        ItemQuicksortNaoRec* aux = topo;
        topo = topo->proximoItem;
        delete aux;
    }
}

bool PilhaNaoRec::isVazia() {
    if (topo == nullptr) {
        return true;
    }
    return false;
}