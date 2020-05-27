#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funtzioak.h"
#include "dijkstra.h"

void matrizeaOsatu(char* str) {
    FILE* fp;

    fp = fopen(str, "r");
    if (fp != NULL) {
        memoriaErreserbatu();
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                fscanf(fp, "%d", &cost[i][j]);
                if (cost[i][j] == 0)
                    cost[i][j] = INF;
            }
        }
    }
}

void dijkstra() {
    int nearest;

    init();
    for (int i = 0; i < V; i++) {
        nearest = getNearest();
        *(visited + nearest) = 1;

        for (int adj = 0; adj < V; adj++) {
            if (cost[nearest][adj] != INF && distance[adj] > distance[nearest] + cost[nearest][adj]) {
                distance[adj] = distance[nearest] + cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}

void init() {
    for (int i = 0; i < V; i++) {
        *(visited + i) = 0;
        *(distance + i) = INF;
        *(parent + i) = 1;
    }
    *(distance + hasi) = 0;
}

int getNearest() {
    int minValue = INF;
    int minNode = 0;

    for (int i = 0; i < V; i++) {
        if (distance[i] < minValue && visited[i] == 0) {
            minValue = distance[i];
            minNode = i;
        }
    }
    return minNode;
}