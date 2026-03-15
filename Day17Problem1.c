#include <stdio.h>

int main() {
    int n;
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0; 
    }
    
    int current_element;
    int max_val, min_val;
    
    scanf("%d", &current_element);
    max_val = current_element;
    min_val = current_element;
    
    
    for (int i = 1; i < n; i++) {
        scanf("%d", &current_element);
        
    
        if (current_element > max_val) {
            max_val = current_element;
        }
        
     
        if (current_element < min_val) {
            min_val = current_element;
        }
    }
    

    printf("Max: %d\n", max_val);
    printf("Min: %d\n", min_val);
    
    return 0;
}
