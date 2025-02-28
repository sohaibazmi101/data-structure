#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE* next;
};

int INSERT_END(struct NODE** head, int data){
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    struct NODE* temp = *head;
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return newNode->data;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return newNode->data;
}

int DELETE_BEGIN(struct NODE** head){
    if(*head == NULL){
        printf("No data in List\n");
        return -1;
    }
    struct NODE* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

void PRINT_LIST(struct NODE* head){
    struct NODE* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NUL\n");
}

int main(){
    struct NODE* head = NULL;
    int data, choice;
    do
    {
        printf("1. Insert at End\n");
        printf("2. Delete Begin\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("Enter your Choice : ");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Entr data to insert : ");
            scanf("%d",&data);
            printf("%d is Inserted\n",INSERT_END(&head, data));
        }
        else if(choice == 2){
            printf("%d Deleted\n",DELETE_BEGIN(&head));
        }
        else if(choice == 3){
            PRINT_LIST(head);
        }else{
            printf("Invalid Choice");
        }
    } while (choice != 4);
}