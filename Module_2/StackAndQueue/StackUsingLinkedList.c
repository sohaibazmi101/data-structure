#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

int IS_EMPTY();
void PUSH(int data);
int POP();
int PEEK();
void PRINT_STACK();

int main(){
    int data, choice;
    do{
        printf("\n1. Push\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. Is Empty?\n");
        printf("5. Print Stack\n");
        printf("6. EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter your data : ");
            scanf("%d", &data);
            PUSH(data);
        }else if(choice == 2){
            printf("Data %d Poped OUT\n",POP());
        }else if(choice == 3){
            printf("Peek is %d\n", PEEK());
        }else if(choice == 4){
            if(IS_EMPTY()){
                printf("List is EMPTY\n");
            }else{
                printf("List is NOT EMPTY\n");
            }
        }else if(choice == 5){
            PRINT_STACK();
        }else if(choice == 6){
            printf("\n..................EXITED....................\n\n");
        }else{
            printf("Invalid Choice\n");
        }
    }while(choice != 6);
}

int IS_EMPTY(){
    if(top == NULL){
        return 1;
    }
    return 0;
}

void PUSH(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation Failed! Stack over Flow\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("Data %d Pushed in Stack\n",data);
}

int POP(){
    if(IS_EMPTY()){
        printf("Stack is Empty\n");
        return -1;
    }
    struct node* temp = top;
    int poped_data = temp->data;
    top = top->next;
    free(temp);
    return poped_data;
}

int PEEK(){
    if(IS_EMPTY()){
        printf("Stack is Empty\n");
        return -1;
    }
    return top->data;
}

void PRINT_STACK(){
    if(IS_EMPTY()){
        printf("Stack is Empty\n");
        return;
    }
    struct node* temp = top;
    printf("Stack is : ");
    while(temp != NULL){
        printf("%d --> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}