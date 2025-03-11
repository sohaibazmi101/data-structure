#include<stdio.h>

#define MAX_SIZE 100

struct PriorityQueue{
    int arr[MAX_SIZE];
    int size;
};

typedef struct PriorityQueue PQ;

void HEAPIFYUP(PQ* pq, int index);
void HEAPIFYDOWN(PQ* pq, int index);
void INSERT(PQ* pq, int value);
void PRINT(PQ* pq);
int DELETE(PQ* pq);
void SWAP(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    PQ pq;
    pq.size = 0;
    int data, choice;
    do{
        printf("1. Insert\n2. Delete\n3. Print\n4. Exit\n");
        printf("ENter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter your data : ");
            scanf("%d", &data);
            INSERT(&pq, data);
            break;
        case 2:
            DELETE(&pq);
            break;
        case 3:
            PRINT(&pq);
            break;
        case 4:
            printf("Exited\n\n");
            break;
        default:
            printf("Invalid Chocie\n");
            break;
        }
    }while(choice != 4);
    return 0;
}

void HEAPIFYUP(PQ* pq, int index){
    int parent = (index - 1)/2;
    if(index > 0 && pq->arr[index] < pq->arr[parent]){
        SWAP(&pq->arr[index], &pq->arr[parent]);
        HEAPIFYUP(pq, parent);
    }
}

void HEAPIFYDOWN(PQ* pq, int index){
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int smallest = index;

    if(left < pq->size && pq->arr[left] < pq->arr[smallest]){
        smallest = left;
    }
    if(right < pq->size && pq->arr[right] < pq->arr[smallest]){
        smallest = right;
    }
    if(smallest != index){
        SWAP(&pq->arr[index], &pq->arr[smallest]);
        HEAPIFYDOWN(pq, smallest);
    }
}

void INSERT(PQ* pq, int value){
    if(pq->size >= MAX_SIZE){
        printf("Queue is Full\n");
        return;
    }
    pq->arr[pq->size] = value;
    HEAPIFYUP(pq, pq->size);
    pq->size++;
}

void PRINT(PQ* pq){
    if(pq->size == 0){
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue : ");
    for(int i = 0; i < pq->size; i++){
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

int DELETE(PQ* pq){
    if(pq->size == 0){
        printf("Queue is Empty\n");
        return -1;
    }
    int minValue = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    HEAPIFYDOWN(pq, 0);
    return minValue;
}