#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};
typedef struct Node Node;

Node* CREATE_NODE(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* BUILD_TREE(){
    int data;
    printf("Enter Data (-1 for No data) : ");
    scanf("%d", &data);
    if(data == -1){
        return NULL;
    }
    Node* newNode = CREATE_NODE(data);
    printf("Enter Left Child of %d :\n", data);
    newNode->left = BUILD_TREE();

    printf("Enter right child of %d :\n", data);
    newNode->right = BUILD_TREE();

    return newNode;
}

void PRE_ORDER_TRAVERSAL(Node* root){
    if(root != NULL){
        printf("%d ",root->data);
        PRE_ORDER_TRAVERSAL(root->left);
        PRE_ORDER_TRAVERSAL(root->right);
    }
}

void IN_ORDER_TRAVERSAL(Node* root){
    if(root != NULL){
        IN_ORDER_TRAVERSAL(root->left);
        printf("%d ",root->data);
        IN_ORDER_TRAVERSAL(root->right);
    }
}

void POST_ORDER_TRAVERSAL(Node* root){
    if(root != NULL){
        POST_ORDER_TRAVERSAL(root->left);
        POST_ORDER_TRAVERSAL(root->right);
        printf("%d ", root->data);
    }
}

int main(){

    printf("Build The Tree :\n");
    Node* root = BUILD_TREE();

    printf("\nPreorder Traversal: ");
    PRE_ORDER_TRAVERSAL(root);
    printf("\n");

    printf("Inorder Traversal: ");
    IN_ORDER_TRAVERSAL(root);
    printf("\n");

    printf("Postorder Traversal: ");
    POST_ORDER_TRAVERSAL(root);
    printf("\n");

    return 0;
    return 0;
}