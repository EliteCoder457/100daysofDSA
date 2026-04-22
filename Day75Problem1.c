#include <stdio.h>

#define MAX 1000

int main() {
    int arr[MAX], n;
    
    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, maxLen = 0;

    // Simple hash arrays (since C doesn't have built-in map)
    int hash[2001];  // to store prefix sums
    int index[2001];

    for (int i = 0; i < 2001; i++) {
        hash[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        int key = sum + 1000;  // shift to avoid negative index

        if (hash[key] == 1) {
            int len = i - index[key];
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            hash[key] = 1;
            index[key] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}
