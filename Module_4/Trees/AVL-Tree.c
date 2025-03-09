#include<stdio.h>
#include<stdlib.h>

int MAXIMUM(int a, int b) {
    return (a > b) ? a : b;
}

typedef struct Node{
    int key;
    struct Node *left, *right;
    int height;
}Node;

int HEIGHT(Node *N);
int GET_BALANCE_FACTOR(Node *N);
Node* CREATE_NODE(int key);
Node* RIGHT_ROTATE(Node *y);
Node* LEFT_ROTATE(Node* x);
Node* INSERT(Node* N, int key);
Node* MIN_VALUE_NODE(Node* N);
Node* DELETE_NODE(Node* root, int key);
void INORDER(Node* root);

int main(){
    Node* root = NULL;
    root = INSERT(root, 10);
    root = INSERT(root, 12);
    root = INSERT(root, 13);
    INORDER(root);
    return 0;

}

int HEIGHT(Node *N){
    return (N == NULL) ? 0 : N->height;
}

int GET_BALANCE_FACTOR(Node *N){
    return (N == NULL) ? 0 : HEIGHT(N->left) - HEIGHT(N->right);
}

Node* CREATE_NODE(int key){
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

Node* RIGHT_ROTATE(Node *y){
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = 1 + MAXIMUM(HEIGHT(y->left), HEIGHT(y->right));
    x->height = 1 + MAXIMUM(HEIGHT(x->right), HEIGHT(x->left));
    return x;
}

Node* LEFT_ROTATE(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->right = x;
    x->right = T2;

    x->height = 1 + MAXIMUM(HEIGHT(x->left), HEIGHT(x->right));
    y->height = 1 + MAXIMUM(HEIGHT(y->left), HEIGHT(y->right));

    return y;
}

Node* INSERT(Node* N, int key){
    if(N == NULL) return CREATE_NODE(key);

    if(key < N->key){
        N->left = INSERT(N->left, key);
    }else if(key > N->key){
        N->right = INSERT(N->right, key);
    }else {
        return N;
    }

    N->height = 1 + MAXIMUM(HEIGHT(N->right), HEIGHT(N->left));
    int balance = GET_BALANCE_FACTOR(N);

    if(balance > 1 && key < N->left->key){
        return RIGHT_ROTATE(N);
    }
    if(balance < -1 && key > N->right->key){
        return LEFT_ROTATE(N);
    }
    if(balance > 1 && key > N->left->key){
        N->left = LEFT_ROTATE(N->left);
        return RIGHT_ROTATE(N);
    }
    if(balance < -1 && key < N->right->key){
        N->right = RIGHT_ROTATE(N->right);
        return LEFT_ROTATE(N);
    }
    return N;
}
Node* MIN_VALUE_NODE(Node* node){
    Node* current = node;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}
Node* DELETE_NODE(Node* root, int key){

}
void INORDER(Node* root){
    if(root != NULL){
        INORDER(root->left);
        printf("%d ",root->key);
        INORDER(root->right);
    }
}