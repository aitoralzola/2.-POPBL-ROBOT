#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 999

//V -> numero de vertices
//cost -> matriz
//src -> donde empieza
//visited -> si ya esta visitado ese nodo

int V = 12, src = 0, cost[100][100];
int dist[100];
int visited[100] = { 0 };
int parent[100];

void getMatrixKanpoaldea();
void getMatrixBarrualdea();
int getNearest();
void dijkstra();
void init();
void display();

int main(int argc, char** argv) {
    int aukera;

    scanf("%d", &aukera);

    switch (aukera) {
    case 1: V = 12;
        getMatrixBarrualdea();
        break;
    case 2: V = 7;
        getMatrixKanpoaldea();
        break;
    }

    init();
    dijkstra();
    display();
}

void getMatrixBarrualdea() {
    FILE* fp;

    fp = fopen("matriz_barrualdea.txt", "r");
    if (fp != NULL) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                fscanf(fp, "%d", &cost[i][j]);
                if (cost[i][j] == 0)
                    cost[i][j] = INF;
            }
        }
    }
}

void getMatrixKanpoaldea() {
    FILE* fp;

    fp = fopen("matriz_terraza.txt", "r");
    if (fp != NULL) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                fscanf(fp, "%d", &cost[i][j]);
                if (cost[i][j] == 0)
                    cost[i][j] = INF;
            }
        }
    }
}

int getNearest() {
    int minValue = INF;
    int minNode = 0;

    for (int i = 0; i < V; i++) {
        if (dist[i] < minValue && visited[i] == 0) {
            minValue = dist[i];
            minNode = i;
        }
    }
    return minNode;
}

void dijkstra() {
    int nearest;
    for (int i = 0; i < V; i++) {
        nearest = getNearest();
        visited[nearest] = 1;
        
        for (int adj = 0; adj < V; adj++) {
            if (cost[nearest][adj] != INF && dist[adj] > dist[nearest] + cost[nearest][adj]) {
                dist[adj] = dist[nearest] + cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}

void init() {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = 1;
    }
    dist[src] = 0;
}

void display() {
    
    printf("Node:\t\tCost:\t\tPath:");
    for (int i = 1; i < V; i++) {
        printf("\n%d\t\t%d\t\t ", i, dist[i]);
        printf("%d", i);
        int parnode = parent[i];
        while (parnode != src) {
            printf(" <- %d ", parnode);
            parnode = parent[parnode];
        }
    }
}