#ifndef CONTABILIZAR_HPP
#define CONTABILIZAR_HPP

#include <string>
#include <iostream>
#include <fstream>

#include "desempenho.hpp"

using namespace std;

//contabiliza os resultados medios para
//arquivos de 7 entradas e 5 sementes
//de todos os algoritmos analisados
void contabilizar() {
    ifstream arquivoAtual;
    DesempenhoComTempo desempContblzdV1;
    DesempenhoComTempo desempContblzdV2K3;
    DesempenhoComTempo desempContblzdV2K5;
    DesempenhoComTempo desempContblzdV2K7;
    DesempenhoComTempo desempContblzdV3M10;
    DesempenhoComTempo desempContblzdV3M100;
    DesempenhoComTempo desempContblzdV4;
    DesempenhoComTempo desempContblzdV5;
    DesempenhoComTempo desempContblzdMerge;
    DesempenhoComTempo desempContblzdHeap;

    int sementes[5] = {10, 58, 649, 396284, 98278992};
    int valorK[3] = {3, 5, 7};
    int valorM[2] = {10, 100};
    int numeroDeTiposDeOrdenação = 7;
    int numeroDeSementes = 5;
    for (int v = 1; v <= numeroDeTiposDeOrdenação; v++) {
        for (int s = 0; s < numeroDeSementes; s++) {
            if (v == 1) {
                string nomeArquivo = "saidaV" + to_string(v) + "S" + to_string(sementes[s]) + ".txt";
                arquivoAtual.open(nomeArquivo);
                if (!arquivoAtual.is_open()) {
                    cout << "Erro ao abrir" <<  endl;
                }
                string aux, comand, tamVet;
                arquivoAtual >> aux;
                comand = aux;
                while (arquivoAtual >> aux) {
                    if (comand == "Vet.:") {
                        tamVet = aux;
                    }
                    if (tamVet == "1000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV1.desempenho1000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV1.desempenho1000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV1.tempo1000 += stod(aux);
                        }
                    } else if (tamVet == "5000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV1.desempenho5000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV1.desempenho5000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV1.tempo5000 += stod(aux);
                        }
                    } else if (tamVet == "10000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV1.desempenho10000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV1.desempenho10000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV1.tempo10000 += stod(aux);
                        }
                    } else if (tamVet == "50000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV1.desempenho50000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV1.desempenho50000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV1.tempo50000 += stod(aux);
                        }
                    } else if (tamVet == "100000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV1.desempenho100000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV1.desempenho100000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV1.tempo100000 += stod(aux);
                        }
                    } else if (tamVet == "500000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV1.desempenho500000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV1.desempenho500000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV1.tempo500000 += stod(aux);
                        }
                    } else if (tamVet == "1000000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV1.desempenho1000000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV1.desempenho1000000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV1.tempo1000000 += stod(aux);
                        }
                    }
                    comand = aux;
                }
                arquivoAtual.close();
            } else if (v == 2) {
                for (int k = 0; k < 3; k++) {
                    string nomeArquivo = "saidaV" + to_string(v) + "S" + to_string(sementes[s]) + "K" + to_string(valorK[k]) + ".txt";
                    arquivoAtual.open(nomeArquivo);
                    string aux, comand, tamVet;
                    arquivoAtual >> aux;
                    comand = aux;
                    if (k == 0) {
                        while (arquivoAtual >> aux) {
                            if (comand == "Vet.:") {
                                tamVet = aux;
                            }
                            if (tamVet == "1000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K3.desempenho1000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K3.desempenho1000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K3.tempo1000 += stod(aux);
                                }
                            } else if (tamVet == "5000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K3.desempenho5000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K3.desempenho5000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K3.tempo5000 += stod(aux);
                                }
                            } else if (tamVet == "10000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K3.desempenho10000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K3.desempenho10000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K3.tempo10000 += stod(aux);
                                }
                            } else if (tamVet == "50000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K3.desempenho50000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K3.desempenho50000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K3.tempo50000 += stod(aux);
                                }
                            } else if (tamVet == "100000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K3.desempenho100000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K3.desempenho100000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K3.tempo100000 += stod(aux);
                                }
                            } else if (tamVet == "500000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K3.desempenho500000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K3.desempenho500000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K3.tempo500000 += stod(aux);
                                }
                            } else if (tamVet == "1000000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K3.desempenho1000000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K3.desempenho1000000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K3.tempo1000000 += stod(aux);
                                }
                            }
                            comand = aux;
                        }
                    } else if (k == 1) {
                        while (arquivoAtual >> aux) {
                            if (comand == "Vet.:") {
                                tamVet = aux;
                            }
                            if (tamVet == "1000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K5.desempenho1000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K5.desempenho1000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K5.tempo1000 += stod(aux);
                                }
                            } else if (tamVet == "5000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K5.desempenho5000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K5.desempenho5000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K5.tempo5000 += stod(aux);
                                }
                            } else if (tamVet == "10000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K5.desempenho10000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K5.desempenho10000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K5.tempo10000 += stod(aux);
                                }
                            } else if (tamVet == "50000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K5.desempenho50000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K5.desempenho50000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K5.tempo50000 += stod(aux);
                                }
                            } else if (tamVet == "100000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K5.desempenho100000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K5.desempenho100000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K5.tempo100000 += stod(aux);
                                }
                            } else if (tamVet == "500000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K5.desempenho500000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K5.desempenho500000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K5.tempo500000 += stod(aux);
                                }
                            } else if (tamVet == "1000000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K5.desempenho1000000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K5.desempenho1000000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K5.tempo1000000 += stod(aux);
                                }
                            }
                            comand = aux;
                        }
                    } else {
                        while (arquivoAtual >> aux) {
                            if (comand == "Vet.:") {
                                tamVet = aux;
                            }
                            if (tamVet == "1000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K7.desempenho1000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K7.desempenho1000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K7.tempo1000 += stod(aux);
                                }
                            } else if (tamVet == "5000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K7.desempenho5000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K7.desempenho5000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K7.tempo5000 += stod(aux);
                                }
                            } else if (tamVet == "10000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K7.desempenho10000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K7.desempenho10000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K7.tempo10000 += stod(aux);
                                }
                            } else if (tamVet == "50000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K7.desempenho50000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K7.desempenho50000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K7.tempo50000 += stod(aux);
                                }
                            } else if (tamVet == "100000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K7.desempenho100000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K7.desempenho100000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K7.tempo100000 += stod(aux);
                                }
                            } else if (tamVet == "500000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K7.desempenho500000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K7.desempenho500000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K7.tempo500000 += stod(aux);
                                }
                            } else if (tamVet == "1000000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV2K7.desempenho1000000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV2K7.desempenho1000000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV2K7.tempo1000000 += stod(aux);
                                }
                            }
                            comand = aux;
                        }
                    }
                    arquivoAtual.close();
                }
            } else if (v == 3) {
                for (int m = 0; m < 2; m++) {
                    string nomeArquivo = "saidaV" + to_string(v) + "S" + to_string(sementes[s]) + "M" + to_string(valorM[m]) + ".txt";
                    arquivoAtual.open(nomeArquivo);
                    string aux, comand, tamVet;
                    arquivoAtual >> aux;
                    comand = aux;
                    if (m == 0) {
                        while (arquivoAtual >> aux) {
                            if (comand == "Vet.:") {
                                tamVet = aux;
                            }
                            if (tamVet == "1000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M10.desempenho1000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M10.desempenho1000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M10.tempo1000 += stod(aux);
                                }
                            } else if (tamVet == "5000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M10.desempenho5000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M10.desempenho5000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M10.tempo5000 += stod(aux);
                                }
                            } else if (tamVet == "10000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M10.desempenho10000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M10.desempenho10000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M10.tempo10000 += stod(aux);
                                }
                            } else if (tamVet == "50000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M10.desempenho50000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M10.desempenho50000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M10.tempo50000 += stod(aux);
                                }
                            } else if (tamVet == "100000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M10.desempenho100000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M10.desempenho100000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M10.tempo100000 += stod(aux);
                                }
                            } else if (tamVet == "500000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M10.desempenho500000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M10.desempenho500000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M10.tempo500000 += stod(aux);
                                }
                            } else if (tamVet == "1000000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M10.desempenho1000000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M10.desempenho1000000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M10.tempo1000000 += stod(aux);
                                }
                            }
                            comand = aux;
                        }
                    } else {
                        while (arquivoAtual >> aux) {
                            if (comand == "Vet.:") {
                                tamVet = aux;
                            }
                            if (tamVet == "1000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M100.desempenho1000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M100.desempenho1000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M100.tempo1000 += stod(aux);
                                }
                            } else if (tamVet == "5000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M100.desempenho5000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M100.desempenho5000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M100.tempo5000 += stod(aux);
                                }
                            } else if (tamVet == "10000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M100.desempenho10000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M100.desempenho10000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M100.tempo10000 += stod(aux);
                                }
                            } else if (tamVet == "50000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M100.desempenho50000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M100.desempenho50000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M100.tempo50000 += stod(aux);
                                }
                            } else if (tamVet == "100000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M100.desempenho100000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M100.desempenho100000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M100.tempo100000 += stod(aux);
                                }
                            } else if (tamVet == "500000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M100.desempenho500000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M100.desempenho500000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M100.tempo500000 += stod(aux);
                                }
                            } else if (tamVet == "1000000") {
                                if (comand == "Comparacoes:") {
                                    desempContblzdV3M100.desempenho1000000.comparacoes += stoi(aux);
                                } else if (comand == "Copias:") {
                                    desempContblzdV3M100.desempenho1000000.copias += stoi(aux);
                                }else if (comand == "Tot:") {
                                    desempContblzdV3M100.tempo1000000 += stod(aux);
                                }
                            }
                            comand = aux;
                        }
                    }
                    arquivoAtual.close();
                }
            } else if (v == 4) {
                string nomeArquivo = "saidaV" + to_string(v) + "S" + to_string(sementes[s]) + ".txt";
                arquivoAtual.open(nomeArquivo);
                string aux, comand, tamVet;
                arquivoAtual >> aux;
                comand = aux;
                while (arquivoAtual >> aux) {
                    if (comand == "Vet.:") {
                        tamVet = aux;
                    }
                    if (tamVet == "1000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV4.desempenho1000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV4.desempenho1000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV4.tempo1000 += stod(aux);
                        }
                    } else if (tamVet == "5000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV4.desempenho5000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV4.desempenho5000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV4.tempo5000 += stod(aux);
                        }
                    } else if (tamVet == "10000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV4.desempenho10000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV4.desempenho10000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV4.tempo10000 += stod(aux);
                        }
                    } else if (tamVet == "50000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV4.desempenho50000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV4.desempenho50000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV4.tempo50000 += stod(aux);
                        }
                    } else if (tamVet == "100000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV4.desempenho100000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV4.desempenho100000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV4.tempo100000 += stod(aux);
                        }
                    } else if (tamVet == "500000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV4.desempenho500000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV4.desempenho500000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV4.tempo500000 += stod(aux);
                        }
                    } else if (tamVet == "1000000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV4.desempenho1000000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV4.desempenho1000000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV4.tempo1000000 += stod(aux);
                        }
                    }
                    comand = aux;
                }
                arquivoAtual.close();
            } else if (v == 5) {
                string nomeArquivo = "saidaV" + to_string(v) + "S" + to_string(sementes[s]) + ".txt";
                arquivoAtual.open(nomeArquivo);
                string aux, comand, tamVet;
                arquivoAtual >> aux;
                comand = aux;
                while (arquivoAtual >> aux) {
                    if (comand == "Vet.:") {
                        tamVet = aux;
                    }
                    if (tamVet == "1000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV5.desempenho1000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV5.desempenho1000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV5.tempo1000 += stod(aux);
                        }
                    } else if (tamVet == "5000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV5.desempenho5000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV5.desempenho5000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV5.tempo5000 += stod(aux);
                        }
                    } else if (tamVet == "10000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV5.desempenho10000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV5.desempenho10000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV5.tempo10000 += stod(aux);
                        }
                    } else if (tamVet == "50000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV5.desempenho50000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV5.desempenho50000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV5.tempo50000 += stod(aux);
                        }
                    } else if (tamVet == "100000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV5.desempenho100000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV5.desempenho100000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV5.tempo100000 += stod(aux);
                        }
                    } else if (tamVet == "500000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV5.desempenho500000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV5.desempenho500000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV5.tempo500000 += stod(aux);
                        }
                    } else if (tamVet == "1000000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdV5.desempenho1000000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdV5.desempenho1000000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdV5.tempo1000000 += stod(aux);
                        }
                    }
                    comand = aux;
                }
                arquivoAtual.close();
            } else if (v == 6) {
                string nomeArquivo = "saidaMergeS" + to_string(sementes[s]) + ".txt";
                arquivoAtual.open(nomeArquivo);
                string aux, comand, tamVet;
                arquivoAtual >> aux;
                comand = aux;
                while (arquivoAtual >> aux) {
                    if (comand == "Vet.:") {
                        tamVet = aux;
                    }
                    if (tamVet == "1000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdMerge.desempenho1000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdMerge.desempenho1000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdMerge.tempo1000 += stod(aux);
                        }
                    } else if (tamVet == "5000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdMerge.desempenho5000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdMerge.desempenho5000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdMerge.tempo5000 += stod(aux);
                        }
                    } else if (tamVet == "10000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdMerge.desempenho10000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdMerge.desempenho10000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdMerge.tempo10000 += stod(aux);
                        }
                    } else if (tamVet == "50000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdMerge.desempenho50000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdMerge.desempenho50000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdMerge.tempo50000 += stod(aux);
                        }
                    } else if (tamVet == "100000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdMerge.desempenho100000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdMerge.desempenho100000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdMerge.tempo100000 += stod(aux);
                        }
                    } else if (tamVet == "500000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdMerge.desempenho500000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdMerge.desempenho500000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdMerge.tempo500000 += stod(aux);
                        }
                    } else if (tamVet == "1000000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdMerge.desempenho1000000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdMerge.desempenho1000000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdMerge.tempo1000000 += stod(aux);
                        }
                    }
                    comand = aux;
                }
                arquivoAtual.close();
            } else if (v == 7) {
                string nomeArquivo = "saidaHeapS" + to_string(sementes[s]) + ".txt";
                arquivoAtual.open(nomeArquivo);
                string aux, comand, tamVet;
                arquivoAtual >> aux;
                comand = aux;
                while (arquivoAtual >> aux) {
                    if (comand == "Vet.:") {
                        tamVet = aux;
                    }
                    if (tamVet == "1000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdHeap.desempenho1000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdHeap.desempenho1000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdHeap.tempo1000 += stod(aux);
                        }
                    } else if (tamVet == "5000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdHeap.desempenho5000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdHeap.desempenho5000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdHeap.tempo5000 += stod(aux);
                        }
                    } else if (tamVet == "10000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdHeap.desempenho10000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdHeap.desempenho10000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdHeap.tempo10000 += stod(aux);
                        }
                    } else if (tamVet == "50000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdHeap.desempenho50000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdHeap.desempenho50000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdHeap.tempo50000 += stod(aux);
                        }
                    } else if (tamVet == "100000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdHeap.desempenho100000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdHeap.desempenho100000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdHeap.tempo100000 += stod(aux);
                        }
                    } else if (tamVet == "500000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdHeap.desempenho500000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdHeap.desempenho500000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdHeap.tempo500000 += stod(aux);
                        }
                    } else if (tamVet == "1000000") {
                        if (comand == "Comparacoes:") {
                            desempContblzdHeap.desempenho1000000.comparacoes += stoi(aux);
                        } else if (comand == "Copias:") {
                            desempContblzdHeap.desempenho1000000.copias += stoi(aux);
                        }else if (comand == "Tot:") {
                            desempContblzdHeap.tempo1000000 += stod(aux);
                        }
                    }
                    comand = aux;
                }
                arquivoAtual.close();
            }
        }
    }
    
    desempContblzdV1.tempo1000 = desempContblzdV1.tempo1000 / numeroDeSementes;
    desempContblzdV2K3.tempo1000 = desempContblzdV2K3.tempo1000 / numeroDeSementes;
    desempContblzdV2K5.tempo1000 = desempContblzdV2K5.tempo1000 / numeroDeSementes;
    desempContblzdV2K7.tempo1000 = desempContblzdV2K7.tempo1000 / numeroDeSementes;
    desempContblzdV3M10.tempo1000 = desempContblzdV3M10.tempo1000 / numeroDeSementes;
    desempContblzdV3M100.tempo1000 = desempContblzdV3M100.tempo1000 / numeroDeSementes;
    desempContblzdV4.tempo1000 = desempContblzdV4.tempo1000 / numeroDeSementes;
    desempContblzdV5.tempo1000 = desempContblzdV5.tempo1000 / numeroDeSementes;
    desempContblzdMerge.tempo1000 = desempContblzdMerge.tempo1000 / numeroDeSementes;
    desempContblzdHeap.tempo1000 = desempContblzdHeap.tempo1000 / numeroDeSementes;

    desempContblzdV1.tempo5000 = desempContblzdV1.tempo5000 / numeroDeSementes;
    desempContblzdV2K3.tempo5000 = desempContblzdV2K3.tempo5000 / numeroDeSementes;
    desempContblzdV2K5.tempo5000 = desempContblzdV2K5.tempo5000 / numeroDeSementes;
    desempContblzdV2K7.tempo5000 = desempContblzdV2K7.tempo5000 / numeroDeSementes;
    desempContblzdV3M10.tempo5000 = desempContblzdV3M10.tempo5000 / numeroDeSementes;
    desempContblzdV3M100.tempo5000 = desempContblzdV3M100.tempo5000 / numeroDeSementes;
    desempContblzdV4.tempo5000 = desempContblzdV4.tempo5000 / numeroDeSementes;
    desempContblzdV5.tempo5000 = desempContblzdV5.tempo5000 / numeroDeSementes;
    desempContblzdMerge.tempo5000 = desempContblzdMerge.tempo5000 / numeroDeSementes;
    desempContblzdHeap.tempo5000 = desempContblzdHeap.tempo5000 / numeroDeSementes;

    desempContblzdV1.tempo10000 = desempContblzdV1.tempo10000 / numeroDeSementes;
    desempContblzdV2K3.tempo10000 = desempContblzdV2K3.tempo10000 / numeroDeSementes;
    desempContblzdV2K5.tempo10000 = desempContblzdV2K5.tempo10000 / numeroDeSementes;
    desempContblzdV2K7.tempo10000 = desempContblzdV2K7.tempo10000 / numeroDeSementes;
    desempContblzdV3M10.tempo10000 = desempContblzdV3M10.tempo10000 / numeroDeSementes;
    desempContblzdV3M100.tempo10000 = desempContblzdV3M100.tempo10000 / numeroDeSementes;
    desempContblzdV4.tempo10000 = desempContblzdV4.tempo10000 / numeroDeSementes;
    desempContblzdV5.tempo10000 = desempContblzdV5.tempo10000 / numeroDeSementes;
    desempContblzdMerge.tempo10000 = desempContblzdMerge.tempo10000 / numeroDeSementes;
    desempContblzdHeap.tempo10000 = desempContblzdHeap.tempo10000 / numeroDeSementes;

    desempContblzdV1.tempo50000 = desempContblzdV1.tempo50000 / numeroDeSementes;
    desempContblzdV2K3.tempo50000 = desempContblzdV2K3.tempo50000 / numeroDeSementes;
    desempContblzdV2K5.tempo50000 = desempContblzdV2K5.tempo50000 / numeroDeSementes;
    desempContblzdV2K7.tempo50000 = desempContblzdV2K7.tempo50000 / numeroDeSementes;
    desempContblzdV3M10.tempo50000 = desempContblzdV3M10.tempo50000 / numeroDeSementes;
    desempContblzdV3M100.tempo50000 = desempContblzdV3M100.tempo50000 / numeroDeSementes;
    desempContblzdV4.tempo50000 = desempContblzdV4.tempo50000 / numeroDeSementes;
    desempContblzdV5.tempo50000 = desempContblzdV5.tempo50000 / numeroDeSementes;
    desempContblzdMerge.tempo50000 = desempContblzdMerge.tempo50000 / numeroDeSementes;
    desempContblzdHeap.tempo50000 = desempContblzdHeap.tempo50000 / numeroDeSementes;

    desempContblzdV1.tempo100000 = desempContblzdV1.tempo100000 / numeroDeSementes;
    desempContblzdV2K3.tempo100000 = desempContblzdV2K3.tempo100000 / numeroDeSementes;
    desempContblzdV2K5.tempo100000 = desempContblzdV2K5.tempo100000 / numeroDeSementes;
    desempContblzdV2K7.tempo100000 = desempContblzdV2K7.tempo100000 / numeroDeSementes;
    desempContblzdV3M10.tempo100000 = desempContblzdV3M10.tempo100000 / numeroDeSementes;
    desempContblzdV3M100.tempo100000 = desempContblzdV3M100.tempo100000 / numeroDeSementes;
    desempContblzdV4.tempo100000 = desempContblzdV4.tempo100000 / numeroDeSementes;
    desempContblzdV5.tempo100000 = desempContblzdV5.tempo100000 / numeroDeSementes;
    desempContblzdMerge.tempo100000 = desempContblzdMerge.tempo100000 / numeroDeSementes;
    desempContblzdHeap.tempo100000 = desempContblzdHeap.tempo100000 / numeroDeSementes;

    desempContblzdV1.tempo500000 = desempContblzdV1.tempo500000 / numeroDeSementes;
    desempContblzdV2K3.tempo500000 = desempContblzdV2K3.tempo500000 / numeroDeSementes;
    desempContblzdV2K5.tempo500000 = desempContblzdV2K5.tempo500000 / numeroDeSementes;
    desempContblzdV2K7.tempo500000 = desempContblzdV2K7.tempo500000 / numeroDeSementes;
    desempContblzdV3M10.tempo500000 = desempContblzdV3M10.tempo500000 / numeroDeSementes;
    desempContblzdV3M100.tempo500000 = desempContblzdV3M100.tempo500000 / numeroDeSementes;
    desempContblzdV4.tempo500000 = desempContblzdV4.tempo500000 / numeroDeSementes;
    desempContblzdV5.tempo500000 = desempContblzdV5.tempo500000 / numeroDeSementes;
    desempContblzdMerge.tempo500000 = desempContblzdMerge.tempo500000 / numeroDeSementes;
    desempContblzdHeap.tempo500000 = desempContblzdHeap.tempo500000 / numeroDeSementes;

    desempContblzdV1.tempo1000000 = desempContblzdV1.tempo1000000 / numeroDeSementes;
    desempContblzdV2K3.tempo1000000 = desempContblzdV2K3.tempo1000000 / numeroDeSementes;
    desempContblzdV2K5.tempo1000000 = desempContblzdV2K5.tempo1000000 / numeroDeSementes;
    desempContblzdV2K7.tempo1000000 = desempContblzdV2K7.tempo1000000 / numeroDeSementes;
    desempContblzdV3M10.tempo1000000 = desempContblzdV3M10.tempo1000000 / numeroDeSementes;
    desempContblzdV3M100.tempo1000000 = desempContblzdV3M100.tempo1000000 / numeroDeSementes;
    desempContblzdV4.tempo1000000 = desempContblzdV4.tempo1000000 / numeroDeSementes;
    desempContblzdV5.tempo1000000 = desempContblzdV5.tempo1000000 / numeroDeSementes;
    desempContblzdMerge.tempo1000000 = desempContblzdMerge.tempo1000000 / numeroDeSementes;
    desempContblzdHeap.tempo1000000 = desempContblzdHeap.tempo1000000 / numeroDeSementes;

    desempContblzdV1.desempenho1000.comparacoes = desempContblzdV1.desempenho1000.comparacoes / numeroDeSementes;
    desempContblzdV2K3.desempenho1000.comparacoes = desempContblzdV2K3.desempenho1000.comparacoes / numeroDeSementes;
    desempContblzdV2K5.desempenho1000.comparacoes = desempContblzdV2K5.desempenho1000.comparacoes / numeroDeSementes;
    desempContblzdV2K7.desempenho1000.comparacoes = desempContblzdV2K7.desempenho1000.comparacoes / numeroDeSementes;
    desempContblzdV3M10.desempenho1000.comparacoes = desempContblzdV3M10.desempenho1000.comparacoes / numeroDeSementes;
    desempContblzdV3M100.desempenho1000.comparacoes = desempContblzdV3M100.desempenho1000.comparacoes / numeroDeSementes;
    desempContblzdV4.desempenho1000.comparacoes = desempContblzdV4.desempenho1000.comparacoes / numeroDeSementes;
    desempContblzdV5.desempenho1000.comparacoes = desempContblzdV5.desempenho1000.comparacoes / numeroDeSementes;
    desempContblzdMerge.desempenho1000.comparacoes = desempContblzdMerge.desempenho1000.comparacoes / numeroDeSementes;
    desempContblzdHeap.desempenho1000.comparacoes = desempContblzdHeap.desempenho1000.comparacoes / numeroDeSementes;

    desempContblzdV1.desempenho5000.comparacoes = desempContblzdV1.desempenho5000.comparacoes / numeroDeSementes;
    desempContblzdV2K3.desempenho5000.comparacoes = desempContblzdV2K3.desempenho5000.comparacoes / numeroDeSementes;
    desempContblzdV2K5.desempenho5000.comparacoes = desempContblzdV2K5.desempenho5000.comparacoes / numeroDeSementes;
    desempContblzdV2K7.desempenho5000.comparacoes = desempContblzdV2K7.desempenho5000.comparacoes / numeroDeSementes;
    desempContblzdV3M10.desempenho5000.comparacoes = desempContblzdV3M10.desempenho5000.comparacoes / numeroDeSementes;
    desempContblzdV3M100.desempenho5000.comparacoes = desempContblzdV3M100.desempenho5000.comparacoes / numeroDeSementes;
    desempContblzdV4.desempenho5000.comparacoes = desempContblzdV4.desempenho5000.comparacoes / numeroDeSementes;
    desempContblzdV5.desempenho5000.comparacoes = desempContblzdV5.desempenho5000.comparacoes / numeroDeSementes;
    desempContblzdMerge.desempenho5000.comparacoes = desempContblzdMerge.desempenho5000.comparacoes / numeroDeSementes;
    desempContblzdHeap.desempenho5000.comparacoes = desempContblzdHeap.desempenho5000.comparacoes / numeroDeSementes;

    desempContblzdV1.desempenho10000.comparacoes = desempContblzdV1.desempenho10000.comparacoes / numeroDeSementes;
    desempContblzdV2K3.desempenho10000.comparacoes = desempContblzdV2K3.desempenho10000.comparacoes / numeroDeSementes;
    desempContblzdV2K5.desempenho10000.comparacoes = desempContblzdV2K5.desempenho10000.comparacoes / numeroDeSementes;
    desempContblzdV2K7.desempenho10000.comparacoes = desempContblzdV2K7.desempenho10000.comparacoes / numeroDeSementes;
    desempContblzdV3M10.desempenho10000.comparacoes = desempContblzdV3M10.desempenho10000.comparacoes / numeroDeSementes;
    desempContblzdV3M100.desempenho10000.comparacoes = desempContblzdV3M100.desempenho10000.comparacoes / numeroDeSementes;
    desempContblzdV4.desempenho10000.comparacoes = desempContblzdV4.desempenho10000.comparacoes / numeroDeSementes;
    desempContblzdV5.desempenho10000.comparacoes = desempContblzdV5.desempenho10000.comparacoes / numeroDeSementes;
    desempContblzdMerge.desempenho10000.comparacoes = desempContblzdMerge.desempenho10000.comparacoes / numeroDeSementes;
    desempContblzdHeap.desempenho10000.comparacoes = desempContblzdHeap.desempenho10000.comparacoes / numeroDeSementes;

    desempContblzdV1.desempenho50000.comparacoes = desempContblzdV1.desempenho50000.comparacoes / numeroDeSementes;
    desempContblzdV2K3.desempenho50000.comparacoes = desempContblzdV2K3.desempenho50000.comparacoes / numeroDeSementes;
    desempContblzdV2K5.desempenho50000.comparacoes = desempContblzdV2K5.desempenho50000.comparacoes / numeroDeSementes;
    desempContblzdV2K7.desempenho50000.comparacoes = desempContblzdV2K7.desempenho50000.comparacoes / numeroDeSementes;
    desempContblzdV3M10.desempenho50000.comparacoes = desempContblzdV3M10.desempenho50000.comparacoes / numeroDeSementes;
    desempContblzdV3M100.desempenho50000.comparacoes = desempContblzdV3M100.desempenho50000.comparacoes / numeroDeSementes;
    desempContblzdV4.desempenho50000.comparacoes = desempContblzdV4.desempenho50000.comparacoes / numeroDeSementes;
    desempContblzdV5.desempenho50000.comparacoes = desempContblzdV5.desempenho50000.comparacoes / numeroDeSementes;
    desempContblzdMerge.desempenho50000.comparacoes = desempContblzdMerge.desempenho50000.comparacoes / numeroDeSementes;
    desempContblzdHeap.desempenho50000.comparacoes = desempContblzdHeap.desempenho50000.comparacoes / numeroDeSementes;

    desempContblzdV1.desempenho100000.comparacoes = desempContblzdV1.desempenho100000.comparacoes / numeroDeSementes;
    desempContblzdV2K3.desempenho100000.comparacoes = desempContblzdV2K3.desempenho100000.comparacoes / numeroDeSementes;
    desempContblzdV2K5.desempenho100000.comparacoes = desempContblzdV2K5.desempenho100000.comparacoes / numeroDeSementes;
    desempContblzdV2K7.desempenho100000.comparacoes = desempContblzdV2K7.desempenho100000.comparacoes / numeroDeSementes;
    desempContblzdV3M10.desempenho100000.comparacoes = desempContblzdV3M10.desempenho100000.comparacoes / numeroDeSementes;
    desempContblzdV3M100.desempenho100000.comparacoes = desempContblzdV3M100.desempenho100000.comparacoes / numeroDeSementes;
    desempContblzdV4.desempenho100000.comparacoes = desempContblzdV4.desempenho100000.comparacoes / numeroDeSementes;
    desempContblzdV5.desempenho100000.comparacoes = desempContblzdV5.desempenho100000.comparacoes / numeroDeSementes;
    desempContblzdMerge.desempenho100000.comparacoes = desempContblzdMerge.desempenho100000.comparacoes / numeroDeSementes;
    desempContblzdHeap.desempenho100000.comparacoes = desempContblzdHeap.desempenho100000.comparacoes / numeroDeSementes;

    desempContblzdV1.desempenho500000.comparacoes = desempContblzdV1.desempenho500000.comparacoes / numeroDeSementes;
    desempContblzdV2K3.desempenho500000.comparacoes = desempContblzdV2K3.desempenho500000.comparacoes / numeroDeSementes;
    desempContblzdV2K5.desempenho500000.comparacoes = desempContblzdV2K5.desempenho500000.comparacoes / numeroDeSementes;
    desempContblzdV2K7.desempenho500000.comparacoes = desempContblzdV2K7.desempenho500000.comparacoes / numeroDeSementes;
    desempContblzdV3M10.desempenho500000.comparacoes = desempContblzdV3M10.desempenho500000.comparacoes / numeroDeSementes;
    desempContblzdV3M100.desempenho500000.comparacoes = desempContblzdV3M100.desempenho500000.comparacoes / numeroDeSementes;
    desempContblzdV4.desempenho500000.comparacoes = desempContblzdV4.desempenho500000.comparacoes / numeroDeSementes;
    desempContblzdV5.desempenho500000.comparacoes = desempContblzdV5.desempenho500000.comparacoes / numeroDeSementes;
    desempContblzdMerge.desempenho500000.comparacoes = desempContblzdMerge.desempenho500000.comparacoes / numeroDeSementes;
    desempContblzdHeap.desempenho500000.comparacoes = desempContblzdHeap.desempenho500000.comparacoes / numeroDeSementes;

    desempContblzdV1.desempenho1000000.comparacoes = desempContblzdV1.desempenho1000000.comparacoes / numeroDeSementes;
    desempContblzdV2K3.desempenho1000000.comparacoes = desempContblzdV2K3.desempenho1000000.comparacoes / numeroDeSementes;
    desempContblzdV2K5.desempenho1000000.comparacoes = desempContblzdV2K5.desempenho1000000.comparacoes / numeroDeSementes;
    desempContblzdV2K7.desempenho1000000.comparacoes = desempContblzdV2K7.desempenho1000000.comparacoes / numeroDeSementes;
    desempContblzdV3M10.desempenho1000000.comparacoes = desempContblzdV3M10.desempenho1000000.comparacoes / numeroDeSementes;
    desempContblzdV3M100.desempenho1000000.comparacoes = desempContblzdV3M100.desempenho1000000.comparacoes / numeroDeSementes;
    desempContblzdV4.desempenho1000000.comparacoes = desempContblzdV4.desempenho1000000.comparacoes / numeroDeSementes;
    desempContblzdV5.desempenho1000000.comparacoes = desempContblzdV5.desempenho1000000.comparacoes / numeroDeSementes;
    desempContblzdMerge.desempenho1000000.comparacoes = desempContblzdMerge.desempenho1000000.comparacoes / numeroDeSementes;
    desempContblzdHeap.desempenho1000000.comparacoes = desempContblzdHeap.desempenho1000000.comparacoes / numeroDeSementes;
    


    

    desempContblzdV1.desempenho1000.copias = desempContblzdV1.desempenho1000.copias / numeroDeSementes;
    desempContblzdV2K3.desempenho1000.copias = desempContblzdV2K3.desempenho1000.copias / numeroDeSementes;
    desempContblzdV2K5.desempenho1000.copias = desempContblzdV2K5.desempenho1000.copias / numeroDeSementes;
    desempContblzdV2K7.desempenho1000.copias = desempContblzdV2K7.desempenho1000.copias / numeroDeSementes;
    desempContblzdV3M10.desempenho1000.copias = desempContblzdV3M10.desempenho1000.copias / numeroDeSementes;
    desempContblzdV3M100.desempenho1000.copias = desempContblzdV3M100.desempenho1000.copias / numeroDeSementes;
    desempContblzdV4.desempenho1000.copias = desempContblzdV4.desempenho1000.copias / numeroDeSementes;
    desempContblzdV5.desempenho1000.copias = desempContblzdV5.desempenho1000.copias / numeroDeSementes;
    desempContblzdMerge.desempenho1000.copias = desempContblzdMerge.desempenho1000.copias / numeroDeSementes;
    desempContblzdHeap.desempenho1000.copias = desempContblzdHeap.desempenho1000.copias / numeroDeSementes;

    desempContblzdV1.desempenho5000.copias = desempContblzdV1.desempenho5000.copias / numeroDeSementes;
    desempContblzdV2K3.desempenho5000.copias = desempContblzdV2K3.desempenho5000.copias / numeroDeSementes;
    desempContblzdV2K5.desempenho5000.copias = desempContblzdV2K5.desempenho5000.copias / numeroDeSementes;
    desempContblzdV2K7.desempenho5000.copias = desempContblzdV2K7.desempenho5000.copias / numeroDeSementes;
    desempContblzdV3M10.desempenho5000.copias = desempContblzdV3M10.desempenho5000.copias / numeroDeSementes;
    desempContblzdV3M100.desempenho5000.copias = desempContblzdV3M100.desempenho5000.copias / numeroDeSementes;
    desempContblzdV4.desempenho5000.copias = desempContblzdV4.desempenho5000.copias / numeroDeSementes;
    desempContblzdV5.desempenho5000.copias = desempContblzdV5.desempenho5000.copias / numeroDeSementes;
    desempContblzdMerge.desempenho5000.copias = desempContblzdMerge.desempenho5000.copias / numeroDeSementes;
    desempContblzdHeap.desempenho5000.copias = desempContblzdHeap.desempenho5000.copias / numeroDeSementes;

    desempContblzdV1.desempenho10000.copias = desempContblzdV1.desempenho10000.copias / numeroDeSementes;
    desempContblzdV2K3.desempenho10000.copias = desempContblzdV2K3.desempenho10000.copias / numeroDeSementes;
    desempContblzdV2K5.desempenho10000.copias = desempContblzdV2K5.desempenho10000.copias / numeroDeSementes;
    desempContblzdV2K7.desempenho10000.copias = desempContblzdV2K7.desempenho10000.copias / numeroDeSementes;
    desempContblzdV3M10.desempenho10000.copias = desempContblzdV3M10.desempenho10000.copias / numeroDeSementes;
    desempContblzdV3M100.desempenho10000.copias = desempContblzdV3M100.desempenho10000.copias / numeroDeSementes;
    desempContblzdV4.desempenho10000.copias = desempContblzdV4.desempenho10000.copias / numeroDeSementes;
    desempContblzdV5.desempenho10000.copias = desempContblzdV5.desempenho10000.copias / numeroDeSementes;
    desempContblzdMerge.desempenho10000.copias = desempContblzdMerge.desempenho10000.copias / numeroDeSementes;
    desempContblzdHeap.desempenho10000.copias = desempContblzdHeap.desempenho10000.copias / numeroDeSementes;

    desempContblzdV1.desempenho50000.copias = desempContblzdV1.desempenho50000.copias / numeroDeSementes;
    desempContblzdV2K3.desempenho50000.copias = desempContblzdV2K3.desempenho50000.copias / numeroDeSementes;
    desempContblzdV2K5.desempenho50000.copias = desempContblzdV2K5.desempenho50000.copias / numeroDeSementes;
    desempContblzdV2K7.desempenho50000.copias = desempContblzdV2K7.desempenho50000.copias / numeroDeSementes;
    desempContblzdV3M10.desempenho50000.copias = desempContblzdV3M10.desempenho50000.copias / numeroDeSementes;
    desempContblzdV3M100.desempenho50000.copias = desempContblzdV3M100.desempenho50000.copias / numeroDeSementes;
    desempContblzdV4.desempenho50000.copias = desempContblzdV4.desempenho50000.copias / numeroDeSementes;
    desempContblzdV5.desempenho50000.copias = desempContblzdV5.desempenho50000.copias / numeroDeSementes;
    desempContblzdMerge.desempenho50000.copias = desempContblzdMerge.desempenho50000.copias / numeroDeSementes;
    desempContblzdHeap.desempenho50000.copias = desempContblzdHeap.desempenho50000.copias / numeroDeSementes;

    desempContblzdV1.desempenho100000.copias = desempContblzdV1.desempenho100000.copias / numeroDeSementes;
    desempContblzdV2K3.desempenho100000.copias = desempContblzdV2K3.desempenho100000.copias / numeroDeSementes;
    desempContblzdV2K5.desempenho100000.copias = desempContblzdV2K5.desempenho100000.copias / numeroDeSementes;
    desempContblzdV2K7.desempenho100000.copias = desempContblzdV2K7.desempenho100000.copias / numeroDeSementes;
    desempContblzdV3M10.desempenho100000.copias = desempContblzdV3M10.desempenho100000.copias / numeroDeSementes;
    desempContblzdV3M100.desempenho100000.copias = desempContblzdV3M100.desempenho100000.copias / numeroDeSementes;
    desempContblzdV4.desempenho100000.copias = desempContblzdV4.desempenho100000.copias / numeroDeSementes;
    desempContblzdV5.desempenho100000.copias = desempContblzdV5.desempenho100000.copias / numeroDeSementes;
    desempContblzdMerge.desempenho100000.copias = desempContblzdMerge.desempenho100000.copias / numeroDeSementes;
    desempContblzdHeap.desempenho100000.copias = desempContblzdHeap.desempenho100000.copias / numeroDeSementes;

    desempContblzdV1.desempenho500000.copias = desempContblzdV1.desempenho500000.copias / numeroDeSementes;
    desempContblzdV2K3.desempenho500000.copias = desempContblzdV2K3.desempenho500000.copias / numeroDeSementes;
    desempContblzdV2K5.desempenho500000.copias = desempContblzdV2K5.desempenho500000.copias / numeroDeSementes;
    desempContblzdV2K7.desempenho500000.copias = desempContblzdV2K7.desempenho500000.copias / numeroDeSementes;
    desempContblzdV3M10.desempenho500000.copias = desempContblzdV3M10.desempenho500000.copias / numeroDeSementes;
    desempContblzdV3M100.desempenho500000.copias = desempContblzdV3M100.desempenho500000.copias / numeroDeSementes;
    desempContblzdV4.desempenho500000.copias = desempContblzdV4.desempenho500000.copias / numeroDeSementes;
    desempContblzdV5.desempenho500000.copias = desempContblzdV5.desempenho500000.copias / numeroDeSementes;
    desempContblzdMerge.desempenho500000.copias = desempContblzdMerge.desempenho500000.copias / numeroDeSementes;
    desempContblzdHeap.desempenho500000.copias = desempContblzdHeap.desempenho500000.copias / numeroDeSementes;

    desempContblzdV1.desempenho1000000.copias = desempContblzdV1.desempenho1000000.copias / numeroDeSementes;
    desempContblzdV2K3.desempenho1000000.copias = desempContblzdV2K3.desempenho1000000.copias / numeroDeSementes;
    desempContblzdV2K5.desempenho1000000.copias = desempContblzdV2K5.desempenho1000000.copias / numeroDeSementes;
    desempContblzdV2K7.desempenho1000000.copias = desempContblzdV2K7.desempenho1000000.copias / numeroDeSementes;
    desempContblzdV3M10.desempenho1000000.copias = desempContblzdV3M10.desempenho1000000.copias / numeroDeSementes;
    desempContblzdV3M100.desempenho1000000.copias = desempContblzdV3M100.desempenho1000000.copias / numeroDeSementes;
    desempContblzdV4.desempenho1000000.copias = desempContblzdV4.desempenho1000000.copias / numeroDeSementes;
    desempContblzdV5.desempenho1000000.copias = desempContblzdV5.desempenho1000000.copias / numeroDeSementes;
    desempContblzdMerge.desempenho1000000.copias = desempContblzdMerge.desempenho1000000.copias / numeroDeSementes;
    desempContblzdHeap.desempenho1000000.copias = desempContblzdHeap.desempenho1000000.copias / numeroDeSementes;

    ofstream arquivoResultado;
    arquivoResultado.open("RESULTADO.txt");

    arquivoResultado << "Medias de desempenho vetor N = 1000" << endl;
    arquivoResultado << "____________________________________" << endl;
    arquivoResultado << endl;
    arquivoResultado << "Quicksort: Recursivo | Num. Comparacoes: " << desempContblzdV1.desempenho1000.comparacoes << " | Num. Copias: " << desempContblzdV1.desempenho1000.copias << " | Temp. Tot: " << desempContblzdV1.tempo1000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 3 | Num. Comparacoes: " << desempContblzdV2K3.desempenho1000.comparacoes << " | Num. Copias: " << desempContblzdV2K3.desempenho1000.copias << " | Temp. Tot: " << desempContblzdV2K3.tempo1000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 5 | Num. Comparacoes: " << desempContblzdV2K5.desempenho1000.comparacoes << " | Num. Copias: " << desempContblzdV2K5.desempenho1000.copias << " | Temp. Tot: " << desempContblzdV2K5.tempo1000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 7 | Num. Comparacoes: " << desempContblzdV2K7.desempenho1000.comparacoes << " | Num. Copias: " << desempContblzdV2K7.desempenho1000.copias << " | Temp. Tot: " << desempContblzdV2K7.tempo1000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 10 | Num. Comparacoes: " << desempContblzdV3M10.desempenho1000.comparacoes << " | Num. Copias: " << desempContblzdV3M10.desempenho1000.copias << " | Temp. Tot: " << desempContblzdV3M10.tempo1000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 100 | Num. Comparacoes: " << desempContblzdV3M100.desempenho1000.comparacoes << " | Num. Copias: " << desempContblzdV3M100.desempenho1000.copias << " | Temp. Tot: " << desempContblzdV3M100.tempo1000 << " |" << endl;
    arquivoResultado << "Quicksort: Nao Recursivo | Num. Comparacoes: " << desempContblzdV4.desempenho1000.comparacoes << " | Num. Copias: " << desempContblzdV4.desempenho1000.copias << " | Temp. Tot: " << desempContblzdV4.tempo1000 << " |" << endl;
    arquivoResultado << "Quicksort: Empilha Inteligente | Num. Comparacoes: " << desempContblzdV5.desempenho1000.comparacoes << " | Num. Copias: " << desempContblzdV5.desempenho1000.copias << " | Temp. Tot: " << desempContblzdV5.tempo1000 << " |" << endl;
    arquivoResultado << "Quicksort: Mergesort | Num. Comparacoes: " << desempContblzdMerge.desempenho1000.comparacoes << " | Num. Copias: " << desempContblzdMerge.desempenho1000.copias << " | Temp. Tot: " << desempContblzdMerge.tempo1000 << " |" << endl;
    arquivoResultado << "Quicksort: Heapsort | Num. Comparacoes: " << desempContblzdHeap.desempenho1000.comparacoes << " | Num. Copias: " << desempContblzdHeap.desempenho1000.copias << " | Temp. Tot: " << desempContblzdHeap.tempo1000 << " |" << endl;
    arquivoResultado << endl;
    
    arquivoResultado << "Medias de desempenho vetor N = 5000" << endl;
    arquivoResultado << "____________________________________" << endl;
    arquivoResultado << endl;
    arquivoResultado << "Quicksort: Recursivo | Num. Comparacoes: " << desempContblzdV1.desempenho5000.comparacoes << " | Num. Copias: " << desempContblzdV1.desempenho5000.copias << " | Temp. Tot: " << desempContblzdV1.tempo5000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 3 | Num. Comparacoes: " << desempContblzdV2K3.desempenho5000.comparacoes << " | Num. Copias: " << desempContblzdV2K3.desempenho5000.copias << " | Temp. Tot: " << desempContblzdV2K3.tempo5000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 5 | Num. Comparacoes: " << desempContblzdV2K5.desempenho5000.comparacoes << " | Num. Copias: " << desempContblzdV2K5.desempenho5000.copias << " | Temp. Tot: " << desempContblzdV2K5.tempo5000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 7 | Num. Comparacoes: " << desempContblzdV2K7.desempenho5000.comparacoes << " | Num. Copias: " << desempContblzdV2K7.desempenho5000.copias << " | Temp. Tot: " << desempContblzdV2K7.tempo5000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 10 | Num. Comparacoes: " << desempContblzdV3M10.desempenho5000.comparacoes << " | Num. Copias: " << desempContblzdV3M10.desempenho5000.copias << " | Temp. Tot: " << desempContblzdV3M10.tempo5000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 100 | Num. Comparacoes: " << desempContblzdV3M100.desempenho5000.comparacoes << " | Num. Copias: " << desempContblzdV3M100.desempenho5000.copias << " | Temp. Tot: " << desempContblzdV3M100.tempo5000 << " |" << endl;
    arquivoResultado << "Quicksort: Nao Recursivo | Num. Comparacoes: " << desempContblzdV4.desempenho5000.comparacoes << " | Num. Copias: " << desempContblzdV4.desempenho5000.copias << " | Temp. Tot: " << desempContblzdV4.tempo5000 << " |" << endl;
    arquivoResultado << "Quicksort: Empilha Inteligente | Num. Comparacoes: " << desempContblzdV5.desempenho5000.comparacoes << " | Num. Copias: " << desempContblzdV5.desempenho5000.copias << " | Temp. Tot: " << desempContblzdV5.tempo5000 << " |" << endl;
    arquivoResultado << "Quicksort: Mergesort | Num. Comparacoes: " << desempContblzdMerge.desempenho5000.comparacoes << " | Num. Copias: " << desempContblzdMerge.desempenho5000.copias << " | Temp. Tot: " << desempContblzdMerge.tempo5000 << " |" << endl;
    arquivoResultado << "Quicksort: Heapsort | Num. Comparacoes: " << desempContblzdHeap.desempenho5000.comparacoes << " | Num. Copias: " << desempContblzdHeap.desempenho5000.copias << " | Temp. Tot: " << desempContblzdHeap.tempo5000 << " |" << endl;
    arquivoResultado << endl;

    arquivoResultado << "Medias de desempenho vetor N = 10000" << endl;
    arquivoResultado << "____________________________________" << endl;
    arquivoResultado << endl;
    arquivoResultado << "Quicksort: Recursivo | Num. Comparacoes: " << desempContblzdV1.desempenho10000.comparacoes << " | Num. Copias: " << desempContblzdV1.desempenho10000.copias << " | Temp. Tot: " << desempContblzdV1.tempo10000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 3 | Num. Comparacoes: " << desempContblzdV2K3.desempenho10000.comparacoes << " | Num. Copias: " << desempContblzdV2K3.desempenho10000.copias << " | Temp. Tot: " << desempContblzdV2K3.tempo10000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 5 | Num. Comparacoes: " << desempContblzdV2K5.desempenho10000.comparacoes << " | Num. Copias: " << desempContblzdV2K5.desempenho10000.copias << " | Temp. Tot: " << desempContblzdV2K5.tempo10000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 7 | Num. Comparacoes: " << desempContblzdV2K7.desempenho10000.comparacoes << " | Num. Copias: " << desempContblzdV2K7.desempenho10000.copias << " | Temp. Tot: " << desempContblzdV2K7.tempo10000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 10 | Num. Comparacoes: " << desempContblzdV3M10.desempenho10000.comparacoes << " | Num. Copias: " << desempContblzdV3M10.desempenho10000.copias << " | Temp. Tot: " << desempContblzdV3M10.tempo10000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 100 | Num. Comparacoes: " << desempContblzdV3M100.desempenho10000.comparacoes << " | Num. Copias: " << desempContblzdV3M100.desempenho10000.copias << " | Temp. Tot: " << desempContblzdV3M100.tempo10000 << " |" << endl;
    arquivoResultado << "Quicksort: Nao Recursivo | Num. Comparacoes: " << desempContblzdV4.desempenho10000.comparacoes << " | Num. Copias: " << desempContblzdV4.desempenho10000.copias << " | Temp. Tot: " << desempContblzdV4.tempo10000 << " |" << endl;
    arquivoResultado << "Quicksort: Empilha Inteligente | Num. Comparacoes: " << desempContblzdV5.desempenho10000.comparacoes << " | Num. Copias: " << desempContblzdV5.desempenho10000.copias << " | Temp. Tot: " << desempContblzdV5.tempo10000 << " |" << endl;
    arquivoResultado << "Quicksort: Mergesort | Num. Comparacoes: " << desempContblzdMerge.desempenho10000.comparacoes << " | Num. Copias: " << desempContblzdMerge.desempenho10000.copias << " | Temp. Tot: " << desempContblzdMerge.tempo10000 << " |" << endl;
    arquivoResultado << "Quicksort: Heapsort | Num. Comparacoes: " << desempContblzdHeap.desempenho10000.comparacoes << " | Num. Copias: " << desempContblzdHeap.desempenho10000.copias << " | Temp. Tot: " << desempContblzdHeap.tempo10000 << " |" << endl;
    arquivoResultado << endl;

    arquivoResultado << "Medias de desempenho vetor N = 50000" << endl;
    arquivoResultado << "____________________________________" << endl;
    arquivoResultado << endl;
    arquivoResultado << "Quicksort: Recursivo | Num. Comparacoes: " << desempContblzdV1.desempenho50000.comparacoes << " | Num. Copias: " << desempContblzdV1.desempenho50000.copias << " | Temp. Tot: " << desempContblzdV1.tempo50000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 3 | Num. Comparacoes: " << desempContblzdV2K3.desempenho50000.comparacoes << " | Num. Copias: " << desempContblzdV2K3.desempenho50000.copias << " | Temp. Tot: " << desempContblzdV2K3.tempo50000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 5 | Num. Comparacoes: " << desempContblzdV2K5.desempenho50000.comparacoes << " | Num. Copias: " << desempContblzdV2K5.desempenho50000.copias << " | Temp. Tot: " << desempContblzdV2K5.tempo50000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 7 | Num. Comparacoes: " << desempContblzdV2K7.desempenho50000.comparacoes << " | Num. Copias: " << desempContblzdV2K7.desempenho50000.copias << " | Temp. Tot: " << desempContblzdV2K7.tempo50000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 10 | Num. Comparacoes: " << desempContblzdV3M10.desempenho50000.comparacoes << " | Num. Copias: " << desempContblzdV3M10.desempenho50000.copias << " | Temp. Tot: " << desempContblzdV3M10.tempo50000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 100 | Num. Comparacoes: " << desempContblzdV3M100.desempenho50000.comparacoes << " | Num. Copias: " << desempContblzdV3M100.desempenho50000.copias << " | Temp. Tot: " << desempContblzdV3M100.tempo50000 << " |" << endl;
    arquivoResultado << "Quicksort: Nao Recursivo | Num. Comparacoes: " << desempContblzdV4.desempenho50000.comparacoes << " | Num. Copias: " << desempContblzdV4.desempenho50000.copias << " | Temp. Tot: " << desempContblzdV4.tempo50000 << " |" << endl;
    arquivoResultado << "Quicksort: Empilha Inteligente | Num. Comparacoes: " << desempContblzdV5.desempenho50000.comparacoes << " | Num. Copias: " << desempContblzdV5.desempenho50000.copias << " | Temp. Tot: " << desempContblzdV5.tempo50000 << " |" << endl;
    arquivoResultado << "Quicksort: Mergesort | Num. Comparacoes: " << desempContblzdMerge.desempenho50000.comparacoes << " | Num. Copias: " << desempContblzdMerge.desempenho50000.copias << " | Temp. Tot: " << desempContblzdMerge.tempo50000 << " |" << endl;
    arquivoResultado << "Quicksort: Heapsort | Num. Comparacoes: " << desempContblzdHeap.desempenho50000.comparacoes << " | Num. Copias: " << desempContblzdHeap.desempenho50000.copias << " | Temp. Tot: " << desempContblzdHeap.tempo50000 << " |" << endl;
    arquivoResultado << endl;

    arquivoResultado << "Medias de desempenho vetor N = 100000" << endl;
    arquivoResultado << "____________________________________" << endl;
    arquivoResultado << endl;
    arquivoResultado << "Quicksort: Recursivo | Num. Comparacoes: " << desempContblzdV1.desempenho100000.comparacoes << " | Num. Copias: " << desempContblzdV1.desempenho100000.copias << " | Temp. Tot: " << desempContblzdV1.tempo100000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 3 | Num. Comparacoes: " << desempContblzdV2K3.desempenho100000.comparacoes << " | Num. Copias: " << desempContblzdV2K3.desempenho100000.copias << " | Temp. Tot: " << desempContblzdV2K3.tempo100000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 5 | Num. Comparacoes: " << desempContblzdV2K5.desempenho100000.comparacoes << " | Num. Copias: " << desempContblzdV2K5.desempenho100000.copias << " | Temp. Tot: " << desempContblzdV2K5.tempo100000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 7 | Num. Comparacoes: " << desempContblzdV2K7.desempenho100000.comparacoes << " | Num. Copias: " << desempContblzdV2K7.desempenho100000.copias << " | Temp. Tot: " << desempContblzdV2K7.tempo100000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 10 | Num. Comparacoes: " << desempContblzdV3M10.desempenho100000.comparacoes << " | Num. Copias: " << desempContblzdV3M10.desempenho100000.copias << " | Temp. Tot: " << desempContblzdV3M10.tempo100000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 100 | Num. Comparacoes: " << desempContblzdV3M100.desempenho100000.comparacoes << " | Num. Copias: " << desempContblzdV3M100.desempenho100000.copias << " | Temp. Tot: " << desempContblzdV3M100.tempo100000 << " |" << endl;
    arquivoResultado << "Quicksort: Nao Recursivo | Num. Comparacoes: " << desempContblzdV4.desempenho100000.comparacoes << " | Num. Copias: " << desempContblzdV4.desempenho100000.copias << " | Temp. Tot: " << desempContblzdV4.tempo100000 << " |" << endl;
    arquivoResultado << "Quicksort: Empilha Inteligente | Num. Comparacoes: " << desempContblzdV5.desempenho100000.comparacoes << " | Num. Copias: " << desempContblzdV5.desempenho100000.copias << " | Temp. Tot: " << desempContblzdV5.tempo100000 << " |" << endl;
    arquivoResultado << "Quicksort: Mergesort | Num. Comparacoes: " << desempContblzdMerge.desempenho100000.comparacoes << " | Num. Copias: " << desempContblzdMerge.desempenho100000.copias << " | Temp. Tot: " << desempContblzdMerge.tempo100000 << " |" << endl;
    arquivoResultado << "Quicksort: Heapsort | Num. Comparacoes: " << desempContblzdHeap.desempenho100000.comparacoes << " | Num. Copias: " << desempContblzdHeap.desempenho100000.copias << " | Temp. Tot: " << desempContblzdHeap.tempo100000 << " |" << endl;
    arquivoResultado << endl;

    arquivoResultado << "Medias de desempenho vetor N = 500000" << endl;
    arquivoResultado << "____________________________________" << endl;
    arquivoResultado << endl;
    arquivoResultado << "Quicksort: Recursivo | Num. Comparacoes: " << desempContblzdV1.desempenho500000.comparacoes << " | Num. Copias: " << desempContblzdV1.desempenho500000.copias << " | Temp. Tot: " << desempContblzdV1.tempo500000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 3 | Num. Comparacoes: " << desempContblzdV2K3.desempenho500000.comparacoes << " | Num. Copias: " << desempContblzdV2K3.desempenho500000.copias << " | Temp. Tot: " << desempContblzdV2K3.tempo500000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 5 | Num. Comparacoes: " << desempContblzdV2K5.desempenho500000.comparacoes << " | Num. Copias: " << desempContblzdV2K5.desempenho500000.copias << " | Temp. Tot: " << desempContblzdV2K5.tempo500000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 7 | Num. Comparacoes: " << desempContblzdV2K7.desempenho500000.comparacoes << " | Num. Copias: " << desempContblzdV2K7.desempenho500000.copias << " | Temp. Tot: " << desempContblzdV2K7.tempo500000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 10 | Num. Comparacoes: " << desempContblzdV3M10.desempenho500000.comparacoes << " | Num. Copias: " << desempContblzdV3M10.desempenho500000.copias << " | Temp. Tot: " << desempContblzdV3M10.tempo500000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 100 | Num. Comparacoes: " << desempContblzdV3M100.desempenho500000.comparacoes << " | Num. Copias: " << desempContblzdV3M100.desempenho500000.copias << " | Temp. Tot: " << desempContblzdV3M100.tempo500000 << " |" << endl;
    arquivoResultado << "Quicksort: Nao Recursivo | Num. Comparacoes: " << desempContblzdV4.desempenho500000.comparacoes << " | Num. Copias: " << desempContblzdV4.desempenho500000.copias << " | Temp. Tot: " << desempContblzdV4.tempo500000 << " |" << endl;
    arquivoResultado << "Quicksort: Empilha Inteligente | Num. Comparacoes: " << desempContblzdV5.desempenho500000.comparacoes << " | Num. Copias: " << desempContblzdV5.desempenho500000.copias << " | Temp. Tot: " << desempContblzdV5.tempo500000 << " |" << endl;
    arquivoResultado << "Quicksort: Mergesort | Num. Comparacoes: " << desempContblzdMerge.desempenho500000.comparacoes << " | Num. Copias: " << desempContblzdMerge.desempenho500000.copias << " | Temp. Tot: " << desempContblzdMerge.tempo500000 << " |" << endl;
    arquivoResultado << "Quicksort: Heapsort | Num. Comparacoes: " << desempContblzdHeap.desempenho500000.comparacoes << " | Num. Copias: " << desempContblzdHeap.desempenho500000.copias << " | Temp. Tot: " << desempContblzdHeap.tempo500000 << " |" << endl;
    arquivoResultado << endl;

    arquivoResultado << "Medias de desempenho vetor N = 1000000" << endl;
    arquivoResultado << "____________________________________" << endl;
    arquivoResultado << endl;
    arquivoResultado << "Quicksort: Recursivo | Num. Comparacoes: " << desempContblzdV1.desempenho1000000.comparacoes << " | Num. Copias: " << desempContblzdV1.desempenho1000000.copias << " | Temp. Tot: " << desempContblzdV1.tempo1000000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 3 | Num. Comparacoes: " << desempContblzdV2K3.desempenho1000000.comparacoes << " | Num. Copias: " << desempContblzdV2K3.desempenho1000000.copias << " | Temp. Tot: " << desempContblzdV2K3.tempo1000000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 5 | Num. Comparacoes: " << desempContblzdV2K5.desempenho1000000.comparacoes << " | Num. Copias: " << desempContblzdV2K5.desempenho1000000.copias << " | Temp. Tot: " << desempContblzdV2K5.tempo1000000 << " |" << endl;
    arquivoResultado << "Quicksort: Mediana | k = 7 | Num. Comparacoes: " << desempContblzdV2K7.desempenho1000000.comparacoes << " | Num. Copias: " << desempContblzdV2K7.desempenho1000000.copias << " | Temp. Tot: " << desempContblzdV2K7.tempo1000000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 10 | Num. Comparacoes: " << desempContblzdV3M10.desempenho1000000.comparacoes << " | Num. Copias: " << desempContblzdV3M10.desempenho1000000.copias << " | Temp. Tot: " << desempContblzdV3M10.tempo1000000 << " |" << endl;
    arquivoResultado << "Quicksort: Selecao | m = 100 | Num. Comparacoes: " << desempContblzdV3M100.desempenho1000000.comparacoes << " | Num. Copias: " << desempContblzdV3M100.desempenho1000000.copias << " | Temp. Tot: " << desempContblzdV3M100.tempo1000000 << " |" << endl;
    arquivoResultado << "Quicksort: Nao Recursivo | Num. Comparacoes: " << desempContblzdV4.desempenho1000000.comparacoes << " | Num. Copias: " << desempContblzdV4.desempenho1000000.copias << " | Temp. Tot: " << desempContblzdV4.tempo1000000 << " |" << endl;
    arquivoResultado << "Quicksort: Empilha Inteligente | Num. Comparacoes: " << desempContblzdV5.desempenho1000000.comparacoes << " | Num. Copias: " << desempContblzdV5.desempenho1000000.copias << " | Temp. Tot: " << desempContblzdV5.tempo1000000 << " |" << endl;
    arquivoResultado << "Quicksort: Mergesort | Num. Comparacoes: " << desempContblzdMerge.desempenho1000000.comparacoes << " | Num. Copias: " << desempContblzdMerge.desempenho1000000.copias << " | Temp. Tot: " << desempContblzdMerge.tempo1000000 << " |" << endl;
    arquivoResultado << "Quicksort: Heapsort | Num. Comparacoes: " << desempContblzdHeap.desempenho1000000.comparacoes << " | Num. Copias: " << desempContblzdHeap.desempenho1000000.copias << " | Temp. Tot: " << desempContblzdHeap.tempo1000000 << " |" << endl;


}

#endif