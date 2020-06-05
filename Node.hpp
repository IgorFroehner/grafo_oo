#ifndef NODE_HPP
#define NODE_HPP    

#include <list>
class Edge;

class Node{
    friend class Edge;
    public:
        Node();

        static unsigned int proxId;
        unsigned int getId();
        
        void addEdge(Edge* e);
        const std::list<Edge*>& getEdges();
        void removerEdge(Node* node);

        void printAdjacentes();
    private:
        unsigned int id;
        std::list<Edge*> edges;
    
};


#endif