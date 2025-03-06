#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10

struct Node{
    int key;
    int value;
    struct Node* next;
};

typedef struct Node Node;

Node* hashTable[TABLE_SIZE];

int HASH_FUNCTION(int key);
void INSERT(int key, int value);
int SEARCH(int key);
void DELETE_KEY(int key);
void DISPLAY();

int main(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = NULL;
    }
    int data, key, choice;
    do{
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. EXIT\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter key : ");
            scanf("%d", &key);
            printf("Enter Value : ");
            scanf("%d", &data);
            INSERT(key, data);
            break;
        case 2:
            printf("Enter key : ");
            scanf("%d",&key);
            if(SEARCH(key) != -1){
                printf("Value : %d\n", SEARCH(key));
            }else{
                printf("Not Found for Key %d\n", key);
            }
            break;
        case 3:
            printf("Enter key : ");
            scanf("%d", &key);
            DELETE_KEY(key);
            break;
        case 4:
            DISPLAY();
            break;
        case 5:
            printf("EXITED\n\n");break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }while(choice != 5);
}

int HASH_FUNCTION(int key){
    return key % TABLE_SIZE;
}

void INSERT(int key, int value){
    int index = HASH_FUNCTION(key);
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    if(hashTable[index] == NULL){
        hashTable[index] = newNode;
    }else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

int SEARCH(int key){
    int index = HASH_FUNCTION(key);
    Node* temp = hashTable[index];
    while (temp)
    {
        if(temp->key == key){
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void DELETE_KEY(int key){
    int index = HASH_FUNCTION(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;
    int found = 0;
    while (temp)
    {
        if(temp->key == key){
            if(prev == NULL){
                hashTable[index] = temp->next;
            }else{
                prev->next = temp->next;
            }
            free(temp);
            printf("Key %d Deleted\n", key);
            found = 1;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d Not found\n",key);
}

void DISPLAY(){
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("Index %d : ",i);
        Node* temp = hashTable[i];
        while (temp)
        {
            printf("(%d, %d) --> ",temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}