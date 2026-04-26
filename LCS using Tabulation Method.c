/* Q) Find out the length of LCS using Tabulation Method. Also give the string. */

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char S1[] = "ABCBDAB";
    char S2[] = "BDCABA";
    
    int n1 = strlen(S1);
    int n2 = strlen(S2);
    int m[100][100];
    int i, j;

    // Building the LCS table
    for (i = 0; i <= n1; i++) {
        for (j = 0; j <= n2; j++) {
            if (i == 0 || j == 0) {
                m[i][j] = 0;
            } else if (S1[i - 1] == S2[j - 1]) {
                m[i][j] = 1 + m[i - 1][j - 1];
            } else {
                m[i][j] = max(m[i - 1][j], m[i][j - 1]);
            }
        }
    }

    // Printing the table
    for (i = 0; i <= n1; i++) {
        for (j = 0; j <= n2; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\n LCS length = %d", m[n1][n2]);

    // Code to find the LCS string
    int index = m[n1][n2];
    char lcs[index + 1];
    lcs[index] = '\0'; // Set terminator

    i = n1;
    j = n2;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcs[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
        } else if (m[i - 1][j] > m[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("\n LCS string = %s\n", lcs);
    return 0;
}