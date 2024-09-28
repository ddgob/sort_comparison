CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/quicksortRecursivo.o $(OBJ)/quicksortMediana.o $(OBJ)/geradorDeVetorAleatorio.o $(OBJ)/quicksortAuxiliar.o $(OBJ)/pivoMediana.o $(OBJ)/selecaoAuxiliar.o $(OBJ)/quicksortSelecao.o $(OBJ)/PilhaNaoRec.o $(OBJ)/quicksortNaoRecIntel.o $(OBJ)/quicksortNaoRecNaoIntel.o $(OBJ)/mergesort.o $(OBJ)/heapsort.o $(OBJ)/memlog.o
HDRS = $(INC)/Item.hpp $(INC)/quicksortRecursivo.hpp $(INC)/quicksortMediana.hpp $(INC)/geradorDeVetorAleatorio.hpp $(INC)/quicksortAuxiliar.hpp $(INC)/itemAuxiliar.hpp $(INC)/pivoMediana.hpp $(INC)/selecaoAuxiliar.hpp $(INC)/quicksortSelecao.hpp $(INC)/ItemQuicksortNaoRec.hpp $(INC)/PilhaNaoRec.hpp $(INC)/quicksortNaoRecIntel.hpp $(INC)/quicksortNaoRecNaoIntel.hpp $(INC)/mergesort.hpp $(INC)/heapsort.hpp $(INC)/desempenho.hpp $(INC)/memlog.h $(INC)/contabilizar.hpp
CFLAGS = -Wall -c -g -I$(INC)  -std=c++17

EXE = $(BIN)/tp2

all: clean $(EXE)

#Semente 10
	./$(EXE) quicksort -v 1 -s 10 -i entrada.txt -o saidaV1S10.txt
	./$(EXE) quicksort -v 2 -k 3 -s 10 -i entrada.txt -o saidaV2S10K3.txt
	./$(EXE) quicksort -v 2 -k 5 -s 10 -i entrada.txt -o saidaV2S10K5.txt
	./$(EXE) quicksort -v 2 -k 7 -s 10 -i entrada.txt -o saidaV2S10K7.txt
	./$(EXE) quicksort -v 3 -m 10 -s 10 -i entrada.txt -o saidaV3S10M10.txt
	./$(EXE) quicksort -v 3 -m 100 -s 10 -i entrada.txt -o saidaV3S10M100.txt
	./$(EXE) quicksort -v 4 -s 10 -i entrada.txt -o saidaV4S10.txt
	./$(EXE) quicksort -v 5 -s 10 -i entrada.txt -o saidaV5S10.txt
	./$(EXE) heapsort -s 10 -i entrada.txt -o saidaHeapS10.txt
	./$(EXE) mergesort -s 10 -i entrada.txt -o saidaMergeS10.txt

#Semente 58
	./$(EXE) quicksort -v 1 -s 58 -i entrada.txt -o saidaV1S58.txt
	./$(EXE) quicksort -v 2 -k 3 -s 58 -i entrada.txt -o saidaV2S58K3.txt
	./$(EXE) quicksort -v 2 -k 5 -s 58 -i entrada.txt -o saidaV2S58K5.txt
	./$(EXE) quicksort -v 2 -k 7 -s 58 -i entrada.txt -o saidaV2S58K7.txt
	./$(EXE) quicksort -v 3 -m 10 -s 58 -i entrada.txt -o saidaV3S58M10.txt
	./$(EXE) quicksort -v 3 -m 100 -s 58 -i entrada.txt -o saidaV3S58M100.txt
	./$(EXE) quicksort -v 4 -s 58 -i entrada.txt -o saidaV4S58.txt
	./$(EXE) quicksort -v 5 -s 58 -i entrada.txt -o saidaV5S58.txt
	./$(EXE) heapsort -s 58 -i entrada.txt -o saidaHeapS58.txt
	./$(EXE) mergesort -s 58 -i entrada.txt -o saidaMergeS58.txt
	

#Semente 649
	./$(EXE) quicksort -v 1 -s 649 -i entrada.txt -o saidaV1S649.txt
	./$(EXE) quicksort -v 2 -k 3 -s 649 -i entrada.txt -o saidaV2S649K3.txt
	./$(EXE) quicksort -v 2 -k 5 -s 649 -i entrada.txt -o saidaV2S649K5.txt
	./$(EXE) quicksort -v 2 -k 7 -s 649 -i entrada.txt -o saidaV2S649K7.txt
	./$(EXE) quicksort -v 3 -m 10 -s 649 -i entrada.txt -o saidaV3S649M10.txt
	./$(EXE) quicksort -v 3 -m 100 -s 649 -i entrada.txt -o saidaV3S649M100.txt
	./$(EXE) quicksort -v 4 -s 649 -i entrada.txt -o saidaV4S649.txt
	./$(EXE) quicksort -v 5 -s 649 -i entrada.txt -o saidaV5S649.txt
	./$(EXE) heapsort -s 649 -i entrada.txt -o saidaHeapS649.txt
	./$(EXE) mergesort -s 649 -i entrada.txt -o saidaMergeS649.txt

