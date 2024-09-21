#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "Edge.h"
#include "LinkedList.h"
#include "Point.h"

/**
 * @brief Classe base para representar um grafo.
 * 
 * Esta classe fornece uma interface para grafos, com métodos para obter informações
 * sobre o grafo e manipular suas arestas. A implementação dos métodos de vizinhança
 * e adição de arestas é deixada para classes derivadas.
 */
class Graph {
public:
    Point* vertices; ///< Vetor de vértices.
    int n; ///< Número de vértices.
    int m; ///< Número de arestas.
    int p; ///< Número de portais (arestas de peso 0).

    /**
     * @brief Construtor.
     * 
     * @param numVertices Número de vértices no grafo.
     * @param numEdges Número de arestas no grafo.
     * @param numPortals Número de portais (arestas de peso 0) no grafo.
     */
    Graph(int numVertices, int numEdges, int numPortals);

    /**
     * @brief Destrutor virtual.
     */
    virtual ~Graph();

    /**
     * @brief Retorna o número de vértices no grafo.
     * 
     * @return Número de vértices.
     */
    int getNumVertices() const;

    /**
     * @brief Retorna o número de arestas no grafo.
     * 
     * @return Número de arestas.
     */
    int getNumArestas() const;

    /**
     * @brief Retorna um vértice pelo seu índice.
     * 
     * @param id Índice do vértice.
     * @return Vértice correspondente ao índice.
     */
    Point getPoint(int id) const;

    /**
     * @brief Retorna a lista de vizinhos de um vértice.
     * 
     * Método virtual puro que deve ser implementado por classes derivadas.
     * 
     * @param v Índice do vértice.
     * @return Lista de arestas que representam os vizinhos do vértice.
     */
    virtual LinkedList<Edge> neighbors(int v) const = 0;

    /**
     * @brief Adiciona uma aresta entre dois vértices.
     * 
     * Método virtual puro que deve ser implementado por classes derivadas.
     * 
     * @param u Índice do vértice de origem.
     * @param v Índice do vértice de destino.
     * @param weight Peso da aresta.
     */
    virtual void addEdge(int u, int v, double weight) = 0;
};

#endif // GRAPH_H
