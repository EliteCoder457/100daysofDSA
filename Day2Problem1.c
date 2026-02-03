/*Problem: Write a C program to delete the element at a given 1-based position pos 
from an array of n integers. Shift remaining elements to the left.*/

#include <stdio.h>
int main(){
int n,i,arr[20],pos;
printf("enter number of elements of array: ");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("\n arr[%d] = ",i);
    scanf("%d",&arr[i]);
}
printf("enter the position from which element has to deleted: ");
scanf("%d",&pos);
for(i=pos;i<n-1;i++){
    arr[i]=arr[i+1];
    n--;
    printf("The array after deletion is : ");
    for(i=0;i<n;i++){
        printf("arr[%d] = %d",i,arr[i]);
    }
}
    return 0;
}
