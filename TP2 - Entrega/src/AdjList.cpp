#include "AdjList.h"
#include "Node.h"
#include <iostream> 

/**
 * @brief Construtor da classe AdjList.
 * 
 * Inicializa a lista de adjacência para o número de vértices fornecido.
 * Aloca memória para o vetor de listas de adjacência, onde cada lista representa
 * os vizinhos de um vértice.
 * 
 * @param numVertices Número de vértices no grafo.
 * @param numEdges Número de arestas no grafo (não utilizado diretamente na inicialização).
 * @param numPortals Número de portais (arestas com peso 0) no grafo (não utilizado diretamente na inicialização).
 */
AdjList::AdjList(int numVertices, int numEdges, int numPortals)
    : Graph(numVertices, numEdges, numPortals) {
    list = new LinkedList<Edge>[numVertices]; // Aloca memória para o vetor de listas de adjacência
}

/**
 * @brief Destrutor da classe AdjList.
 * 
 * Libera a memória alocada para o vetor de listas de adjacência, evitando vazamentos de memória.
 */
AdjList::~AdjList() {
    delete[] list; // Libera a memória alocada para o vetor de listas
}

/**
 * @brief Verifica se um vértice existe na lista de adjacência.
 * 
 * Verifica se o índice do vértice está dentro dos limites válidos do vetor de listas.
 * 
 * @param v Índice do vértice a ser verificado.
 * @return Retorna verdadeiro se o vértice existe, falso caso contrário.
 */
bool AdjList::exists(int v) {
    return v >= 0 && v < n; // Verifica se o índice está dentro dos limites
}

/**
 * @brief Retorna a lista de vizinhos de um vértice na lista de adjacência.
 * 
 * Cria uma lista de arestas conectadas ao vértice fornecido. Se o vértice estiver fora dos limites,
 * uma exceção é lançada.
 * 
 * @param v Índice do vértice cujo vizinhos serão retornados.
 * @return Lista de arestas conectadas ao vértice v.
 * @throws std::out_of_range Se o índice do vértice estiver fora dos limites.
 */
LinkedList<Edge> AdjList::neighbors(int v) const {
    if (!(v >= 0 && v < n)) {
        throw std::out_of_range("Error: Vertex out of range."); // Verifica a validade do vértice
    }

    LinkedList<Edge> nbrs; // Lista para armazenar os vizinhos

    Node<Edge>* it = list[v].begin(); // Iterador para percorrer a lista de adjacência do vértice v

    while (it != list[v].end()) {
        nbrs.insert(it->data); // Adiciona o vizinho à lista de vizinhos
        it = it->next; // Move para o próximo nó
    }

    return nbrs; // Retorna a lista de vizinhos
}

/**
 * @brief Adiciona uma aresta à lista de adjacência.
 * 
 * Insere uma aresta na lista de adjacência do vértice de origem. Se o vértice de origem estiver
 * fora dos limites, uma exceção é lançada.
 * 
 * @param u Vértice de origem da aresta.
 * @param v Vértice de chegada da aresta.
 * @param weight Peso da aresta.
 * @throws std::out_of_range Se o vértice de origem estiver fora dos limites.
 */
void AdjList::addEdge(int u, int v, double weight) {
    if (!(u >= 0 && u < n)) {
        throw std::out_of_range("Error: Vertex out of range."); // Verifica a validade do vértice de origem
    }
    list[u].insert(Edge(v, weight)); // Adiciona a aresta à lista de adjacência do vértice de origem
}
