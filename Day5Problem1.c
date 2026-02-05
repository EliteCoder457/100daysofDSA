/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. 
Your task is to create a single chronological log that preserves the correct order of arrivals.*/

#include <stdio.h>
int main() {
int n1, n2;
int a[50], b[50], c[100];
int i = 0, j = 0, k = 0;

printf("Enter the number of elements in first array: ");
scanf("%d", &n1);
printf("Enter the elements: ");
for (i = 0; i < n1; i++) {
    scanf("%d", &a[i]);
}


printf("Enter the number of elements in second array: ");
scanf("%d", &n2);
printf("Enter the elements: ");
for (i = 0; i < n2; i++) {
    scanf("%d", &b[i]);
}

   i = j = 0;
while (i < n1 && j < n2) {
     if (a[i] < b[j])
        c[k++] = a[i++];
    else
        c[k++] = b[j++];
}

while (i < n1)
    c[k++] = a[i++];

while (j < n2)
    c[k++] = b[j++];

printf("Merged array:\n");
for (i = 0; i < k; i++)
    printf("%d ", c[i]);

    return 0;
}
