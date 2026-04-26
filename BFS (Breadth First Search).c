/* Q) BFS (Breadth First Search) Implementation */

#include <stdio.h>

int visited[10];
int queue[10];
int front = -1, rear = -1;
int graph[10][10];
int vertices;

void BFS(int start) {
    int i;
    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        start = queue[++front];
        printf("%d ", start);

        for (i = 0; i < vertices; i++) {
            if (graph[start][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
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

    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start);

    return 0;
}