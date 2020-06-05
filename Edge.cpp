#include "Edge.hpp"


Edge::Edge(Node* a, Node* b){
    this->node1 = a;
    this->node2 = b;
}
        
Node* Edge::getNode1(){
    return node1;
}

Node* Edge::getNode2(){
    return node2;
}