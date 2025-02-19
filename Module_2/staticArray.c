#include<stdio.h>

int main(){
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array Elements : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Array Elements : ");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}