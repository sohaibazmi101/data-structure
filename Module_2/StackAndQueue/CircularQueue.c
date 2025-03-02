#include<stdio.h>
#include<stdlib.h>

# define MAX 6

struct Queue
{
    int items[MAX];
    int front, rear;
};

typedef struct Queue queue;

void INIT(queue* q){
    q->front = -1;
    q->rear = -1;
}

int IS_EMPTY(queue* q){
    return q->front == -1;
}

int IS_FULL(queue* q){
    return (q->rear + 1) % MAX == q->front;
}

void ENQUEUE(queue* q, int data){
    if(IS_FULL(q)){
        printf("Queue is Full\n");
        return;
    }
    if(IS_EMPTY(q)){
        q->front = 0;
    }
    q->rear = (q->rear + 1)%MAX;
    q->items[q->rear] = data;
    printf("Data %d Inserted Successfully\n",data);
}

int DEQUEUE(queue* q){
    if (IS_EMPTY(q))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if(q->front == q->rear){
        q->front = q->rear = -1;
    }else{
        q->front = (q->front + 1) % MAX;
    }
    return item;
}

void PRINT_LIST(queue* q){
    if(IS_EMPTY(q)){
        printf("List is Empty\n");
        return;
    }
    printf("List Item : ");
    for(int i = q->front; i <= q->rear; i++){
        printf("%d ",q->items[i]);
    }
    printf("\n");
}

int main(){
    int data, choice;
    queue q;
    INIT(&q);
    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. IsFull\n");
        printf("5. Print List\n");
        printf("6. EXIT\n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data value : ");
            scanf("%d", &data);
            ENQUEUE(&q, data);
            break;
        case 2:
            printf("Item Dequeue : %d\n", DEQUEUE(&q));
            break;
        case 3:
            if(IS_EMPTY(&q)){
                printf("Queue is Empty\n");
            }else{
                printf("Queue is not Empty\n");
            }
            break;
        case 4:
            if(IS_FULL(&q)){
                printf("Queue is Full\n");
            }else{
                printf("Queue is NOT Full\n");
            }
            break;
        case 5:
            PRINT_LIST(&q);
            break;
        case 6 :
            printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<EXITED>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (choice != 6);
}