#include <iostream>
#include <cmath>
#include <limits>
#include <chrono>
#include <iomanip>

#include "Graph.h"
#include "AdjList.h"
#include "AdjMatrix.h"
#include "PriorityQueue.h"
#include "Node.h"
#include "Pair.h"

using namespace std;

const long double INF = 0x3f3f3f3f3f3f3f3f; // Valor infinito para inicialização das distâncias

// Implementação do algoritmo de Dijkstra
bool Dijkstra(Graph& grafo, double energia, int portais, int n) {
    // Fila de prioridade para selecionar o próximo vértice com menor distância
    PriorityQueue<Pair<double, Pair<int, int>>> pq;

    // Matriz de distâncias para armazenar a menor distância até cada vértice
    // do vértice i usando j portais
    double** dist = new double*[n];
    for (int i = 0; i < n; ++i) {
        dist[i] = new double[portais + 1];
        for (int j = 0; j <= portais; ++j) {
            dist[i][j] = INF;
        }
    }
    dist[0][0] = 0; // Distância inicial para o vértice de origem
    pq.insert({0, {0, 0}}); // Inserção do vértice inicial na fila

    bool flag = false;
    double path_size = 0.0;

    // Laço principal do algoritmo de Dijkstra
    while(!pq.empty()){
        Pair<double, Pair<int, int>> top_pair = pq.top(); // Extrai o elemento com menor distância
        int u = top_pair.second.first; // Vértice atual
        int num_portais = top_pair.second.second; // Número de portais usados até o vértice atual
        double distance = top_pair.first; // Distância até o vértice atual
        pq.remove(); // Remove o elemento da fila

        // Verifica se chegou ao destino
        if(u == n-1) {
            if(distance <= energia) flag = true;
            break;
        }  

        // Ignora se a distância atual não é a mínima registrada
        if(dist[u][num_portais] < distance){
            continue; 
        }

        // Itera sobre os vizinhos do vértice atual
        LinkedList<Edge> neighbors = grafo.neighbors(u);
        for(Node<Edge>* it = neighbors.begin(); it != neighbors.end(); it = it->next){
            int v = it->data.v; // Vértice vizinho
            double weight = it->data.weight; // Peso da aresta
            double new_distance = distance + weight; // Nova distância até o vizinho
            int new_portals = num_portais;

            // Se a aresta for um portal
            if(weight == 0){
                if(num_portais < portais) {
                    new_portals++;
                } else continue;
            }

            // Atualiza a distância se a nova distância for menor
            if(new_distance < dist[v][new_portals]){
                dist[v][new_portals] = new_distance;
                pq.insert({new_distance, {v, new_portals}});
            }
            path_size = new_distance;
        }
    }

    // Libera a memória alocada para a matriz de distâncias
    for(int i = 0; i < n; i++) {
        delete[] dist[i];
    }
    delete[] dist;

    return flag;
}

// Implementação do algoritmo A*
bool AStar(Graph& grafo, double energia, int portais, int n) {
    // Fila de prioridade para selecionar o próximo vértice com menor distância estimada
    PriorityQueue<Pair<Pair<double, double>, Pair<int, int>>, CompareAstar<Pair<Pair<double, double>, Pair<int, int>>>> pq;

    // Matriz de distâncias para armazenar a menor distância até cada vértice
    // do vértice i usando j portais
    double** dist = new double*[n];
    for (int i = 0; i < n; ++i) {
        dist[i] = new double[portais + 1];
        for (int j = 0; j <= portais; ++j) {
            dist[i][j] = INF;
        }
    }
    dist[0][0] = 0; // Distância inicial para o vértice de origem
    pq.insert({{0,0}, {0,0}}); // Inserção do vértice inicial na fila

    bool flag = false;
    double path_size = 0.0;

    // Laço principal do algoritmo A*
    while(!pq.empty()){
        Pair<Pair<double, double>, Pair<int, int>> top_pair = pq.top(); // Extrai o elemento com menor distância estimada
        int u = top_pair.second.first; // Vértice atual
        int num_portais = top_pair.second.second; // Número de portais usados até o vértice atual
        double distance = top_pair.first.first; // Distância até o vértice atual
        pq.remove(); // Remove o elemento da fila

        // Verifica se chegou ao destino
        if(u == n-1) {
            if(distance <= energia) flag = true;
            break;
        }  

        // Ignora se a distância atual não é a mínima registrada
        if(dist[u][num_portais] < distance){
            continue; 
        }

        // Itera sobre os vizinhos do vértice atual
        LinkedList<Edge> neighbors = grafo.neighbors(u);
        for(Node<Edge>* it = neighbors.begin(); it != neighbors.end(); it = it->next){
            int v = it->data.v; // Vértice vizinho
            double weight = it->data.weight; // Peso da aresta

            // Calcula a distância euclidiana até o destino
            double euclidian_distance = grafo.getPoint(n-1).euclideanDistance(grafo.getPoint(v));
            
            double new_distance = distance + weight; // Nova distância até o vizinho
            double new_euclidean = new_distance + euclidian_distance; // Distância estimada até o destino
            int new_portals = num_portais;

            // Se a aresta for um portal
            if(weight == 0){
                if(num_portais < portais) {
                    new_portals++;
                } else continue;
            }

            // Atualiza a distância se a nova distância for menor
            if(new_distance < dist[v][new_portals]){
                dist[v][new_portals] = new_distance;
                pq.insert({{new_distance, new_euclidean}, {v, new_portals}});
            }
            path_size = new_distance;
        }
    }

    // Libera a memória alocada para a matriz de distâncias
    for(int i = 0; i < n; i++) {
        delete[] dist[i];
    }
    delete[] dist;

    return flag;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k; // Lê número de vértices, arestas e portais

    AdjList grafo(n, m, k); // Cria o grafo como lista de adjacência
    grafo.vertices = new Point[n]; // Aloca memória para os vértices
    
    // Lê as coordenadas dos vértices
    for (int i = 0; i < n; ++i) {
        cin >> grafo.vertices[i].x >> grafo.vertices[i].y;
    }

    // Lê as arestas do grafo e calcula os pesos
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        double weight = grafo.getPoint(u).euclideanDistance(grafo.getPoint(v));
        grafo.addEdge(u, v, weight);
    }

    // Lê os portais do grafo (arestas de peso zero)
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        grafo.addEdge(u, v, 0.0); 
    }

    double s;
    int q;
    cin >> s >> q; // Lê a energia disponível e o número de portais permitidos

    bool result_dijkstra = Dijkstra(grafo, s, q, n); // Executa o algoritmo de Dijkstra
    bool result_astar = AStar(grafo, s, q, n); // Executa o algoritmo A*

    // Imprime os resultados
    cout << (result_dijkstra ? 1 : 0) << " ";
    cout << (result_astar ? 1 : 0) << endl;

    return 0;
}
