#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct {
    int weight[MAX_VERTICES][MAX_VERTICES];  // матриця ваг ребер
    int vertices;
} Graph;

// Ініціалізація графа
void initGraph(Graph *g, int v) {
    g->vertices = v;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j)
                g->weight[i][j] = 0;
            else
                g->weight[i][j] = INF;  // немає ребра
        }
    }
}

// Додавання зважено ребра
void addEdge(Graph *g, int u, int v, int w) {
    g->weight[u][v] = w;
    g->weight[v][u] = w;  // для неорієнтованого графа
}

// Знаходження вершини з мінімальною відстанню серед невідвіданих
int minDistance(int dist[], int visited[], int vertices) {
    int minDist = INF;
    int minVertex = -1;
    
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] < minDist) {
            minDist = dist[v];
            minVertex = v;
        }
    }
    return minVertex;
}

// Алгоритм Дейкстри
void dijkstra(Graph *g, int src) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int prev[MAX_VERTICES];
    
    // Ініціалізація
    for (int i = 0; i < g->vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
        prev[i] = -1;
    }
    dist[src] = 0;
    
    // Основний цикл
    for (int count = 0; count < g->vertices - 1; count++) {
        // Знаходимо вершину з мінімальною відстанню
        int u = minDistance(dist, visited, g->vertices);
        
        if (u == -1) break;
        
        visited[u] = 1;
        
        // Релаксація ребер
        for (int v = 0; v < g->vertices; v++) {
            if (!visited[v] && 
                g->weight[u][v] != INF && 
                dist[u] != INF && 
                dist[u] + g->weight[u][v] < dist[v]) {
                
                dist[v] = dist[u] + g->weight[u][v];
                prev[v] = u;
            }
        }
    }
    
    // Виведення результатів
    printf("Dijkstra's Algorithm - Shortest Path from vertex %d:\n\n", src);
    printf("Vertex | Distance\n");
    printf("-------|----------\n");
    for (int i = 0; i < g->vertices; i++) {
        if (dist[i] == INF)
            printf("   %d   |    INF\n", i);
        else
            printf("   %d   |    %d\n", i, dist[i]);
    }
}

int main() {
    Graph g;
    initGraph(&g, 6);
    
    // Додавання ребер (u, v, вага)
    addEdge(&g, 0, 1, 4);
    addEdge(&g, 0, 2, 2);
    addEdge(&g, 1, 2, 1);
    addEdge(&g, 1, 3, 5);
    addEdge(&g, 2, 3, 8);
    addEdge(&g, 2, 4, 10);
    addEdge(&g, 3, 4, 2);
    addEdge(&g, 3, 5, 6);
    addEdge(&g, 4, 5, 3);
    
    dijkstra(&g, 0);
    
    return 0;
}