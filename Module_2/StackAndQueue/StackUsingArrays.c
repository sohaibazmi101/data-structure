#include<stdio.h>

#define SIZE 10

int STACK[SIZE];
int top = -1;

void PUSH(int data);
int POP();
int PEEK();
int IS_EMPTY();
int IS_FULL();
void PRINT_STACK();

int main(){
    int data, choice;
    do{
        printf("\n1. For Push\n");
        printf("2. For pop\n");
        printf("3. for Peek\n");
        printf("4. Is Empty\n");
        printf("5. Is Full\n");
        printf("6. Print Stack\n");
        printf("7. EXIT\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Enter your data : ");
            scanf("%d",&data);
            PUSH(data);
        }else if(choice == 2){
            printf("Data %d Poped OUT\n",POP());
        }else if(choice == 3){
            printf("Peek Data : %d\n",PEEK());
        }else if(choice == 4){
            if(IS_EMPTY()){
                printf("Stack is EMPTY!\n");
            }else{
                printf("Stack is not Empty\n");
            }
        }else if(choice == 5){
            if(IS_FULL()){
                printf("Stack is FULL!");
            }else{
                printf("Stack is NOT FULL!\n");
            }
        }
        else if(choice == 6){
            PRINT_STACK();
        }
        else if(choice == 7){
            printf("\n...............Exited..................\n");
        }else{
            printf("Invalid Choice\n");
        }
    }while(choice != 7);
}

void PUSH(int data){
    if(IS_FULL()){
        printf("Stack Over flow\n");
        printf("%d Not Inserted\n",data);
        return;
    }
    STACK[++top] = data;
}

int POP(){
    if (IS_EMPTY())
    {
        printf("Stack under flow\n");
        return -1;
    }
    return STACK[top--];
}

int PEEK(){
    if(IS_EMPTY()){
        printf("Stack is Empty\n");
        return -1;
    }
    return STACK[top];
}

int IS_EMPTY(){
    if(top == -1){
        return 1;
    }
    return 0;
}
int IS_FULL(){
    if(top == SIZE - 1){
        return 1;
    }
    return 0;
}

void PRINT_STACK(){
    if(IS_EMPTY()){
        printf("Empty!\n");
        return;
    }
    for(int i = top; i >= 0; i--){
        printf("%d ",STACK[i]);
    }
    printf("\n");
}