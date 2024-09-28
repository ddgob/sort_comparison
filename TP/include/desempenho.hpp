#ifndef DESEMPENHO_HPP
#define DESEMPENHO_HPP

//struct de desempenho
//utilizadas dentro dos algoritmos
typedef struct Desempenho {
    int comparacoes = 0;
    int copias = 0;
} Desempenho;

//struct de desempenho utilizado
//na funcao contabilizar()
typedef struct DesempenhoComTempo {
    Desempenho desempenho1000;
    Desempenho desempenho5000;
    Desempenho desempenho10000;
    Desempenho desempenho50000;
    Desempenho desempenho100000;
    Desempenho desempenho500000;
    Desempenho desempenho1000000;
    double tempo1000 = 0;
    double tempo5000 = 0;
    double tempo10000 = 0;
    double tempo50000 = 0;
    double tempo100000 = 0;
    double tempo500000 = 0;
    double tempo1000000 = 0;
} DesempenhoComTempo;

#endif