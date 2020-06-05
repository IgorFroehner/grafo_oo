parametrosCompilacao=-Wall #-Wshadow

all: grafo

grafo: main.o Grafo.o Edge.o Node.o
	g++ -o grafo main.o Grafo.o Edge.o Node.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Grafo.o: Grafo.hpp Grafo.cpp
	g++ -c Grafo.cpp $(parametrosCompilacao)


Edge.o: Edge.hpp Edge.cpp
	g++ -c Edge.cpp $(parametrosCompilacao)

Node.o: Node.hpp Node.cpp
	g++ -c Node.cpp $(parametrosCompilacao)

clean:
	rm *.o grafo
