#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int* answer = (int*)malloc(numsSize * sizeof(int));
    if (answer == NULL) {
        return NULL; 
    }
    
    answer[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        
        answer[i] = answer[i - 1] * nums[i - 1];
    }
    

    int right_product = 1;
    
  
    for (int i = numsSize - 1; i >= 0; i--) {
        
        answer[i] = answer[i] * right_product;
        
        
        right_product *= nums[i];
    }
    
    return answer;
}
