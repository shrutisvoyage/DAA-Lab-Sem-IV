/* Q) Assembly Scheduling: 
   Company 1 = {10, 12, 6, 7, 11}
   Company 2 = {11, 8, 9, 7, 8}
   t1 (transfer from line 1 to 2) = {2, 3, 1, 3}
   t2 (transfer from line 2 to 1) = {2, 1, 2, 2}
   Find the min cost.
*/

#include <stdio.h>

int min(int a, int b) {
    if (a > b)
        return b;
    else
        return a;
}

int main() {
    int n = 5, i;
    int Company1[] = {10, 12, 6, 7, 11};
    int Company2[] = {11, 8, 9, 7, 8};
    int t1[] = {2, 3, 1, 3};
    int t2[] = {2, 1, 2, 2};
    int e1 = 3, e2 = 5;   // Entry times
    int ex1 = 2, ex2 = 1; // Exit times
    int f1[n], f2[n];

    // Base case: time taken to leave first station
    f1[0] = e1 + Company1[0];
    f2[0] = e2 + Company2[0];

    for (i = 1; i < n; i++) {
        f1[i] = min(f1[i - 1] + Company1[i], f2[i - 1] + t2[i - 1] + Company1[i]);
        f2[i] = min(f2[i - 1] + Company2[i], f1[i - 1] + t1[i - 1] + Company2[i]);
    }

    // Final result including exit times
    int result = min(f1[n - 1] + ex1, f2[n - 1] + ex2);
    printf("Minimum time is %d\n", result);

    return 0;
}