#include <iostream>
#include <stdio.h>
#include <getopt.h>
#include <sys/resource.h>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include "Item.hpp"
#include "geradorDeVetorAleatorio.hpp"
#include "quicksortRecursivo.hpp"
#include "quicksortAuxiliar.hpp"
#include "quicksortMediana.hpp"
#include "pivoMediana.hpp"
#include "selecaoAuxiliar.hpp"
#include "quicksortSelecao.hpp"
#include "PilhaNaoRec.hpp"
#include "quicksortNaoRecIntel.hpp"
#include "quicksortNaoRecNaoIntel.hpp"
#include "mergesort.hpp"
#include "heapsort.hpp"
#include "desempenho.hpp"
#include "msgassert.h"
#include "memlog.h"
#include "contabilizar.hpp"



using namespace std;

int main(int argc, char* argv[]) {

    string tipoDeOrdenacao = argv[1];
    if (tipoDeOrdenacao == "-c") {
        //contabiliza os resultados para
        //5 sementes e todos os algoritmos
        //incluindo mediana com
        //k = 3, 4 e 5 e selecao com
        //m = 10 e 100
        contabilizar();
    } else {

        //declaracao das variaveis que serao
        //usadas para ler do terminal e
        //conferir se as opcoes corretas
        //foram passadas
        extern char*optarg;
        int flag, semente, mediana, selecao;
        string nomeEntrada, nomeSaida, sementeString, medianaString, selecaoString;
        char log[100];
        string tipoQuicksort = "";
        bool memLogAtivado = false;
        bool memLogIniciado = false;
        //garante que sera passado o tipo
        //de ordenacao correto
        erroAssert(tipoDeOrdenacao == "quicksort" || tipoDeOrdenacao == "heapsort" || tipoDeOrdenacao == "mergesort",
        "Tipo de ordenação inválida. Por favor passe como primeiro argumento: quicksort, heapsort ou mergesort.");
        bool sementePassada = false;
        bool arquivoDeEntradaPassado = false;
        bool arquivoDeSaidaPassado = false;
        bool medianaPassada = false;
        bool selecaoPassada = false;

        //getopt para leitura dos 
        //argumentos passados no terminal
        while((flag = getopt(argc, argv, "v:s:i:o:k:m:p:lce")) != EOF) {
            switch(flag) {
                case 'v':
                    //verifica que a versao do quicksort
                    //eh passado quando se seleciona o
                    //quicksort
                    erroAssert(tipoDeOrdenacao == "quicksort",
                    "A flag '-v' deve ser passada apenas para métodos de ordenação quicksort");
                    tipoQuicksort = optarg;
                    //verifica que a versao de quicksort
                    //passado eh valido
                    erroAssert(tipoQuicksort == "1" || tipoQuicksort == "2" || tipoQuicksort == "3" || tipoQuicksort == "4" || tipoQuicksort == "5", 
                    "Versao de quicksort inválido. Passe a flag '-v' seguido de: '1' para quicksort recursivo, '2' para quicksort mediana, '3' para quicksort selecao, '4' para quicksort nao recursivo, '5' para quicksort empilha inteligente");
                    break;
                case 's':
                    sementeString = optarg;
                    semente = stoi(sementeString);
                    sementePassada = true;
                    break;
                case 'i':
                    nomeEntrada = optarg;
                    arquivoDeEntradaPassado = true;
                    break;
                case 'o':
                    nomeSaida = optarg;
                    arquivoDeSaidaPassado = true;
                    break;
                case 'k':
                    medianaString = optarg;
                    mediana = stoi(medianaString);
                    medianaPassada = true;
                    break;
                case 'm':
                    selecaoString = optarg;
                    selecao = stoi(selecaoString);
                    selecaoPassada = true;
                    break;
                case 'p':
                    //permite a coleta dos logs
                    strcpy(log,optarg);
                    iniciaMemLog(log);
                    desativaMemLog();
                    memLogIniciado = true;
                    break;
                case 'l':
                    //coleta os logs
                    ativaMemLog();
                    memLogAtivado = true;
                    break;
                default:
                    break;
            }
        }

        
        if (tipoDeOrdenacao == "quicksort") {
            //verifica que se o quicksort for selecionado
            //seja passsado uma versao
            erroAssert(tipoQuicksort != "",
            "Quando o metodo de ordenacao quicksort eh selecionado, faz-se obrigatorio a passagem da versao do quicksort que se deseja usar");
            if (tipoQuicksort == "2") {
                //verifica que se o quicksort for selecionado
                //e for de mediana, seja passsado o param-
                //-etro k
                erroAssert(medianaPassada == true,
                "Eh obrigatorio a passagem do numero de elementos do vetor de onde sera tirada a mediana pelo terminal atraves da flag -k");
            }
            if (tipoQuicksort == "3") {
                //verifica que se o quicksort for selecionado
                //e for de selecao, seja passsado o param-
                //-etro m
                erroAssert(selecaoPassada == true,
                "Eh obrigatorio a passagem do tamanho da particao a partir do qual sera usado a selecao para a ordenacao pelo terminal atraves da flag -m");
            }
        }

        //verifica que os parametros
        //obrigatorios (semente,
        //arquivo de entrada e arquivo
        //de saida) sejam passados
        erroAssert(sementePassada == true,
        "Eh obrigatorio a passagem da semente pelo terminal atraves da flag -s");
        erroAssert(arquivoDeEntradaPassado == true,
        "Eh obrigatorio a passagem do nome do arquivo de entrada pelo terminal atraves da flag -i");
        erroAssert(arquivoDeSaidaPassado == true,
        "Eh obrigatorio a passagem do nome do arquivo de saida pelo terminal atraves da flag -o");

        /*
        Evita que memlog seja ativado antes de ser
        iniciado, fazendo com que os registros de
        acesso nao seja escritos no arquivo de
        registros de acesso
        */
        if(memLogAtivado == true && memLogIniciado == true) {
            ativaMemLog();
        }

        /*
        Verifica que o nome do arquivo de registro de
        acesso seja passado no terminal pela flag -p
        para que sejam gravados os registros de acesso
        requeridos pela flag -l
        */
        if(memLogAtivado == true && memLogIniciado == false) {
            erroAssert(memLogAtivado == false,
            "eh necessario passar o nome do arquivo de registros no terminal pela flag -p para que sejam gravados os registros de acesso requeridos pela flag -l");
        }

        //abre o arquivo de entradas
        //e declara as variaveis
        //para a sua leitura  
        int numeroEntradas;
        ifstream arquivoEntrada;
        arquivoEntrada.open(nomeEntrada);
        //verifica que o arquivo de entrada
        //foi aberto corretamente
        erroAssert(arquivoEntrada.is_open() == true,
        "Erro ao tentar abrir arquivo de entrada");
        arquivoEntrada >> numeroEntradas;
        int* tamanhosVetores = new int[numeroEntradas];
        //le os tokens do arquivo de entrada
        for (int i = 0; i < numeroEntradas; i++) {
            arquivoEntrada >> tamanhosVetores[i];
        }

        arquivoEntrada.close();

        //cria o arquivo de saida
        ofstream arquivoSaida;
        arquivoSaida.open(nomeSaida);
        erroAssert(arquivoSaida.is_open() == true,
        "Erro ao tentar criar arquivo de saida");

        //a partir daqui sao executados os 
        //algoritmos de ordenacao dependendo
        //dos argumentos passados pelo terminal
        Desempenho desemp;

        if (tipoDeOrdenacao == "quicksort") {
            if (tipoQuicksort == "1") {

                arquivoSaida << "Quicksort: Recursivo | Semente: " << semente << endl;
                arquivoSaida << "____________________________________" << endl;
                arquivoSaida << endl;

                for (int i = 0; i < numeroEntradas; i++) {

                    defineFaseMemLog(0);
                    
                    //gera o vetor a ser ordenado
                    //com itens aleatorios dado
                    //uma semente e aloca ele
                    Item *vetorDesordenado = gerarVetorAleatorio(tamanhosVetores[i], semente);

                    defineFaseMemLog(1);

                    //cria estruturas para analise
                    //dos tempos de execucao
                    struct rusage resources;
                    int rc;
                    double utime, stime, total_time;
                    
                    //inicia contagem tempo de execucao

                    quicksortRecursivo(&desemp, vetorDesordenado, tamanhosVetores[i]);

                    //finda contagem tempo de execucao

                    //retorna erro caso a analise de tempo
                    //de execucao falhe
                    if((rc = getrusage(RUSAGE_SELF, &resources)) != 0) {
                        perror("getrusage failed");
                    }
                    utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
                    stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
                    total_time = utime+stime;

                    //printa resultados de desempenho
                    //no arquivo de saida
                    arquivoSaida << "Tam. Vet.: " << tamanhosVetores[i] << " | Num. Comparacoes: " << desemp.comparacoes << " | Num. Copias: " << desemp.copias << " | Temp. Tot: " << total_time << " |" << endl;

                    delete[] vetorDesordenado;

                }

            } else if (tipoQuicksort == "2") {

                arquivoSaida << "Quicksort: Mediana | Semente: " << semente << " | k: " << mediana << " |" << endl;
                arquivoSaida << "_____________________________________________" << endl;
                arquivoSaida << endl;

                for (int i = 0; i < numeroEntradas; i++) {

                    defineFaseMemLog(0);
                    
                    //gera o vetor a ser ordenado
                    //com itens aleatorios dado
                    //uma semente e aloca ele
                    Item *vetorDesordenado = gerarVetorAleatorio(tamanhosVetores[i], semente);

                    defineFaseMemLog(1);

                    //cria estruturas para analise
                    //dos tempos de execucao
                    struct rusage resources;
                    int rc;
                    double utime, stime, total_time;
                    
                    //inicia contagem tempo de execucao

                    quicksortMediana(&desemp, vetorDesordenado, tamanhosVetores[i], mediana);

                    //finda contagem tempo de execucao

                    //retorna erro caso a analise de tempo
                    //de execucao falhe
                    if((rc = getrusage(RUSAGE_SELF, &resources)) != 0) {
                        perror("getrusage failed");
                    }
                    utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
                    stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
                    total_time = utime+stime;

                    //printa resultados de desempenho
                    //no arquivo de saida
                    arquivoSaida << "Tam. Vet.: " << tamanhosVetores[i] << " | Num. Comparacoes: " << desemp.comparacoes << " | Num. Copias: " << desemp.copias << " | Temp. Tot: " << total_time << " |" << endl;

                    delete[] vetorDesordenado;

                }

            } else if (tipoQuicksort == "3") {

                arquivoSaida << "Quicksort: Selecao | Semente: " << semente << " | m: " << selecao << " |" << endl;
                arquivoSaida << "_____________________________________________" << endl;
                arquivoSaida << endl;

                for (int i = 0; i < numeroEntradas; i++) {

                    defineFaseMemLog(0);
                    
                    //gera o vetor a ser ordenado
                    //com itens aleatorios dado
                    //uma semente e aloca ele
                    Item *vetorDesordenado = gerarVetorAleatorio(tamanhosVetores[i], semente);

                    defineFaseMemLog(1);

                    //cria estruturas para analise
                    //dos tempos de execucao
                    struct rusage resources;
                    int rc;
                    double utime, stime, total_time;
                    
                    //inicia contagem tempo de execucao

                    quicksortSelecao(&desemp, vetorDesordenado, tamanhosVetores[i], selecao);

                    //finda contagem tempo de execucao

                    //retorna erro caso a analise de tempo
                    //de execucao falhe
                    if((rc = getrusage(RUSAGE_SELF, &resources)) != 0) {
                        perror("getrusage failed");
                    }
                    utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
                    stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
                    total_time = utime+stime;

                    //printa resultados de desempenho
                    //no arquivo de saida
                    arquivoSaida << "Tam. Vet.: " << tamanhosVetores[i] << " | Num. Comparacoes: " << desemp.comparacoes << " | Num. Copias: " << desemp.copias << " | Temp. Tot: " << total_time << " |" << endl;

                    delete[] vetorDesordenado;

                }

            } else if (tipoQuicksort == "4") {

                arquivoSaida << "Quicksort: Nao Recursivo | Semente: " << semente << endl;
                arquivoSaida << "___________________________________" << endl;
                arquivoSaida << endl;

                for (int i = 0; i < numeroEntradas; i++) {

                    defineFaseMemLog(0);
                    
                    //gera o vetor a ser ordenado
                    //com itens aleatorios dado
                    //uma semente e aloca ele
                    Item *vetorDesordenado = gerarVetorAleatorio(tamanhosVetores[i], semente);

                    defineFaseMemLog(1);

                    //cria estruturas para analise
                    //dos tempos de execucao
                    struct rusage resources;
                    int rc;
                    double utime, stime, total_time;
                    
                    //inicia contagem tempo de execucao

                    quicksortNaoRecNaoIntel(&desemp, vetorDesordenado, tamanhosVetores[i]);

                    //finda contagem tempo de execucao

                    //retorna erro caso a analise de tempo
                    //de execucao falhe
                    if((rc = getrusage(RUSAGE_SELF, &resources)) != 0) {
                        perror("getrusage failed");
                    }
                    utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
                    stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
                    total_time = utime+stime;

                    //printa resultados de desempenho
                    //no arquivo de saida
                    arquivoSaida << "Tam. Vet.: " << tamanhosVetores[i] << " | Num. Comparacoes: " << desemp.comparacoes << " | Num. Copias: " << desemp.copias << " | Temp. Tot: " << total_time << " |" << endl;

                    delete[] vetorDesordenado;

                }

            } else if (tipoQuicksort == "5") {

                arquivoSaida << "Quicksort: Empilha Inteligente | Semente: " << semente << endl;
                arquivoSaida << "___________________________________" << endl;
                arquivoSaida << endl;

                for (int i = 0; i < numeroEntradas; i++) {

                    defineFaseMemLog(0);
                    
                    //gera o vetor a ser ordenado
                    //com itens aleatorios dado
                    //uma semente e aloca ele
                    Item *vetorDesordenado = gerarVetorAleatorio(tamanhosVetores[i], semente);

                    defineFaseMemLog(1);

                    //cria estruturas para analise
                    //dos tempos de execucao
                    struct rusage resources;
                    int rc;
                    double utime, stime, total_time;
                    
                    //inicia contagem tempo de execucao

                    quicksortNaoRecIntel(&desemp, vetorDesordenado, tamanhosVetores[i]);

                    //finda contagem tempo de execucao

                    //retorna erro caso a analise de tempo
                    //de execucao falhe
                    if((rc = getrusage(RUSAGE_SELF, &resources)) != 0) {
                        perror("getrusage failed");
                    }
                    utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
                    stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
                    total_time = utime+stime;

                    //printa resultados de desempenho
                    //no arquivo de saida
                    arquivoSaida << "Tam. Vet.: " << tamanhosVetores[i] << " | Num. Comparacoes: " << desemp.comparacoes << " | Num. Copias: " << desemp.copias << " | Temp. Tot: " << total_time << " |" << endl;

                    delete[] vetorDesordenado;

                }

            }
        } else if (tipoDeOrdenacao == "mergesort") {

            arquivoSaida << "Mergesort | Semente: " << semente << endl;
            arquivoSaida << "___________________________________" << endl;
            arquivoSaida << endl;

            for (int i = 0; i < numeroEntradas; i++) {

                defineFaseMemLog(0);
                
                //gera o vetor a ser ordenado
                //com itens aleatorios dado
                //uma semente e aloca ele
                Item *vetorDesordenado = gerarVetorAleatorio(tamanhosVetores[i], semente);

                defineFaseMemLog(1);

                //cria estruturas para analise
                //dos tempos de execucao
                struct rusage resources;
                int rc;
                double utime, stime, total_time;
                
                //inicia contagem tempo de execucao

                mergesort(&desemp, vetorDesordenado, tamanhosVetores[i]);

                //finda contagem tempo de execucao

                //retorna erro caso a analise de tempo
                    //de execucao falhe
                if((rc = getrusage(RUSAGE_SELF, &resources)) != 0) {
                    perror("getrusage failed");
                }
                utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
                stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
                total_time = utime+stime;

                //printa resultados de desempenho
                //no arquivo de saida
                arquivoSaida << "Tam. Vet.: " << tamanhosVetores[i] << " | Num. Comparacoes: " << desemp.comparacoes << " | Num. Copias: " << desemp.copias << " | Temp. Tot: " << total_time << " |" << endl;

                delete[] vetorDesordenado;

            }

        } else if (tipoDeOrdenacao == "heapsort") {

            arquivoSaida << "Heapsort | Semente: " << semente << endl;
            arquivoSaida << "___________________________________" << endl;
            arquivoSaida << endl;

            for (int i = 0; i < numeroEntradas; i++) {

                defineFaseMemLog(0);
                
                //gera o vetor a ser ordenado
                //com itens aleatorios dado
                //uma semente e aloca ele
                Item *vetorDesordenado = gerarVetorAleatorio(tamanhosVetores[i], semente);

                defineFaseMemLog(1);

                //cria estruturas para analise
                //dos tempos de execucao
                struct rusage resources;
                int rc;
                double utime, stime, total_time;
                
                //inicia contagem tempo de execucao

                heapsort(&desemp, vetorDesordenado, tamanhosVetores[i]);

                //finda contagem tempo de execucao

                //retorna erro caso a analise de tempo
                //de execucao falhe
                if((rc = getrusage(RUSAGE_SELF, &resources)) != 0) {
                    perror("getrusage failed");
                }
                utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
                stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
                total_time = utime+stime;

                //printa resultados de desempenho
                //no arquivo de saida
                arquivoSaida << "Tam. Vet.: " << tamanhosVetores[i] << " | Num. Comparacoes: " << desemp.comparacoes << " | Num. Copias: " << desemp.copias << " | Temp. Tot: " << total_time << " |" << endl;

                delete[] vetorDesordenado;

            }

        }

        arquivoSaida.close();        
        delete[] tamanhosVetores;

        if (memLogAtivado) {
            return finalizaMemLog();
        } else {
            return 0;
        }
    }
}