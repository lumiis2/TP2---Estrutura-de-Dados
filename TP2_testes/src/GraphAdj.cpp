#include "../include/GraphAdj.hpp"
#include "../include/Graph.hpp"
#include <stdlib.h>
#include <iostream>

GraphAdj::GraphAdj(int size){
    this->size = size;
    this->neighborhoodSize = (int*) std::malloc(sizeof(int) * size);
    this->maxNeighborhood = (int*) std::malloc(sizeof(int) * size);
    this->neighborhood = (int**) std::malloc(sizeof(int*) * size);
    for(int i =  0; i < size; i++){
        this->neighborhoodSize[i] = 0;
        this->maxNeighborhood[i] = 1;
        this->neighborhood[i] = (int*) std::malloc(sizeof(int) * 1);
    }

}

void GraphAdj::resize(int vertex){
    int tamanhoAnterior = this->maxNeighborhood[vertex];
    this->maxNeighborhood[vertex] *= 2;
    int* aux = (int*) std::malloc(sizeof(int) * this->maxNeighborhood[vertex]);
    
    for(int i = 0; i < tamanhoAnterior; i++){
        aux[i] = this->neighborhood[vertex][i];
    }

    free(this->neighborhood[vertex]);
    this->neighborhood[vertex] = aux;
}


//depois de receber, tem que dar free
int* GraphAdj::getNeighborhood(int vertex) {
    int* ret = (int*) std::malloc(sizeof(int) * this->neighborhoodSize[vertex]);
    for(int i = 0; i < this->getNeighborhoodSize(vertex); i++)
        ret[i] = this->neighborhood[vertex][i];
    return ret;
}

void GraphAdj::addEdge(int va, int vb){
    if(this->maxNeighborhood[va] == this->getNeighborhoodSize(va)){
        resize(va);
    }
    this->neighborhood[va][this->getNeighborhoodSize(va)] = vb;
    this->neighborhoodSize[va]++;
}