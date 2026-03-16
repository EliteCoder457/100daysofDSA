#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    
    int min_abs_sum = INT_MAX;
    int best_left = 0;
    int best_right = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < min_abs_sum) {
            min_abs_sum = abs(sum);
            best_left = arr[left];
            best_right = arr[right];
        }

        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            break;
        }
    }

    printf("%d %d\n", best_left, best_right);

    free(arr);
    return 0;
}
