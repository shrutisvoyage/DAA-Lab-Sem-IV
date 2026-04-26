/* 
Question: Write a C program to sort non-negative integers using Count Sort.
*/

#include <stdio.h>

int main() {
    int arr[100], count[100] = {0}, output[100];
    int n, i, max = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (non-negative only):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }

    // Count frequency
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Cumulative count
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Build output array
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }

    return 0;
}