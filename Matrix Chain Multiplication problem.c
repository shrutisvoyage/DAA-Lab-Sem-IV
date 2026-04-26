/* Q) Develop a program so that it can solve the Matrix Chain Multiplication problem. */

#include <stdio.h>
#include <limits.h>

int main() {
    // Array dimensions for matrices
    int P[5] = {12, 8, 15, 10, 25}; 
    int n = 4; // Number of matrices
    int m[5][5];
    int i, j, k, len;

    // Initialize diagonal to 0 (cost is 0 when multiplying one matrix)
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // len is the chain length
    for (len = 2; len <= n; len++) {
        for (i = 1; i <= n - len + 1; i++) {
            j = i + len - 1;
            m[i][j] = INT_MAX; // Initializing minimum cost to infinity

            for (k = i; k < j; k++) {
                // q = cost/scalar multiplications
                int cost = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];
                
                if (cost < m[i][j]) {
                    m[i][j] = cost; // Update if found a smaller cost
                }
            }
        }
    }

    printf("\n Matrix Table: \n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i > j) {
                printf("%10s", " ");
            } else {
                printf("%10d ", m[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n Min cost = %d\n", m[1][n]);
    return 0;
}Matrix Chain Multiplication problem