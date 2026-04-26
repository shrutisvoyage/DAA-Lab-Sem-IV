/* Q) DFS (Depth First Search) Implementation */

#include <stdio.h>

int visited[10];
int graph[10][10];
int vertices;

void DFS(int start) {
    int i;
    printf("%d ", start);
    visited[start] = 1;

    for (i = 0; i < vertices; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix: \n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array to 0
    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

    return 0;
}