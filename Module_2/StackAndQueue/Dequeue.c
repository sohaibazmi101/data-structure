#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct DEQUEUE{
    int items[MAX];
    int front, rear;
};

typedef struct DEQUEUE Dequeue;

void INIT(Dequeue* d){
    d->front = -1;
    d->rear = -1;
}

int IS_EMPTY(Dequeue* d){
    return d->front == -1;
}

int IS_FULL(Dequeue* d){
    return (d->front == 0 && d->rear == MAX - 1) || (d->front == d->rear + 1);
}

void INSERT_FRONT(Dequeue* d, int data){
    if(IS_FULL(d)){
        printf("Dequeue is Full\n");
        return;
    }
    if(IS_EMPTY(d)){
        d->front = d->rear = 0;
    }else if(d->front == 0){
        d->front = MAX - 1;
    }else{
        d->front = d->front - 1;
    }
    d->items[d->front] = data;
    printf("Data %d Inserted Sucessfully\n", data);
}

void INSERT_REAR(Dequeue* d, int data){
    if(IS_FULL(d)){
        printf("Dequeue is Full\n");
        return;
    }
    if(IS_EMPTY(d)){
        d->front = d->rear = 0;
    }else if(d->rear == MAX - 1){
        d->rear = 0;
    }else{
        d->rear = d->rear + 1;
    }
    d->items[d->rear] = data;
    printf("Dequeue is Full\n");
}

int DELETE_FRONT(Dequeue* d){
    if(IS_EMPTY(d)){
        printf("List is Empty\n");
        return -1;
    }
    int item = d->items[d->front];
    if(d->front == MAX - 1){
        d->front = 0;
    }else if(d->front == d->rear){
        d->front = d->rear = -1;
    }else{
        d->front = d->front + 1;
    }
    return item;
}

int DELETE_REAR(Dequeue* d){
    if(IS_EMPTY(d)){
        printf("Dequeue is Empty\n");
        return -1;
    }
    int item = d->items[d->rear];
    if(d->rear == 0){
        d->rear = MAX - 1;
    }else if(d->front == d->rear){
        d->front = d->rear = -1;
    }else{
        d->rear = d->rear - 1;
    }
    return item;
}

int GET_FRONT(Dequeue* d){
    if(IS_EMPTY(d)){
        printf("Dequeue is Empty\n");
        return -1;
    }else{
        return d->items[d->front];
    }
}

int GET_REAR(Dequeue* d){
    if(IS_EMPTY(d)){
        printf("Dequeue is Empty\n");
        return -1;
    }else{
        return d->items[d->rear];
    }
}

void PRINT_LIST(Dequeue* d){
    if(IS_EMPTY(d)){
        printf("List is Empty\n");
        return;
    }
    printf("Items : ");
    if(d->front > d->rear){
        for(int i = d->front; i <= MAX - 1; i++){
            printf("%d ",d->items[i]);
        }
        for(int i = 0; i <= d->rear; i++){
            printf("%d ",d->items[i]);
        }
        printf("\n");
        return;
    }
    for(int i = d->front; i <= d->rear; i++){
        printf("%d ",d->items[i]);
    }
    printf("\n");
}

int main(){
    int data, choice;
    Dequeue d;
    INIT(&d);
    do{
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Is Empty\n");
        printf("6. Is Full\n");
        printf("7. Get Front\n");
        printf("8. Get Rear\n");
        printf("9. Print List\n");
        printf("10. EXIT\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Data : ");
            scanf("%d", &data);
            INSERT_FRONT(&d, data);
            break;
        case 2:
            printf("Enter Data : ");
            scanf("%d", &data);
            INSERT_REAR(&d, data);
            break;
        case 3:
            printf("Data %d Deleted\n", DELETE_FRONT(&d));
            break;
        case 4:
            printf("Data %d Deleted\n", DELETE_REAR(&d));
            break;
        case 5:
            if(IS_EMPTY(&d)){
                printf("Dequeue is Empty\n");
            }else{
                printf("Dequeue is Not Empty\n");
            }
            break;
        case 6:
            if(IS_FULL(&d)){
                printf("Dequeue is FULL\n");
            }else{
                printf("Dequeue is Not Full\n");
            }
            break;
        case 7:
            printf("Front : %d\n", GET_FRONT(&d));
            break;
        case 8:
            printf("Rear : %d\n", GET_REAR(&d));
            break;
        case 9:
            PRINT_LIST(&d);
            break;
        case 10:
            printf("<<<<<<<<<<<<<<EXITED>>>>>>>>>>>>>\n\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }while(choice != 10);
}