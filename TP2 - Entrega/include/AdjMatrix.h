#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include "LinkedList.h"
#include "Graph.h"
#include "Edge.h"

/**
 * @brief Classe que representa um grafo utilizando uma matriz de adjacência.
 * 
 * A matriz de adjacência é uma estrutura que armazena as arestas de um grafo em uma matriz onde
 * o elemento (i, j) representa o peso da aresta entre os vértices i e j.
 */
class AdjMatrix : public Graph { 

private:
    double **matrix; ///< Matriz de adjacência.

public:
    /**
     * @brief Construtor da classe AdjMatrix.
     * 
     * Inicializa uma matriz de adjacência com o número de vértices fornecido.
     * 
     * @param numVertices Número de vértices no grafo.
     * @param numEdges Número de arestas no grafo.
     * @param numPortals Número de portais (arestas com peso 0) no grafo.
     */
    AdjMatrix(int numVertices, int numEdges, int numPortals);

    /**
     * @brief Destrutor da classe AdjMatrix.
     * 
     * Libera a memória alocada para a matriz de adjacência.
     */
    ~AdjMatrix();

    /**
     * @brief Verifica se um vértice existe na matriz de adjacência.
     * 
     * @param vertex Índice do vértice a ser verificado.
     * @return Retorna verdadeiro se o vértice existe, falso caso contrário.
     */
    bool exists(int vertex);

    /**
     * @brief Retorna a lista de vizinhos de um vértice.
     * 
     * Implementa a função virtual da classe base Graph para retornar os vizinhos do vértice v.
     * 
     * @param v Índice do vértice cujo vizinhos serão retornados.
     * @return Lista de arestas conectadas ao vértice v.
     */
    LinkedList<Edge> neighbors(int v) const override;

    /**
     * @brief Adiciona uma aresta à matriz de adjacência.
     * 
     * Implementa a função virtual da classe base Graph para adicionar uma aresta com o peso especificado.
     * 
     * @param u Vértice de origem da aresta.
     * @param v Vértice de chegada da aresta.
     * @param weight Peso da aresta.
     */
    void addEdge(int u, int v, double weight) override;

    /**
     * @brief Imprime a matriz de adjacência no console.
     * 
     * Este método exibe a matriz de adjacência, mostrando as conexões e pesos entre os vértices.
     */
    void printMatrix() const;

};

#endif // ADJMATRIX_H
