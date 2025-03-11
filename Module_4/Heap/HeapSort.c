#include<stdio.h>

#define MAX_SIZE 100

struct Heap{
    int arr[MAX_SIZE];
    int size;
};
typedef struct Heap Heap;

void HEAPIFY(Heap* heap, int index, int size);
void INSERT(Heap* heap, int data);
void SORT(Heap* heap);
void PRINT(Heap* heap);
void SWAP(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char const *argv[])
{
    int choice, data;
    Heap heap;
    heap.size = 0;
    do{
        printf("1. Insert\n2. Sort\n3. Print\n4. EXIT\n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert : ");
            scanf("%d", &data);
            INSERT(&heap, data);
            break;
        case 2:
            SORT(&heap);
            break;
        case 3:
            PRINT(&heap);
            break;
        case 4:
            printf("Exited\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }while(choice != 4);
    return 0;
}

void HEAPIFYUP(Heap* heap, int index){
    int parent = (index - 1)/2;
    if(index > 0 && heap->arr[parent] < heap->arr[index]){
        SWAP(&heap->arr[index], &heap->arr[parent]);
        index = parent;
        HEAPIFYUP(heap, parent);
    }
}

void HEAPIFY(Heap* heap, int index, int size){
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int largest = index;

    if(left < size && heap->arr[left] > heap->arr[largest]){
        largest = left;
    }
    if(right < size && heap->arr[right] > heap->arr[largest]){
        largest = right;
    }
    if(largest != index){
        SWAP(&heap->arr[largest], &heap->arr[index]);
        HEAPIFY(heap, largest, size);
    }
}

void INSERT(Heap* heap, int data){
    if(heap->size == MAX_SIZE){
        printf("Heap is Full\n");
        return;
    }
    heap->arr[heap->size] = data;
    HEAPIFYUP(heap, heap->size);
    heap->size++;
}
void SORT(Heap* heap){
    int originalSize = heap->size;
    for(int i = heap->size/2 -1; i >=0; i--){
        HEAPIFY(heap, i, heap->size);
    }
    for(int i = heap->size - 1; i > 0; i--){
        SWAP(&heap->arr[0], &heap->arr[i]);
        HEAPIFY(heap, 0, i);
    }
    heap->size = originalSize;
}
void PRINT(Heap* heap){
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