#include <stdio.h>

int main() {
    int m, n;
    
 
    if (scanf("%d %d", &m, &n) != 2) {
        return 1; 
    }
    
    long long sum = 0; 
    int current_element;
    

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &current_element);
            
            
            if (i == j) {
                sum += current_element;
            }
        }
    }
    
   
    printf("%lld\n", sum);
    
    return 0;
}
