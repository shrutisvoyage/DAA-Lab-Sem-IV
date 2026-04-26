// Write down a searching code of
// T(n) = T(n/2) + c

#include <stdio.h>

int binarysearch(int arr[], int low, int high, int key) {
    
    if (low <= high) {
        
        int mid = (low + high) / 2;
        
        if (arr[mid] == key)
            return mid;
        
        else if (arr[mid] > key)
            return binarysearch(arr, low, mid - 1, key);
        
        else
            return binarysearch(arr, mid + 1, high, key);
    }
    
    return -1;
}

int main() {
    
    int arr[] = {5, 7, 8, 10, 15, 18};
    
    int n = 6;
    int key = 10;
    
    int pos = binarysearch(arr, 0, n - 1, key);
    
    if (pos != -1)
        printf("Element found at index %d", pos);
    else
        printf("Element not found");
    
    return 0;
}