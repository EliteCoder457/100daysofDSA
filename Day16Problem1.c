#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    
    if (scanf("%d", &n) != 1) {
        return 1; 
    }

    if (n <= 0) {
        return 0;
    }
    
  
    int *arr = (int *)malloc(n * sizeof(int));
    int *visited = (int *)calloc(n, sizeof(int)); 
    
    if (arr == NULL || visited == NULL) {
        return 1; 
    }
    
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    

    for (int i = 0; i < n; i++) {
        
        if (visited[i] == 1) {
            continue;
        }
        
        int count = 1;
       
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1; 
                count++;
            }
        }
        
 
        printf("%d:%d ", arr[i], count);
    }
    printf("\n");
    
    // Free allocated memory
    free(arr);
    free(visited);
    
    return 0;
}
