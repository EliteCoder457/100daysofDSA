#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long val1 = *(long long*)a;
    long long val2 = *(long long*)b;
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    long long *prefix_sums = (long long *)malloc((n + 1) * sizeof(long long));
    if (prefix_sums == NULL) return 1;

    prefix_sums[0] = 0;
    long long current_sum = 0;

    for (int i = 1; i <= n; i++) {
        long long val;
        scanf("%lld", &val);
        current_sum += val;
        prefix_sums[i] = current_sum;
    }

    qsort(prefix_sums, n + 1, sizeof(long long), compare);

    long long count = 0;
    long long streak = 1;

    for (int i = 1; i <= n; i++) {
        if (prefix_sums[i] == prefix_sums[i - 1]) {
            streak++;
        } else {
            count += (streak * (streak - 1)) / 2;
            streak = 1;
        }
    }
    count += (streak * (streak - 1)) / 2;

    printf("%lld\n", count);

    free(prefix_sums);
    return 0;
}
