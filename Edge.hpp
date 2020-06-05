#ifndef EDGE_HPP
#define EDGE_HPP

#include "Node.hpp"

class Edge{
    public:
        Edge(Node* a, Node* b);
        
        Node* getNode1();
        Node* getNode2();
    private:
        Node* node1;
        Node* node2;
    
};

#endif