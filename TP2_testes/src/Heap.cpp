/*#include "Heap.hpp"
#include<stdlib.h>
#include<iostream>

void Heap::move(int& i, int dir){
    int j;
    if(dir==0) j = i/2;
    if(dir==1) j = 2*i;
    if(dir==2) j = 2*i+1;
    Pair aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
    i = j;
}

int Heap::size(){
    return this->ultimoElemento;
}

void Heap::pop(){
    if(ultimoElemento==0) return;
    Pair aux = vetor[ultimoElemento];
    vetor[ultimoElemento] = vetor[1];
    vetor[1] = aux;
    int atual = 1;

    ultimoElemento--;
    if(ultimoElemento<=0) return;

    while(true){
        if(atual*2 > ultimoElemento) break;

        if(atual*2+1 <= ultimoElemento){
            if(vetor[atual*2].first < vetor[atual*2+1].first){
                if(vetor[atual*2].first < vetor[atual].first) move(atual, 1);
                else break;
            }else{
                if(vetor[atual*2+1].first < vetor[atual].first) move(atual, 2);
                else break;
            }
        }else{
            if(vetor[atual].first > vetor[atual*2].first) move(atual, 1);
            else break;
        }

    }
    
    
}

Pair Heap::top(){
    if(ultimoElemento==0) return Pair(-1, -1);
    return this->vetor[1];
}

void Heap::resize(){
    tamanho = 2*tamanho;
    int tamanhoAnterior = tamanho/2;
    Pair* aux = (Pair*) std::malloc((tamanho+1) * (sizeof(Pair)));

    for(int i = 0; i <= tamanhoAnterior; i++){
        aux[i] = this->vetor[i];
    }
    
    free(vetor);
    vetor = aux;
}

void Heap::insert(Pair p){
    if(ultimoElemento == tamanho) resize();
    ultimoElemento++;
    vetor[ultimoElemento] = p;
    int atual = this->ultimoElemento;
    
    while(vetor[atual].first < vetor[atual/2].first){
        move(atual, 0);   
    }  
}

Heap::Heap(){
    tamanho = 1;
    ultimoElemento = 0;
    vetor = (Pair*) std::malloc(sizeof(Pair) * 2);
    Pair aux = Pair(-1000000001, -1000000001);
    vetor[0] = aux;
}*/