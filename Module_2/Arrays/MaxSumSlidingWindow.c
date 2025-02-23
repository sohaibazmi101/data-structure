#include<stdio.h>

int SLIDING_WINDOW(int arr[], int n, int k);

int main(){
    int n, k;
    printf("Enter the size of Array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Entered Array is : ");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");

    printf("Enter the size of sub array : ");
    scanf("%d", &k);

    if(SLIDING_WINDOW(arr, n, k) != -1){
        printf("Sum of Sub array of size of %d is %d\n",k, SLIDING_WINDOW(arr, n, k));
    }else{
        printf("Size of Sub array is out of BOUND\n");
    }
}

int SLIDING_WINDOW(int arr[], int n, int k){
    if(k < 0 || k > n){
        return -1;
    }
    int maxSum = 0;
    int windowSum = 0;
    for(int i = 0; i < k; i++){
        windowSum = windowSum + arr[i];
    }
    maxSum = windowSum;
    for(int i = k; i < n; i++){
        windowSum = windowSum + arr[i] - arr[i-k];
        if(windowSum > maxSum){
            maxSum = windowSum;
        }
    }
    return maxSum;
}