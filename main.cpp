#include <iostream>

#include "Grafo.hpp"
#include "Node.hpp"

int main(){

    Grafo grafo;
    
    Node* node0{new Node()};
    grafo.adicionarVeritice(node0);
    
    Node* node1{new Node()};
    grafo.adicionarVeritice(node1);
    
    Node* node2{new Node()};
    grafo.adicionarVeritice(node2);

    Node* node3{new Node()};
    grafo.adicionarVeritice(node3);

    // 0 <-> 1
    // 0 <-> 2
    // 0 <-> 3
    grafo.adicionarAresta(node0, node1);
    grafo.adicionarAresta(node0, node2);
    grafo.adicionarAresta(node0, node3);

    // 1 <-> 2
    grafo.adicionarAresta(node1, node2);

    // 1 <-> 3
    grafo.adicionarAresta(node1, node3);

    // 2 <-> 3
    grafo.adicionarAresta(node2, node3);

    grafo.imprimirGrafo();

    // 0 <-/-> 1
    grafo.removerAresta(0,  1);

    std::cout << std::endl << std::endl << "Aresta entre 0 e 1 removida" << std::endl;
    
    grafo.imprimirGrafo();

    // excluindo 2
    grafo.removerVertice(2);

    std::cout << std::endl << std::endl << "Vertice 2 removido" << std::endl;

    grafo.imprimirGrafo();

    return 0;
}