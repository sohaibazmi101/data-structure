#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

void add_at_beg(node **head);
void display(node *head);
void add_at_end(node *head);
void del_at_beg(node **head);
void del_at_end(node *head);
void del_at_pos(node *head, int pos);

int main()
{
    node *head;
    head = (node *)malloc(sizeof(node));

    if (head != NULL)
    {
        head->data = 1;
        head->next = NULL;
    }

    add_at_beg(&head);
    add_at_beg(&head);
    add_at_beg(&head);
    add_at_end(head);
    display(head);
    // printf("\nDeletion at Beginning\n");
    // del_at_beg(&head);
    // display(head);
    // printf("\nDeletion at end\n");
    // del_at_end(head);
    // display(head);
    // printf("\n");
    int pos;
    printf("ENTER POS : ");
    scanf("%d",&pos);
    del_at_pos(head, pos);
    display(head);
    return 0;
}

void display(node *head)
{
    node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void add_at_beg(node **head)
{
    int val;
    printf("Enter the Number : ");
    scanf("%d", &val);
    node *temp;
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
        return;
    temp->data = val;
    temp->next = *head;
    *head = temp;
}
void add_at_end(node *head)
{
    int val;
    printf("Add Element at End : ");
    scanf("%d", &val);
    node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    ptr->next = temp;
}

void del_at_beg(node **head){
    node *temp;
    temp = *head;
    *head = temp->next;
    free(temp);
    temp = NULL;
}

void del_at_end(node *head){
    node *ptr, *prev;
    ptr = head;
    prev = NULL;
    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    free(ptr);
    ptr->next = NULL;
}

void del_at_pos(node *head, int pos){
    if(*head == NULL){
        printf("List is Empty.\n");
        return;
    }
    if(pos == 0){
        node *temp = *head;
        *head = temp->next;
        free(temp);
    }
    node *current;
    current = *head;
    for(int i = 0; current != NULL && i < pos - 1; i++){
        current = current->next;
    }
    if(current == NULL || current->next == NULL){
        printf("Position out of bound\n");
        return;
    }
    node *target = current->next;
    current->next = target->next;
    free(target);
}