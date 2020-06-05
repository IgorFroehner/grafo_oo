#include "Grafo.hpp"
#include <iostream>

void Grafo::adicionarVeritice(Node* node){
    this->nodes.push_back(node);
}

void Grafo::removerVertice(Node* node){
    std::list<Edge*> nodeEdges = node->getEdges();
    std::list<Edge*>::const_iterator it = nodeEdges.begin();
    for ( ; it!=nodeEdges.end(); it++){
        this->removerAresta((*it)->getNode1(), (*it)->getNode2());
    }
    this->nodes.remove(node);
    delete node;
}

void Grafo::removerVertice(unsigned int id){
    std::list<Node*>::iterator nodeIt = nodes.begin();
    Node* node = nullptr;
    for ( ; nodeIt!=nodes.end(); nodeIt++){
        if (id==(*nodeIt)->getId()){
            node = (*nodeIt);
            break;
        }
    }
    if (node==nullptr){
        std::cerr << "Vertice não encontrado" << std::endl;
    }else{
        std::list<Edge*> nodeEdges = node->getEdges();
        std::list<Edge*>::const_iterator it = nodeEdges.begin();
        for ( ; it!=nodeEdges.end(); it++){
            this->removerAresta((*it)->getNode1(), (*it)->getNode2());
        }
        this->nodes.erase(nodeIt);
        delete node;
    }
}

void Grafo::adicionarAresta(Node* node1, Node* node2){
    Edge* newEdge{new Edge{node1, node2}};
    node1->addEdge(newEdge);
    node2->addEdge(newEdge);
}

void Grafo::removerAresta(Node* node1, Node* node2){
    node1->removerEdge(node2);
    node2->removerEdge(node1);
}

void Grafo::removerAresta(unsigned int id1, unsigned int id2){
    std::list<Node*>::iterator it = nodes.begin();
    Node* node1 = nullptr;
    Node* node2 = nullptr;
    for ( ; it!=nodes.end(); it++){
        if ((*it)->getId()==id1 && node1==nullptr){
            node1 = (*it);
        }
        if ((*it)->getId()==id2 && node2==nullptr){
            node2 = (*it);
        }
    }
    node1->removerEdge(node2);
    node2->removerEdge(node1);
}

void Grafo::imprimirGrafo(){
    std::list<Node*>::iterator it = nodes.begin();
    for ( ; it!=nodes.end(); it++){
        (*it)->printAdjacentes();
    }
}

