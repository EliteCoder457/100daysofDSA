//350. Intersection of Two Arrays II
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
    // Sort both arrays
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int i = 0, j = 0, k = 0;

    int minSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(minSize * sizeof(int));

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            result[k++] = nums1[i];
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    *returnSize = k;   
    return result;
}
