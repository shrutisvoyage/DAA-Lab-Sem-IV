#include <stdio.h>

int main() {
    int n, key, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Index %d : Found\n", i);
        } else {
            printf("Index %d : Not Found\n", i);
        }
    }

    return 0;
}