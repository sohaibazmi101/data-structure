#include<stdio.h>

int BINARY_SEARCH(int arr[], int low, int high, int key);

int main(){
    int n, key;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] < arr[j]){
                printf("Array is Not Sorted\n");
                return -1;
            }
        }
    }
    printf("Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }printf("\n");
    printf("Enter the search key : ");
    scanf("%d", &key);
    int item = BINARY_SEARCH(arr, 0, n, key);
    if(item != -1){
        printf("Item %d Found\n", item);
    }else{
        printf("Item Not found\n");
    }
    return 0;
}

int BINARY_SEARCH(int arr[], int low, int high, int key){
    while (low<=high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key){
            return key;
        }else if(arr[mid] > key){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}