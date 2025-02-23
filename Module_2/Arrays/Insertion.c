#include<stdio.h>

#define N 100

void INSERT(int arr[], int n, int pos, int value);

void DELETE(int arr[], int n, int pos);

int SEARCHING(int arr[], int n, int data);

int main(){

    int n, pos, value;
    int choice;

    printf("Enter the size of Array : ");
    scanf("%d", &n);

    int arr[N];

    for(int i = 0; i < n; i++){
        arr[i] = i * 10 +5;
    }

    printf("Original Array is : ");

    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }

    do{
        printf("\n1. For Insertion\n");
        printf("2. For Deletion\n");
        printf("3. For Searching\n");
        printf("4. Exit\n\n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);

        if(choice == 1){
            printf("Enter the position of value : ");
            scanf("%d", &pos);
            printf("Enter the value : ");
            scanf("%d", &value);
            INSERT(arr, n, pos, value);
            printf("\n\nArray after insertion : ");
            printf("\n\n");
            for(int i = 0; i <= n; i++){
                printf("%d ",arr[i]);
            }
        }

        else if(choice == 2){
            printf("Enter the position of Element : ");
            scanf("%d", &pos);
            DELETE(arr, n, pos);
        }

        else if(choice == 3){
            printf("Enter data value to be searched : ");
            scanf("%d", &value);
            if(SEARCHING(arr, n, value) != -1){
                printf("Data Found in array : %d", SEARCHING(arr,n,value));
            }
            else{
                printf("Data NOT found");
            }
        }

        else{
            printf("Invalid Statement");
        }
    }while(choice != 4);

    return 0;
}

void INSERT(int arr[], int n, int pos, int value){

    if(pos < 0 || pos > n){
        printf("Invalid Index");
        return;
    }

    for(int i = n; i > pos; i--){
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    n = n+1;
    printf("Value %d inserted Successfully", value);

}

void DELETE(int arr[], int n, int pos){

    if(pos < 0 || pos >=n){
        printf("Invalid Index");
        return;
    }

    for(int i = pos; i < n - 1; i++){
        arr[i] = arr[i + 1];
    }
    n = n-1;
    printf("Element %d Deleted Successfully\n", arr[pos]);
    printf("Array After Deletion : ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int SEARCHING(int arr[], int n, int data){
    for(int i = 0; i < n; i++){
        if(data == arr[i]){
            return arr[i];
        }
    }
    return -1;
}