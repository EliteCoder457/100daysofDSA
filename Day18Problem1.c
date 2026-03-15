#include <stdio.h>
#include <stdlib.h>

void reverse(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;
    

    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }
    
   
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1; 
    }
    
   
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
  
    if (scanf("%d", &k) != 1) {
        free(arr);
        return 1;
    }
    
    // Normalize k in case it is larger than the array size
    k = k % n;
    
    // Only perform rotations if k is greater than 0
    if (k > 0) {
        // Step 1: Reverse the entire array
        reverse(arr, 0, n - 1);
        
        // Step 2: Reverse the first k elements
        reverse(arr, 0, k - 1);
        
        // Step 3: Reverse the remaining elements
        reverse(arr, k, n - 1);
    }
    
    // Print the rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr
