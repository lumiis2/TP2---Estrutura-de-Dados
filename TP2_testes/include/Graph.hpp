#ifndef GRAPH
#define GRAPH
#include "Point.hpp"

class Graph{
    public:
        virtual int* getNeighborhood(int vertex) = 0;
        virtual void addEdge(int va, int vb) = 0;
        
        int getNeighborhoodSize(int vertex){
                return this->neighborhoodSize[vertex];
        }
    protected:
        int size;
        int* neighborhoodSize;

};

#endif