#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
#include "Graph.hpp"

class GraphMatrix : public Graph{
    public:
        virtual int* getNeighborhood(int vertex);
        virtual void addEdge(int va, int vb);
        GraphMatrix(int size);
    private:
        bool** matrix;
};

#endif