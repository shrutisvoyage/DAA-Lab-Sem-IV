#include <stdio.h>

void bubbleSort(int a[], int n) {
    int i, j, temp, k;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                printf("After swap: ");
                for(k = 0; k < n; k++) {
                    printf("%d ", a[k]);
                }
                printf("\n");
            }
        }
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    bubbleSort(a, n);

    return 0;
}