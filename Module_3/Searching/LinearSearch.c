#include<stdio.h>

int LINEAR_SEARCH(int arr[], int n, int key);

int main(){
    int n, key;
    printf("Enter the size of Array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array Elements : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Array Elements : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter the Key for search : ");
    scanf("%d", &key);
    if(LINEAR_SEARCH(arr, n, key) == -1){
        printf("Not Found in Array\n");
    }else{
        printf("%d Found at %d\n", arr[LINEAR_SEARCH(arr, n, key)], LINEAR_SEARCH(arr, n, key));
    }
    
}

int LINEAR_SEARCH(int arr[], int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}