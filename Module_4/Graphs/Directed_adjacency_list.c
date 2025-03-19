#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;

Node* CREATE_NODE(int data);
void ADD_EDGE(Node* adj[], int i, int j);
void DISPLAY(Node* adj[], int V);

int main(){
    int V = 4;
    Node* adj[V];
    for(int i = 0; i<V; i++){
        adj[i] = NULL;
    }

    ADD_EDGE(adj, 0,1);
    ADD_EDGE(adj, 0, 2);
    ADD_EDGE(adj, 2, 1);

    DISPLAY(adj, V);
    return 0;
}

Node* CREATE_NODE(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void ADD_EDGE(Node* adj[], int i, int j){
    Node* newNode = CREATE_NODE(j);
    newNode->next = adj[i];
    adj[i] = newNode;
}

void DISPLAY(Node* adj[], int V){
    for(int i = 0; i< V; i++){
        Node* temp = adj[i];
        printf("%d: ",i);
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}