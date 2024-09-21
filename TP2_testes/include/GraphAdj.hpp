#ifndef GRAPHADJ_H
#define GRAPHADJ_H
#include "Graph.hpp"

class GraphAdj : public Graph{
    public:
        virtual int* getNeighborhood(int vertex) override;
        virtual void addEdge(int va, int vb) override;
        GraphAdj(int size);
    private:
        int* maxNeighborhood;
        int** neighborhood;
        void resize(int x);
        
};

#endif