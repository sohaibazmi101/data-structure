#include<stdio.h>

#define MAX 100

struct Element{
    int value;
};
typedef struct Element Element;

void SWAP(Element *a, Element *b);

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

int PARTITION(Element arr[], int low, int high) {
    Element pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].value < pivot.value) {
            i++;
            SWAP(&arr[i], &arr[j]);
        }
    }
    SWAP(&arr[i + 1], &arr[high]);
    return i + 1;
}

void QUICK_SORT(Element arr[], int low, int high){
    if(low < high){
        int pivot = PARTITION(arr, low, high);
        QUICK_SORT(arr, low, pivot - 1);
        QUICK_SORT(arr, pivot + 1, high);
    }
}

void HEAPIFY(Element arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left].value > arr[largest].value){
        largest = left;
    }
    if(right < n && arr[right].value > arr[largest].value){
        largest = right;
    }
    if(largest != i){
        SWAP(&arr[i], &arr[largest]);
        HEAPIFY(arr, n, largest);
    }
}

void HEAP_SORT(Element arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        HEAPIFY(arr, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        SWAP(&arr[0], &arr[i]);
        HEAPIFY(arr, i, 0);
    }
}


void SWAP(Element *a, Element *b){
    Element temp = *a;
    *a = *b;
    *b = temp;
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
    HEAP_SORT(arr, size);
    PRINT_ARRAY(arr, size);
}