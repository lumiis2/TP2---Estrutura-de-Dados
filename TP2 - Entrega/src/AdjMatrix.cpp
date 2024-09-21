#include "AdjMatrix.h"
#include "Graph.h"

const double INF = 0x3f3f3f3f3f; 

/**
 * @brief Construtor da classe AdjMatrix.
 * 
 * Inicializa a matriz de adjacência para o número de vértices fornecido.
 * Aloca memória para a matriz e define todos os pesos como -1.0, indicando que não há arestas.
 * 
 * @param numVertices Número de vértices no grafo.
 * @param numEdges Número de arestas no grafo (não utilizado diretamente na inicialização).
 * @param numPortals Número de portais (arestas com peso 0) no grafo (não utilizado diretamente na inicialização).
 */
AdjMatrix::AdjMatrix(int numVertices, int numEdges, int numPortals)
    : Graph(numVertices, numEdges, numPortals) {
    // Inicializa a matriz de adjacência
    matrix = new double*[numVertices]; // Aloca memória para o vetor de linhas da matriz
    for (int i = 0; i < numVertices; i++) {
        matrix[i] = new double[numVertices]; // Aloca memória para cada linha da matriz
        for (int j = 0; j < numVertices; j++) {
            matrix[i][j] = INF; // Inicializa todos os pesos como INF
        }
    }
}

/**
 * @brief Destrutor da classe AdjMatrix.
 * 
 * Libera a memória alocada para a matriz de adjacência, evitando vazamentos de memória.
 */
AdjMatrix::~AdjMatrix() {
    // Libera a memória alocada para a matriz de adjacência
    for (int i = 0; i < n; i++) {
        delete[] matrix[i]; // Libera a memória de cada linha
    }
    delete[] matrix; // Libera a memória do vetor de linhas
}

/**
 * @brief Verifica se um vértice existe na matriz de adjacência.
 * 
 * Verifica se o índice do vértice está dentro dos limites válidos da matriz.
 * 
 * @param vertex Índice do vértice a ser verificado.
 * @return Retorna verdadeiro se o vértice existe, falso caso contrário.
 */
bool AdjMatrix::exists(int vertex) {
    // Verifica se o vértice está dentro dos limites válidos
    return vertex >= 0 && vertex < n;
}

/**
 * @brief Retorna a lista de vizinhos de um vértice na matriz de adjacência.
 * 
 * Cria uma lista de arestas conectadas ao vértice fornecido, ignorando arestas com peso zero.
 * 
 * @param v Índice do vértice cujo vizinhos serão retornados.
 * @return Lista de arestas conectadas ao vértice v.
 */
LinkedList<Edge> AdjMatrix::neighbors(int v) const {
    LinkedList<Edge> neighborsList;
    // Itera sobre todas as colunas da linha v para encontrar vizinhos
    for (int i = 0; i < n; i++) {
        if (matrix[v][i] != INF) { // Se existe uma aresta com peso não zero e não inicial
            neighborsList.insert(Edge(i, matrix[v][i])); // Adiciona a aresta à lista de vizinhos
        }
    }
    return neighborsList;
}

/**
 * @brief Adiciona uma aresta à matriz de adjacência.
 * 
 * Atualiza os valores da matriz para refletir a adição de uma aresta entre dois vértices com o peso especificado.
 * 
 * @param u Vértice de origem da aresta.
 * @param v Vértice de chegada da aresta.
 * @param weight Peso da aresta.
 * @throws std::invalid_argument Se algum dos vértices for inválido (fora dos limites).
 */
void AdjMatrix::addEdge(int u, int v, double weight) {
    if (!exists(u) || !exists(v)) {
        throw std::invalid_argument("Vértices inválidos."); // Verifica a validade dos vértices
    }
    matrix[u][v] = weight; // Adiciona a aresta na matriz
}

/**
 * @brief Imprime a matriz de adjacência e informações sobre a memória utilizada.
 * 
 * Exibe a matriz de adjacência no console e calcula o número de bytes utilizados e desperdiçados.
 */
void AdjMatrix::printMatrix() const {
    int usedBytes = 0; // Inicializa o contador de bytes utilizados
    int wastedBytes = 0; // Inicializa o contador de bytes desperdiçados

    std::cout << "Matriz de Adjacência:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " "; // Imprime o valor da célula
            if (matrix[i][j] == 0.0) {
                usedBytes += sizeof(double); // Conta bytes utilizados para arestas com peso 0
            } else if (matrix[i][j] == -1.0) {
                wastedBytes += sizeof(double); // Conta bytes desperdiçados para arestas não inicializadas
            }
        }
        std::cout << std::endl; // Nova linha após imprimir todos os elementos de uma linha
    }
    std::cout << "Bytes utilizados: " << usedBytes << std::endl;
    std::cout << "Bytes desperdiçados: " << wastedBytes << std::endl;
}
