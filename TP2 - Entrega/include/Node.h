#ifndef NODE_H
#define NODE_H

/**
 * @brief Estrutura template que representa um nó em uma lista encadeada.
 * 
 * @tparam T Tipo dos dados armazenados no nó.
 */
template <typename T>
struct Node {
    T data;      ///< Dados armazenados no nó.
    Node* next;  ///< Ponteiro para o próximo nó na lista encadeada.

    /**
     * @brief Construtor que inicializa o nó com dados fornecidos e define o próximo nó como nulo.
     * 
     * @param data Dados a serem armazenados no nó.
     */
    Node(T data) : data(data), next(nullptr) {}
};

#endif // NODE_H
