/*
Q3. Write a C program to implement Greedy Activity Selection Algorithm
to select maximum number of non-overlapping activities.
*/

#include <stdio.h>

int main() {
    int start[]  = {1, 3, 0, 5, 8, 5, 6};
    int finish[] = {2, 4, 6, 7, 9, 9, 10};
    int n = 7;

    int last = 0;

    printf("Selected Activities:\n");
    printf("A%d\n", 1); // First activity always selected

    for (int i = 1; i < n; i++) {
        if (start[i] >= finish[last]) {
            printf("A%d\n", i + 1);
            last = i;
        }
    }

    return 0;
}