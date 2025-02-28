#include<stdio.h>
#include<stdlib.h>


struct NODE{
    int data;
    struct NODE* next;
    struct NODE* previous;
};


void INSERT_END(struct NODE** head, int data){
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        newNode->previous = NULL;
        *head = newNode;
        return;
    }
    struct NODE* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->previous = temp;
}

int DELETE_BEGIN(struct NODE** head){
    if(*head == NULL){
        printf("List is Empty\n");
        return -1;
    }
    struct NODE* temp = *head;
    if(head != NULL){
        (*head)->previous = NULL;
    }
    *head = (*head)->next;
    int data = temp->data;
    free(temp);
    return data;
}

void PRINT_LIST(struct NODE* head){
    struct NODE* temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct NODE* head = NULL;
    int data, choice;
    do{
        printf("1. Insert at End.\n");
        printf("2. Delete at Begin.\n");
        printf("3. Print List.\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter your data : ");
            scanf("%d",&data);
            INSERT_END(&head, data);
            printf("Checked");
        }else if(choice == 2){
            printf("%d Deleted Successfully\n",DELETE_BEGIN(&head));
        }else if(choice == 3){
            PRINT_LIST(head);
        }else if(choice == 4){
            printf("\nExited\n\n");
        }
        else{
            printf("Invalid Choice\n");
        }
    }while(choice != 4);
}