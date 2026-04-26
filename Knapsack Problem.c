/* Q) Develop a program so that it can solve the 0/1 Knapsack Problem. */

#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {
    int n, W, i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    printf("Enter values: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter weights: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int result = knapsack(W, wt, val, n);
    printf("Maximum value = %d\n", result);

    return 0;
}