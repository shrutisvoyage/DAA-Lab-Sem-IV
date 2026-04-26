#include <stdio.h>

void modifiedBubbleSort(int a[], int n) {
    int i, j, temp, flag;

    for(i = 0; i < n - 1; i++) {
        flag = 0;

        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }

        if(flag == 0) {
            break;
        }
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[50];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    modifiedBubbleSort(a, n);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}