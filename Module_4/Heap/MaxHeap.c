#include<stdio.h>

#define MAX_SIZE 100

struct MaxHeap{
    int arr[MAX_SIZE];
    int size;
};

typedef struct MaxHeap MaxHeap;

void SWAP(int *a, int *b);
void INSERT(MaxHeap* heap, int value);
void HEAPIFYUP(MaxHeap* heap, int index);
void HEAPIFYDOWN(MaxHeap* heap, int index);
int DELETE_MAX(MaxHeap* heap);
void SEARCH(MaxHeap* heap, int data);
void PRINT_HEAP(MaxHeap* heap);

int main(){
    MaxHeap heap;
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
            del = DELETE_MAX(&heap);
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

void SWAP(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void INSERT(MaxHeap* heap, int value){
    if(heap->size >= MAX_SIZE){
        printf("Heap is Full\n");
        return;
    }
    heap->arr[heap->size] = value;
    HEAPIFYUP(heap, heap->size);
    heap->size++;
}

void HEAPIFYUP(MaxHeap* heap, int index){
    int parent = (index - 1)/2;
    while (index > 0 && heap->arr[parent] < heap->arr[index])
    {
        SWAP(&heap->arr[parent], &heap->arr[index]);
        index = parent;
        parent = (index - 1)/2;
    }
}

void HEAPIFYDOWN(MaxHeap* heap, int index){
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int largest = index;

    if(left < heap->size && heap->arr[left] > heap->arr[largest]){
        largest = left;
    }
    if(right < heap->size && heap->arr[right] > heap->arr[largest]){
        largest = right;
    }
    if(index != largest){
        SWAP(&heap->arr[index], &heap->arr[largest]);
        HEAPIFYDOWN(heap, largest);
    }
}

int DELETE_MAX(MaxHeap* heap){
    if(heap->size == 0){
        printf("Heap is Empty\n");
        return -1;
    }
    int maxValue = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    HEAPIFYDOWN(heap, 0);
    return maxValue;
}

void SEARCH(MaxHeap* heap, int data){
    if(heap->size == 0){
        printf("heap is Empty\n");
        return;
    }
    printf("Heap : ");
    for(int i = 0; i < heap->size; i++){
        if(heap->arr[i] == data){
            printf("Data %d Found\n",heap->arr[i]);
            return;
        }
    }
    printf("No data Found %d\n", data);
}

void PRINT_HEAP(MaxHeap* heap){
    if(heap->size == 0){
        printf("Heap is Empty\n");
        return;
    }
    printf("Heap : ");
    for(int i = 0; i < heap->size; i++){
        printf("%d ",heap->arr[i]);
    }
    printf("\n");
}