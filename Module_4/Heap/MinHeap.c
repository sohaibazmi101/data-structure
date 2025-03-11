#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct MinHeap{
    int arr[MAX_SIZE];
    int size;
};

typedef struct MinHeap MinHeap;

void SWAP(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void HEAPIFYUP(MinHeap* heap, int index);
void HEAPIFYDOWN(MinHeap* heap, int index);
void PRINT_HEAP(MinHeap* heap);
void INSERT(MinHeap* heap, int data);
void SEARCH(MinHeap* heap, int data);
int DELETE_MIN(MinHeap* heap);

int main(){
    MinHeap heap;
    heap.size = 0;
    int data, choice, del;
    do{
        printf("1. Insert\n2. Search\n3. Delete\n4. PrintHEap\n 5. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert : ");
            scanf("%d", &data);
            INSERT(&heap, data);
            break;
        case 2:
            printf("Enter data to search : ");
            scanf("%d", &data);
            SEARCH(&heap, data);
            break;
        case 3:
            del = DELETE_MIN(&heap);
            if(del != -1){
                printf("Data %d Deleted\n",del);
            }
            break;
        case 4:
            PRINT_HEAP(&heap);
            break;
        case 5:
            printf("Exited\n\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }while(choice != 5);
    return 0;
}

void HEAPIFYUP(MinHeap* heap, int index){
    int parent = (index - 1)/2;
    while (index > 0 && heap->arr[parent] > heap->arr[index])
    {
        SWAP(&heap->arr[parent], &heap->arr[index]);
        index = parent;
        parent = (index - 1)/2;
    }
}

void HEAPIFYDOWN(MinHeap* heap, int index){
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int smallest = index;
    
    if(left < heap->size && heap->arr[left] < heap->arr[smallest]){
        smallest = left;
    }
    if(right < heap->size && heap->arr[right] < heap->arr[smallest]){
        smallest = right;
    }
    if(smallest != index){
        SWAP(&heap->arr[index], &heap->arr[smallest]);
        HEAPIFYDOWN(heap, smallest);
    }
}

void PRINT_HEAP(MinHeap* heap){
    if(heap->size == 0){
        printf("Heap is Empty\n");
        return;
    }
    printf("Heap : ");
    for(int i = 0; i < heap->size; i++){
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

void INSERT(MinHeap* heap, int data){
    if(heap->size >= MAX_SIZE){
        printf("Heap Is Full\n");
        return;
    }
    heap->arr[heap->size] = data;
    HEAPIFYUP(heap, heap->size);
    heap->size++;
}

void SEARCH(MinHeap* heap, int data){
    if(heap->size == 0){
        printf("Heap is Empty\n");
        return;
    }
    for(int i = 0; i < heap->size; i++){
        if(data == heap->arr[i]){
            printf("Data %d Found\n", heap->arr[i]);
            return;
        }
    }
    printf("No Data Found : %d\n", data);
}

int DELETE_MIN(MinHeap* heap){
    if(heap->size == 0){
        printf("Heap is Empty\n");
        return -1;
    }
    int minValue = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    HEAPIFYDOWN(heap, 0);
    return minValue;
}