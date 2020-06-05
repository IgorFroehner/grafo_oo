#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Node.hpp"
#include "Edge.hpp"
#include <list>

class Grafo{
    public:
        void adicionarVeritice(Node* node);
        void removerVertice(Node* node);
        void removerVertice(unsigned int id);
        
        void adicionarAresta(Node* node1, Node* node2);
        void removerAresta(Node* node1, Node* node2);
        void removerAresta(unsigned int id1, unsigned int id2);

        void imprimirGrafo();

    private:
        std::list<Node*> nodes;

};

#endif