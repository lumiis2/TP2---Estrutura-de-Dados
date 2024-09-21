#include "../include/GraphMatrix.hpp"
#include<iostream>
#include <stdlib.h>

GraphMatrix::GraphMatrix(int size){
    this->size = size;
    this->neighborhoodSize = (int*) std::malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) this->neighborhoodSize[i] = 0;
    
    this->matrix = (bool**) std::malloc(sizeof(bool*) * size);
    for(int i = 0; i < size; i++){
        this->matrix[i] = (bool*) std::malloc(sizeof(bool) * size);
        for(int j = 0; j < size; j++) matrix[i][j] = false;
    }
}

void GraphMatrix::addEdge(int va, int vb){
    this->matrix[va][vb] = true;
    this->neighborhoodSize[va]++;
}

int* GraphMatrix::getNeighborhood(int vertex){
    int* ans = (int*) std::malloc(sizeof(int) * this->getNeighborhoodSize(vertex));
    int at = 0;
    for(int i = 0; i < this->size; i++){
        if(matrix[vertex][i]==true){
            ans[at] = i;
            at++;
        }
    }
    return ans;
}