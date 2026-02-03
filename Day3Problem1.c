/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.*/

#include <stdio.h>
int main(){
int n,arr[20],i,num,found=0,pos=-1;
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("enter the elements: ");
for(int i=0;i<n;i++){
    
    scanf("%d",&arr[i]);
}
printf("Enter the element you want to find: ");
scanf("%d",&num);
for(i=0;i<n;i++){
    if(arr[i]==num){
    found=1;
    printf("position %d",i);
    break;
}

}
if(found==0){
    printf("does not exist");
}
    return 0;
}
