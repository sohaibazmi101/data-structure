#include<stdio.h>

#define MAX 100

struct Element{
    int value;
};
typedef struct Element Element;

void PRINT_ARRAY(Element arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i].value);
    }printf("\n");
}

void BUBBLE_SORT(Element arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(arr[j].value > arr[j + 1].value){
                Element temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void SELECTION_SORT(Element arr[], int size){
    for(int i = 0; i < size - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j].value < arr[minIndex].value){
                minIndex = j;
            }
        }
        Element temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void INSERTION_SORT(Element arr[], int size){
    for(int i = 1; i < size; i++){
        Element key = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j].value > key.value)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void MERGE(Element arr[], int mid, int left, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Element L[n1], R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(L[i].value <= R[j].value){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void MERGE_SORT(Element arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;
        MERGE_SORT(arr, left, mid);
        MERGE_SORT(arr, mid + 1, right);
        MERGE(arr, mid, left, right);
    }
}

int main(){
    Element arr[MAX];
    printf("Enter Array Elements : (to quit enter -1) : ");
    int element, size = 0;
    int i = 0;
    do
    {
        scanf("%d",&element);
        if(element != -1){
            arr[i].value = element;
            size++;
        }
        i++;
    }while(element!=-1);
    MERGE_SORT(arr, 0, size - 1);
    PRINT_ARRAY(arr, size);
}