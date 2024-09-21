#ifndef ADJLIST_H
#define ADJLIST_H

#include "Graph.h"
#include "Edge.h"
#include "LinkedList.h"

/**
 * @brief Classe que representa um grafo utilizando uma lista de adjacência.
 * 
 * A lista de adjacência é uma estrutura que armazena as arestas de um grafo usando um vetor de listas
 * onde cada lista contém as arestas conectadas a um vértice específico.
 */
class AdjList : public Graph {
private:
    LinkedList<Edge>* list; ///< Lista de adjacência onde cada elemento é uma lista de arestas conectadas a um vértice.

public:
    /**
     * @brief Construtor da classe AdjList.
     * 
     * Inicializa a lista de adjacência para o número de vértices fornecido.
     * 
     * @param numVertices Número de vértices no grafo.
     * @param numEdges Número de arestas no grafo.
     * @param numPortals Número de portais (arestas com peso 0) no grafo.
     */
    AdjList(int numVertices, int numEdges, int numPortals);

    /**
     * @brief Destrutor da classe AdjList.
     * 
     * Libera a memória alocada para a lista de adjacência.
     */
    ~AdjList();

    /**
     * @brief Verifica se um vértice existe na lista de adjacência.
     * 
     * @param v Índice do vértice a ser verificado.
     * @return Retorna verdadeiro se o vértice existe, falso caso contrário.
     */
    bool exists(int v);

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
     * @brief Adiciona uma aresta à lista de adjacência.
     * 
     * Implementa a função virtual da classe base Graph para adicionar uma aresta com o peso especificado.
     * 
     * @param u Vértice de origem da aresta.
     * @param v Vértice de chegada da aresta.
     * @param weight Peso da aresta.
     */
    void addEdge(int u, int v, double weight) override;
};

#endif // ADJLIST_H
