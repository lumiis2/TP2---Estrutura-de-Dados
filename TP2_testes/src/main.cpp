#include "../include/Heap.hpp"
#include "../include/Graph.hpp"
#include "../include/GraphAdj.hpp"
#include "../include/GraphMatrix.hpp"
#include "../include/Point.hpp"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
typedef long double ld;

using namespace std;

const long double INF = 0x3f3f3f3f3f3f3f3f;

Point* points;
long double** dist;
Graph* trail;
Graph* portal;


int n, m, k, q;
ld s;

Pair<ld, Pair<int, int>> build(ld a, int b, int c){
    return Pair<ld, Pair<int, int>>(a, Pair<int, int>(b, c));
}

void dijkstra(){
    dist[0][0] = 0;
    Heap<Pair<ld, Pair<int, int>>> pq;
    pq.insert(build(0, 0, 0));

    while(pq.size()){
        int vertexIn = pq.top().second.first;
        if(vertexIn==n-1) return;
        Point vertex = points[pq.top().second.first];
        int rest = pq.top().second.second;
        ld distance = pq.top().first;
        pq.pop();
        if(dist[vertexIn][rest] < distance) continue;

        int* aux = trail->getNeighborhood(vertexIn);
        for(int i = 0; i < trail->getNeighborhoodSize(vertexIn); i++){
            ld newDistance = distance + vertex.distanceTo(points[aux[i]]);
            if(dist[aux[i]][rest] > newDistance){
                dist[aux[i]][rest] = newDistance;
                pq.insert(build(newDistance, aux[i], rest));
            }
        }

        free(aux);
        if(rest >= q) continue;
        aux = portal->getNeighborhood(vertexIn);
        for(int i = 0; i < portal->getNeighborhoodSize(vertexIn); i++){
            if(dist[aux[i]][rest+1] > distance){
                dist[aux[i]][rest+1] = distance;
                pq.insert(build(distance, aux[i], rest+1));
            }
        }
    }
}

void Astar(){
    dist[0][0] = 0;
    Heap<Pair<ld, Pair<int, int>>> pq;
    pq.insert(build(0, 0, 0));

    while(pq.size()){
        int vertexIn = pq.top().second.first;
        if(vertexIn==n-1) return;
        Point vertex = points[pq.top().second.first];
        int rest = pq.top().second.second;
        ld distance = pq.top().first;
        pq.pop();
        if(dist[vertexIn][rest] < distance-vertex.distanceTo(points[n-1])) continue;

        int* aux = trail->getNeighborhood(vertexIn);
        for(int i = 0; i < trail->getNeighborhoodSize(vertexIn); i++){
            ld newDistance = distance + vertex.distanceTo(points[aux[i]]);
            if(dist[aux[i]][rest] > newDistance){
                dist[aux[i]][rest] = newDistance;
                pq.insert(build(newDistance+vertex.distanceTo(points[n-1]), aux[i], rest));
            }
        }

        free(aux);
        if(rest >= q) continue;
        aux = portal->getNeighborhood(vertexIn);
        for(int i = 0; i < portal->getNeighborhoodSize(vertexIn); i++){
            if(dist[aux[i]][rest+1] > distance){
                dist[aux[i]][rest+1] = distance;
                pq.insert(build(distance, aux[i], rest+1));
            }
        }
    }
}

int main(){
    cin >> n >> m >> k;   
    points = (Point*) std::malloc(n * sizeof(Point));

    dist = (ld**) std::malloc(n * sizeof(ld*));
    for(int i = 0; i < n; i++){
        dist[i] = (ld*)std::malloc((k+1)*sizeof(ld));
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < k+1; j++) dist[i][j] = INF;



    for(int i = 0; i < n; i++){
        ld a, b; cin >> a >> b;
        points[i] = Point(a, b);
    }

    

    bool useAdj = true;

    if(useAdj){
        trail = new GraphAdj(n);
        portal = new GraphAdj(n);
    }else{
        trail = new GraphMatrix(n);
        portal = new GraphMatrix(n);
    }

    

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        trail->addEdge(a, b);
    }

    


    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        portal->addEdge(a, b);
    }   

    

    cin >> s >> q;

    dijkstra();
    ld ansd = INF;
    for(int i = 0; i <= k; i++) ansd = min(ansd, dist[n-1][i]);


    for(int i = 0; i < n; i++)
        for(int j = 0; j < k+1; j++) dist[i][j] = INF;

    
    Astar();
    ld ansa = INF;
    for(int i = 0; i <= k; i++) ansa = min(ansa, dist[n-1][i]);
  

    if(ansd-s <= 0.000001) cout << 1 << " ";
    else cout << 0 << " ";

    if(ansa-s <= 0.000001) cout << 1 << endl;
    else cout << 0 << endl;

}