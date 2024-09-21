#ifndef EDGE_H
#define EDGE_H

/**
 * @brief Estrutura que representa uma aresta em um grafo.
 * 
 * Esta estrutura armazena o vértice de chegada e o peso da aresta.
 */
struct Edge {
    int v; ///< Vértice de chegada.
    double weight; ///< Peso da aresta.

    /**
     * @brief Construtor.
     * 
     * @param v Vértice de chegada.
     * @param weight Peso da aresta.
     */
    Edge(int v, double weight) : v(v), weight(weight) {}
};

#endif // EDGE_H
