#include "Node.hpp"
#include "Edge.hpp"
#include <iostream>

unsigned int Node::proxId{0};

Node::Node(){
    id = proxId++;
}

unsigned int Node::getId(){
    return id;
}

void Node::addEdge(Edge* e){
    edges.push_back(e);
}

const std::list<Edge*>& Node::getEdges(){
    return edges;
}

void Node::removerEdge(Node* node){
    std::list<Edge*>::iterator it = edges.begin();
    for ( ; it!=edges.end(); it++){
        if ((*it)->getNode1()==node || (*it)->getNode2()==node){
            edges.erase(it);
            break;
        }
    }
}

void Node::printAdjacentes(){
    std::list<Edge*>::iterator it = edges.begin();
    std::cout << "São adjacentes ao vertice " << this->getId() << ":" << std::endl;
    for ( ; it!=edges.end(); it++){
        if ((*it)->getNode1()!=this){
            std::cout << (*it)->getNode1()->getId() << " ";
        }else{
            std::cout << (*it)->getNode2()->getId() << " ";
        }
    }
    std::cout << std::endl;
}