#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the size of Array : ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter array Elements : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Dynamic Array Elements Are : ");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }

    printf("\n");

    free(arr);

    printf("Dynamic Array Elements Are : ");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}