#Semente 396284
	./$(EXE) quicksort -v 1 -s 396284 -i entrada.txt -o saidaV1S396284.txt
	./$(EXE) quicksort -v 2 -k 3 -s 396284 -i entrada.txt -o saidaV2S396284K3.txt
	./$(EXE) quicksort -v 2 -k 5 -s 396284 -i entrada.txt -o saidaV2S396284K5.txt
	./$(EXE) quicksort -v 2 -k 7 -s 396284 -i entrada.txt -o saidaV2S396284K7.txt
	./$(EXE) quicksort -v 3 -m 10 -s 396284 -i entrada.txt -o saidaV3S396284M10.txt
	./$(EXE) quicksort -v 3 -m 100 -s 396284 -i entrada.txt -o saidaV3S396284M100.txt
	./$(EXE) quicksort -v 4 -s 396284 -i entrada.txt -o saidaV4S396284.txt
	./$(EXE) quicksort -v 5 -s 396284 -i entrada.txt -o saidaV5S396284.txt
	./$(EXE) heapsort -s 396284 -i entrada.txt -o saidaHeapS396284.txt
	./$(EXE) mergesort -s 396284 -i entrada.txt -o saidaMergeS396284.txt

#Semente 98278992
	./$(EXE) quicksort -v 1 -s 98278992 -i entrada.txt -o saidaV1S98278992.txt
	./$(EXE) quicksort -v 2 -k 3 -s 98278992 -i entrada.txt -o saidaV2S98278992K3.txt
	./$(EXE) quicksort -v 2 -k 5 -s 98278992 -i entrada.txt -o saidaV2S98278992K5.txt
	./$(EXE) quicksort -v 2 -k 7 -s 98278992 -i entrada.txt -o saidaV2S98278992K7.txt
	./$(EXE) quicksort -v 3 -m 10 -s 98278992 -i entrada.txt -o saidaV3S98278992M10.txt
	./$(EXE) quicksort -v 3 -m 100 -s 98278992 -i entrada.txt -o saidaV3S98278992M100.txt
	./$(EXE) quicksort -v 4 -s 98278992 -i entrada.txt -o saidaV4S98278992.txt
	./$(EXE) quicksort -v 5 -s 98278992 -i entrada.txt -o saidaV5S98278992.txt
	./$(EXE) heapsort -s 98278992 -i entrada.txt -o saidaHeapS98278992.txt
	./$(EXE) mergesort -s 98278992 -i entrada.txt -o saidaMergeS98278992.txt
	./$(EXE) -c

testRun: clean $(EXE)

