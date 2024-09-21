#ifndef HEAP
#define HEAP

#include "Pair.hpp"
#include <stdlib.h>
#include <stdexcept>


//para usar essa classe, é preciso que exista um construtor padrão.
template<typename T> class Heap{
    private:
        T* vetor;
        long long tamanho;
        long long ultimoElemento;
    public:
        int size(){
            return this->ultimoElemento;
        }

        //SE A LISTA ESTIVER VAZIA, NÃO RETORNA NADA.
        T top(){
            if(ultimoElemento==0) throw std::exception();
            return this->vetor[1];
        }

        void pop(){
            if(ultimoElemento==0) return;
            T aux = vetor[ultimoElemento];
            vetor[ultimoElemento] = vetor[1];
            vetor[1] = aux;
            int atual = 1;

            ultimoElemento--;
            if(ultimoElemento<=0) return;

            while(true){
                if(atual*2 > ultimoElemento) break;

                if(atual*2+1 <= ultimoElemento){
                    if(vetor[atual*2] < vetor[atual*2+1]){
                        if(vetor[atual*2] < vetor[atual]) move(atual, 1);
                        else break;
                    }else{
                        if(vetor[atual*2+1] < vetor[atual]) move(atual, 2);
                        else break;
                    }
                }else{
                    if(vetor[atual] > vetor[atual*2]) move(atual, 1);
                    else break;
                }

            }
        }


        void resize(){
            tamanho = 2*tamanho;
            int tamanhoAnterior = tamanho/2;
            T* aux = (T*) std::malloc((tamanho+1) * (sizeof(T)));

            for(int i = 0; i <= tamanhoAnterior; i++){
                aux[i] = this->vetor[i];
            }
            
            free(vetor);
            vetor = aux;
        }

        void insert(T p){
            if(ultimoElemento == tamanho) resize();
            ultimoElemento++;
            vetor[ultimoElemento] = p;
            int atual = this->ultimoElemento;
            
            while(vetor[atual] < vetor[atual/2] and atual/2 != 0){
                move(atual, 0);   
            }  
        }

        //cima 0, esq 1, dir 2
        void move(int& i, int dir){
            int j;
            if(dir==0) j = i/2;
            if(dir==1) j = 2*i;
            if(dir==2) j = 2*i+1;
            T aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = j;
        }


        Heap(){
            tamanho = 1;
            ultimoElemento = 0;
            vetor = (T*) std::malloc(sizeof(T) * 2);
        }
};









#endif
