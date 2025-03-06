#include<stdio.h>
#include<stdlib.h>

#define CACHE_CAPACITY 3

struct Node{
    int key, value;
    struct Node *next, *prev;
};
typedef struct Node Node;

struct HashMap{
    Node* nodes[100];
};
typedef struct HashMap HashMap;

Node* head = NULL;
Node* tail = NULL;

HashMap cache;
int cacheSize = 0;

Node* CREATE_NODE(int key, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void MOVE_TO_HEAD(Node* node){
    if(node == head)return;
    if(node->prev) node->prev->next = node->next;
    if(node->next) node->next->prev = node->prev;
    if(node == tail) tail = node->prev;
    node->next = head;
    node->prev = NULL;
    if(head) node->prev = head;
    head = node;
    if(!tail) tail = head;
}

void REMOVE_LRU(){
    if(!tail){
        return;
    }
    cache.nodes[tail->key] = NULL;
    if(tail->prev) tail->prev->next = NULL;
    Node* temp = tail;
    tail = tail->prev;
    if(!tail) head = NULL;
    free(temp);
    cacheSize--;
}

void PUT(int key, int value){
    Node* existingNode = cache.nodes[key];
    if(existingNode){
        existingNode->value = value;
        MOVE_TO_HEAD(existingNode);
        return;
    }
    if(cacheSize == CACHE_CAPACITY){
        REMOVE_LRU();
    }
    Node* newNode = CREATE_NODE(key, value);
    newNode->next = head;
    if(head) head->prev = newNode;
    head = newNode;
    if(!tail) tail = head;
    cache.nodes[key] = newNode;
    cacheSize++;
}

int GET(int key){
    Node* node = cache.nodes[key];
    if(!node){
        printf("Key %d Not found in cache\n", key);
        return -1;
    }
    MOVE_TO_HEAD(node);
    return node->value;
}

void DISPLAY_CACHE(){
    Node* temp = head;
    printf("Cache : ");
    while(temp){
        printf("(%d, %d) ", temp->key, temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int key, value, choice;
    do{
        printf("1. PUT\n");
        printf("2. Get\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter Key : ");
                scanf("%d", &key);
                printf("Enter value : ");
                scanf("%d", &value);
                PUT(key, value);
                break;
            case 2:
                printf("Enter key : ");
                scanf("%d", &key);
                printf("Accessing Key %d : %d\n", key, GET(key));
                break;
            case 3:
                DISPLAY_CACHE();
                break;
            case 4:
                printf("Exiting\n\n");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }while(choice != 4);
}