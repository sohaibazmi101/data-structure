#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct QUEUE{
    int items[MAX];
    int front, rear;
};

void INITIALIZE(struct QUEUE* q){
    q->front = -1;
    q->rear = -1;
}

void ENQUEUE(struct QUEUE* q, int data);
int DEQUEUE(struct QUEUE* q);
int FRONT(struct QUEUE* q);
int IS_EMPTY(struct QUEUE* q);
int IS_FULL(struct QUEUE* q);
void PRINT_LIST(struct QUEUE* q){
    if(IS_EMPTY(q)){
        printf("List is Empty\n");
        return;
    }
    for(int i = q->front; i <= q->rear; i++){
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main(){
    int choice, data;
    struct QUEUE q;
    INITIALIZE(&q);
    do{
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. PRINT LIST\n");
        printf("7. EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter data : ");
            scanf("%d",&data);
            ENQUEUE(&q, data);
        }
        else if(choice == 2){
            printf("Data DEQUEUED : %d\n", DEQUEUE(&q));
        }else if(choice == 3){
            printf("Front ELEMENTS : %d\n",FRONT(&q));
        }else if(choice == 4){
            if(IS_EMPTY(&q)){
                printf("QUEUE IS EMPTY\n");
            }else{
                printf("QUEUE IS NOT EMPTY\n");
            }
        }else if(choice == 5){
            if(IS_FULL(&q)){
                printf("QUEUE IS FULL\n");
            }else {
                printf("QUEUE IS NOT FULL\n");
            }
        }else if(choice == 6){
            PRINT_LIST(&q);
        }
        
        else if(choice == 7){
            printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<EXITED>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
        }else{
            printf("Invalid Choice\n");
        }
    }while(choice != 7);
}

int IS_EMPTY(struct QUEUE* q){
    return q->front == -1 || q->front > q->rear;
}

int IS_FULL(struct QUEUE* q){
    return q->rear == MAX - 1;
}

int FRONT(struct QUEUE* q){
    return q->items[q->front];
}

void ENQUEUE(struct QUEUE* q, int data){
    if(IS_FULL(q)){
        printf("Queue is FULL\n");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->items[++q->rear] = data;
    printf("Enqueued : %d\n",data);
}

int DEQUEUE(struct QUEUE* q){
    if(IS_EMPTY(q)){
        printf("Queue is Empty\n");
        return -1;
    }
    int item = q->items[q->front++];
    if(q->front > q->rear){
        q->front = q->rear = -1;
    }
    return item;
}