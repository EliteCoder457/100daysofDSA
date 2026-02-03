//Missing in Array

int missingNum(int *arr, int size) {
    int total,missing,sum=0;
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    total=(size+1)*(size+2)/2;
    missing=total-sum;
    return missing;
}
