#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "Node.h" // Inclui o cabeçalho da classe Node

/**
 * @brief Classe template para representar uma lista encadeada.
 * 
 * @tparam T Tipo dos dados armazenados na lista.
 */
template <typename T>
class LinkedList {
public:
    Node<T>* head; ///< Ponteiro para o primeiro nó da lista.
    Node<T>* tail; ///< Ponteiro para o último nó da lista.

    /**
     * @brief Construtor padrão.
     * Inicializa a lista com head e tail como nullptr.
     */
    LinkedList();

    /**
     * @brief Destrutor.
     * Remove todos os nós da lista.
     */
    ~LinkedList();

    /**
     * @brief Construtor de cópia.
     * Copia os nós de outra lista encadeada.
     * 
     * @param other Outra lista encadeada para copiar.
     */
    LinkedList(const LinkedList<T>& other);

    /**
     * @brief Operador de atribuição.
     * Copia os nós de outra lista encadeada.
     * 
     * @param other Outra lista encadeada para copiar.
     * @return Referência para a lista atualizada.
     */
    LinkedList<T>& operator=(const LinkedList<T>& other);

    /**
     * @brief Insere um novo nó no final da lista.
     * 
     * @param data Dados a serem inseridos na lista.
     */
    void insert(const T& data);

    /**
     * @brief Verifica se um dado existe na lista.
     * 
     * @param data Dados a serem verificados.
     * @return true se o dado existir na lista, false caso contrário.
     */
    bool Exists(const T& data);

    /**
     * @brief Conta o número de elementos na lista.
     * 
     * @return Número de elementos na lista.
     */
    int Count();

    /**
     * @brief Imprime os elementos da lista.
     */
    void Print();

    /**
     * @brief Remove todos os nós da lista.
     */
    void clear();

    /**
     * @brief Retorna o ponteiro para o início da lista.
     * 
     * @return Ponteiro para o primeiro nó.
     */
    Node<T>* begin() const;

    /**
     * @brief Retorna um ponteiro nulo indicando o fim da lista.
     * 
     * @return Ponteiro nulo.
     */
    Node<T>* end() const;
};

// Implementação das funções da classe LinkedList

// Construtor padrão: inicializa head e tail como nullptr
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

// Insere um novo nó no final da lista
template <typename T>
void LinkedList<T>::insert(const T& data) {
    Node<T>* newNode = new Node<T>(data); // Cria um novo nó
    if (!head) { // Se a lista estiver vazia
        head = tail = newNode; // head e tail apontam para o novo nó
        return;
    }
    tail->next = newNode; // O próximo do tail atual aponta para o novo nó
    tail = newNode; // tail agora aponta para o novo nó
}

// Verifica se um dado existe na lista
template <typename T>
bool LinkedList<T>::Exists(const T& data) {
    Node<T>* current = head; // Começa do início da lista
    while (current != nullptr) { // Percorre até o final da lista
        if (current->data == data) { // Se encontrar o dado
            return true; // Retorna verdadeiro
        }
        current = current->next; // Move para o próximo nó
    }
    return false; // Se não encontrar, retorna falso
}

// Conta o número de elementos na lista
template <typename T>
int LinkedList<T>::Count() {
    int count = 0; // Inicializa o contador
    Node<T>* current = head; // Começa do início da lista
    while (current != nullptr) { // Percorre até o final da lista
        count++; // Incrementa o contador
        current = current->next; // Move para o próximo nó
    }
    return count; // Retorna o número de elementos
}

// Imprime os elementos da lista
template <typename T>
void LinkedList<T>::Print() {
    Node<T>* current = head; // Começa do início da lista
    while (current != nullptr) { // Percorre até o final da lista
        std::cout << current->data << " "; // Imprime o dado
        current = current->next; // Move para o próximo nó
    }
    std::cout << std::endl; // Nova linha após imprimir todos os elementos
}

// Construtor de cópia: copia os nós de outra lista
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr) {
    Node<T>* current = other.head; // Começa do início da outra lista
    while (current != nullptr) { // Percorre até o final da outra lista
        insert(current->data); // Insere cada dado na nova lista
        current = current->next; // Move para o próximo nó da outra lista
    }
}

// Destrutor: limpa a lista chamando clear()
template <typename T>
LinkedList<T>::~LinkedList() {
    clear(); // Remove todos os nós da lista
}

// Remove todos os nós da lista
template <typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) { // Enquanto a lista não estiver vazia
        Node<T>* temp = head; // Armazena o ponteiro para o nó atual
        head = head->next; // Move o head para o próximo nó
        delete temp; // Deleta o nó atual
    }
    head = nullptr; // Certifica-se de que a cabeça seja nullptr após limpar a lista
    tail = nullptr; // Certifica-se de que a cauda seja nullptr após limpar a lista
}

// Operador de atribuição: copia os nós de outra lista
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this == &other) return *this; // Verifica auto-atribuição

    // Limpa a lista existente
    clear();

    // Copia os nós da outra lista
    Node<T>* current = other.head; // Começa do início da outra lista
    while (current != nullptr) { // Percorre até o final da outra lista
        insert(current->data); // Insere cada dado na nova lista
        current = current->next; // Move para o próximo nó da outra lista
    }

    return *this; // Retorna a lista atualizada
}

// Retorna o ponteiro para o início da lista
template <typename T>
Node<T>* LinkedList<T>::begin() const {
    return head; // Ponteiro para o primeiro nó
}

// Retorna um ponteiro nulo indicando o fim da lista
template <typename T>
Node<T>* LinkedList<T>::end() const {
    return nullptr; // Ponteiro nulo indicando o final
}

#endif
