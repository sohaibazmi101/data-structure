#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct PRIORITY_QUEUE{
    int data;
    int priority;
};

typedef struct PRIORITY_QUEUE queue;

queue QUEUE[MAX];

int size = 0;

int IS_FULL(){
    return size == MAX;
}

int IS_EMPTY(){
    return size == 0;
}

void ENQUEUE(int data, int priority){
    if(IS_FULL()){
        printf("Queue is Full\n");
        return;
    }
    int i = size - 1;
    while (i>=0 && QUEUE[i].priority > priority)
    {
        QUEUE[i+1] = QUEUE[i];
        i--;
    }
    QUEUE[i + 1].data = data;
    QUEUE[i + 1].priority = priority;
    size++;
    printf("Item Added : (%d, %d)\n",data, priority);
}

void DEQUEUE(){
    if(IS_EMPTY()){
        printf("Queue is Empty\n");
        return;
    }
    printf("Data Removed : (%d, %d)\n",QUEUE[0].data, QUEUE[0].priority);
    for(int i = 1; i < size; i++){
        QUEUE[i - 1] = QUEUE[i];
    }
    size--;
}

void DISPLAY(){
    if(IS_EMPTY()){
        printf("List is Empty\n");
        return;
    }
    printf("Priority Queue : ");
    for(int i = 0; i < size; i++){
        printf("(%d, %d), ",QUEUE[i].data, QUEUE[i].priority);
    }
    printf("\n");
}

int main(){
    int data, priority, choice;
    do{
        printf("1. EnQueue\n");
        printf("2. DeQueue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Data : ");
            scanf("%d", &data);
            printf("Enter Priority : ");
            scanf("%d",&priority);
            ENQUEUE(data, priority);
            break;
        case 2:
            DEQUEUE();
            break;
        case 3:
            if(IS_EMPTY()){
                printf("QUEUE IS EMPTY\n");
            }else{
                printf("QUEUE IS NOT EMPTY\n");
            }
            break;
        case 4:
            if(IS_FULL()){
                printf("QUEUE IS FULL\n");
            }else{
                printf("QUEUE IS NOT FULL\n");
            }
            break;
        case 5:
            DISPLAY();
            break;
        case 6:
            printf("EXITED\n\n");
            break;
        default:
            printf("Ivalid Choice\n");
            break;
        }
    }while(choice != 6);
}