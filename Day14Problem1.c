#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    
    bool isIdentity = true;
    int current_element;
    
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &current_element);
            
          
            if (i == j && current_element != 1) {
                isIdentity = false;
            }
          
            else if (i != j && current_element != 0) {
                isIdentity = false;
            }
        }
    }
    
   
    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }
    
    return 0;
}
