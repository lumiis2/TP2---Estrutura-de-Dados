#include "Graph.h"
#include <iostream>

/**
 * @brief Construtor da classe Graph.
 * 
 * Inicializa o grafo com o número de vértices, arestas e portais fornecidos.
 * Aloca memória para o vetor de vértices, onde cada vértice é representado por um objeto da classe Point.
 * 
 * @param numVertices Número de vértices no grafo.
 * @param numEdges Número de arestas no grafo.
 * @param numPortals Número de portais (arestas com peso 0) no grafo.
 */
Graph::Graph(int numVertices, int numEdges, int numPortals)
    : n(numVertices), m(numEdges), p(numPortals) {
    vertices = new Point[n]; // Aloca memória para o vetor de vértices
}

/**
 * @brief Destrutor da classe Graph.
 * 
 * Libera a memória alocada para o vetor de vértices, evitando vazamentos de memória.
 */
Graph::~Graph() {
    delete[] vertices; // Libera a memória alocada para o vetor de vértices
}

/**
 * @brief Retorna o número de vértices no grafo.
 * 
 * @return O número de vértices no grafo.
 */
int Graph::getNumVertices() const {
    return n; // Retorna o número de vértices
}

/**
 * @brief Retorna o número de arestas no grafo.
 * 
 * @return O número de arestas no grafo.
 */
int Graph::getNumArestas() const {
    return m; // Retorna o número de arestas
}

/**
 * @brief Retorna um vértice pelo seu índice.
 * 
 * Se o índice fornecido estiver dentro dos limites válidos, retorna o vértice correspondente.
 * Caso contrário, exibe uma mensagem de erro e retorna um ponto vazio ou nulo.
 * 
 * @param id Índice do vértice a ser retornado.
 * @return O vértice correspondente ao índice fornecido.
 */
Point Graph::getPoint(int id) const {
    if (id >= 0 && id < n) {
        return vertices[id]; // Retorna o vértice se o índice estiver dentro dos limites
    } else {
        std::cerr << "Invalid vertex id" << std::endl; // Exibe uma mensagem de erro se o índice for inválido
        return Point(); // Retorna um ponto vazio ou nulo
    }
}