#Semente 10

	./$(EXE) quicksort -v 1 -s 10 -i entrada.txt -o saidaV1S10.txt -p Outputs/logV1S10.out -l
	analisamem/bin/analisamem -i Outputs/logV1S10.out -p Outputs/graphV1S10 -f png
	gnuplot Outputs/*.gp

	./$(EXE) quicksort -v 2 -k 3 -s 10 -i entrada.txt -o saidaV2S10K3.txt -p Outputs/logV2S10K3.out -l
	analisamem/bin/analisamem -i Outputs/logV2S10K3.out -p Outputs/graphV2S10K3 -f png
	gnuplot Outputs/*.gp
	
	./$(EXE) quicksort -v 3 -m 3 -s 10 -i entrada.txt -o saidaV3S10M10.txt -p Outputs/logV3S10M10.out -l
	analisamem/bin/analisamem -i Outputs/logV3S10M10.out -p Outputs/graphV3S10M10 -f png
	gnuplot Outputs/*.gp
	
	./$(EXE) quicksort -v 4 -s 10 -i entrada.txt -o saidaV4S10.txt -p Outputs/logV4S10.out -l
	analisamem/bin/analisamem -i Outputs/logV4S10.out -p Outputs/graphV4S10 -f png
	gnuplot Outputs/*.gp
	
	./$(EXE) quicksort -v 5 -s 10 -i entrada.txt -o saidaV5S10.txt -p Outputs/logV5S10.out -l
	analisamem/bin/analisamem -i Outputs/logV5S10.out -p Outputs/graphV5S10 -f png
	gnuplot Outputs/*.gp
	
	./$(EXE) mergesort -s 10 -i entrada.txt -o saidaMergeS10.txt -p Outputs/logMergeS10.out -l
	analisamem/bin/analisamem -i Outputs/logMergeS10.out -p Outputs/graphMergeS10 -f png
	gnuplot Outputs/*.gp

	./$(EXE) heapsort -s 10 -i entrada.txt -o saidaHeapS10.txt -p Outputs/logHeapS10.out -l
	analisamem/bin/analisamem -i Outputs/logHeapS10.out -p Outputs/graphHeapS10 -f png
	gnuplot Outputs/*.gp

compile: clean $(EXE)

run: 
	./$(EXE)

$(BIN)/tp2: $(OBJS)
	$(CC) $(OBJS) -o $(BIN)/tp2 $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/Item.o: $(HDRS) $(SRC)/Item.cpp
	$(CC) $(CFLAGS) $(SRC)/Item.cpp -o $(OBJ)/Item.o

$(OBJ)/desempenho.o: $(HDRS) $(SRC)/desempenho.cpp
	$(CC) $(CFLAGS) $(SRC)/desempenho.cpp -o $(OBJ)/desempenho.o

$(OBJ)/contabilizar.o: $(HDRS) $(SRC)/contabilizar.cpp
	$(CC) $(CFLAGS) $(SRC)/contabilizar.cpp -o $(OBJ)/contabilizar.o

$(OBJ)/quicksortRecursivo.o: $(HDRS) $(SRC)/quicksortRecursivo.cpp
	$(CC) $(CFLAGS) $(SRC)/quicksortRecursivo.cpp -o $(OBJ)/quicksortRecursivo.o

$(OBJ)/quicksortMediana.o: $(HDRS) $(SRC)/quicksortMediana.cpp
	$(CC) $(CFLAGS) $(SRC)/quicksortMediana.cpp -o $(OBJ)/quicksortMediana.o

$(OBJ)/geradorDeVetorAleatorio.o: $(HDRS) $(SRC)/geradorDeVetorAleatorio.cpp
	$(CC) $(CFLAGS) $(SRC)/geradorDeVetorAleatorio.cpp -o $(OBJ)/geradorDeVetorAleatorio.o

$(OBJ)/quicksortAuxiliar.o: $(HDRS) $(SRC)/quicksortAuxiliar.cpp
	$(CC) $(CFLAGS) $(SRC)/quicksortAuxiliar.cpp -o $(OBJ)/quicksortAuxiliar.o

$(OBJ)/pivoMediana.o: $(HDRS) $(SRC)/pivoMediana.cpp
	$(CC) $(CFLAGS) $(SRC)/pivoMediana.cpp -o $(OBJ)/pivoMediana.o

$(OBJ)/selecaoAuxiliar.o: $(HDRS) $(SRC)/selecaoAuxiliar.cpp
	$(CC) $(CFLAGS) $(SRC)/selecaoAuxiliar.cpp -o $(OBJ)/selecaoAuxiliar.o

$(OBJ)/quicksortSelecao.o: $(HDRS) $(SRC)/quicksortSelecao.cpp
	$(CC) $(CFLAGS) $(SRC)/quicksortSelecao.cpp -o $(OBJ)/quicksortSelecao.o

$(OBJ)/PilhaNaoRec.o: $(HDRS) $(SRC)/PilhaNaoRec.cpp
	$(CC) $(CFLAGS) $(SRC)/PilhaNaoRec.cpp -o $(OBJ)/PilhaNaoRec.o

$(OBJ)/quicksortNaoRecIntel.o: $(HDRS) $(SRC)/quicksortNaoRecIntel.cpp
	$(CC) $(CFLAGS) $(SRC)/quicksortNaoRecIntel.cpp -o $(OBJ)/quicksortNaoRecIntel.o

$(OBJ)/quicksortNaoRecNaoIntel.o: $(HDRS) $(SRC)/quicksortNaoRecNaoIntel.cpp
	$(CC) $(CFLAGS) $(SRC)/quicksortNaoRecNaoIntel.cpp -o $(OBJ)/quicksortNaoRecNaoIntel.o

$(OBJ)/mergesort.o: $(HDRS) $(SRC)/mergesort.cpp
	$(CC) $(CFLAGS) $(SRC)/mergesort.cpp -o $(OBJ)/mergesort.o

$(OBJ)/heapsort.o: $(HDRS) $(SRC)/heapsort.cpp
	$(CC) $(CFLAGS) $(SRC)/heapsort.cpp -o $(OBJ)/heapsort.o

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) $(SRC)/memlog.c -o $(OBJ)/memlog.o

clean: 
	rm -f $(EXE) $(OBJS) Outputs/*.gp Outputs/*.gpdat Outputs/*.png Outputs/*.out