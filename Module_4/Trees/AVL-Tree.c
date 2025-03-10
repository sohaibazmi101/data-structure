#include <stdio.h>
#include <stdlib.h>

int MAXIMUM(int a, int b) {
    return (a > b) ? a : b;
}

typedef struct Node {
    int key;
    struct Node *left, *right;
    int height;
} Node;

int HEIGHT(Node *N);
int GET_BALANCE_FACTOR(Node *N);
Node* CREATE_NODE(int key);
Node* RIGHT_ROTATE(Node *y);
Node* LEFT_ROTATE(Node* x);
Node* INSERT(Node* N, int key);
Node* MIN_VALUE_NODE(Node* N);
Node* DELETE_NODE(Node* root, int key);
void INORDER(Node* root);
Node* SEARCH(Node* node, int key);

int main() {
    Node* root = NULL;
    int choice, key;
    do{
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("Enetr your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter your Key : ");
                scanf("%d", &key);
                root = INSERT(root, key);
                break;
            case 2:
                printf("Enter key to delete : ");
                scanf("%d", &key);
                root = DELETE_NODE(root, key);
                break;
            case 3:
                printf("Enter your key : ");
                scanf("%d", &key);
                SEARCH(root, key);
                break;
            case 4:
                printf("Inorder : ");
                INORDER(root);
                printf("\n");
                break;
            case 5:
                printf("Exited\n");
                break;
            default:
                printf("Invald Choice\n");
                break;
        }
    }while(choice != 5);
}

int HEIGHT(Node *N) {
    return (N == NULL) ? 0 : N->height;
}

int GET_BALANCE_FACTOR(Node *N) {
    return (N == NULL) ? 0 : HEIGHT(N->left) - HEIGHT(N->right);
}

Node* CREATE_NODE(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

Node* RIGHT_ROTATE(Node *y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + MAXIMUM(HEIGHT(y->left), HEIGHT(y->right));
    x->height = 1 + MAXIMUM(HEIGHT(x->left), HEIGHT(x->right));
    return x;
}

Node* LEFT_ROTATE(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + MAXIMUM(HEIGHT(x->left), HEIGHT(x->right));
    y->height = 1 + MAXIMUM(HEIGHT(y->left), HEIGHT(y->right));

    return y;
}

Node* INSERT(Node* N, int key) {
    if (N == NULL) return CREATE_NODE(key);

    if (key < N->key)
        N->left = INSERT(N->left, key);
    else if (key > N->key)
        N->right = INSERT(N->right, key);
    else
        return N;

    N->height = 1 + MAXIMUM(HEIGHT(N->left), HEIGHT(N->right));
    int balance = GET_BALANCE_FACTOR(N);

    if (balance > 1 && key < N->left->key)
        return RIGHT_ROTATE(N);
    if (balance < -1 && key > N->right->key)
        return LEFT_ROTATE(N);
    if (balance > 1 && key > N->left->key) {
        N->left = LEFT_ROTATE(N->left);
        return RIGHT_ROTATE(N);
    }
    if (balance < -1 && key < N->right->key) {
        N->right = RIGHT_ROTATE(N->right);
        return LEFT_ROTATE(N);
    }
    return N;
}

Node* MIN_VALUE_NODE(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node* DELETE_NODE(Node* root, int key) {
    if (root == NULL){
        printf("Key : %d Not found\n", key);
        return root;
    }

    if (key < root->key)
        root->left = DELETE_NODE(root->left, key);
    else if (key > root->key)
        root->right = DELETE_NODE(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = (root->left) ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            printf("Deleted : %d\n", temp->key);
            free(temp);
        } else {
            Node* temp = MIN_VALUE_NODE(root->right);
            root->key = temp->key;
            root->right = DELETE_NODE(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + MAXIMUM(HEIGHT(root->left), HEIGHT(root->right));

    int balance = GET_BALANCE_FACTOR(root);

    if (balance > 1 && GET_BALANCE_FACTOR(root->left) >= 0)
        return RIGHT_ROTATE(root);

    if (balance > 1 && GET_BALANCE_FACTOR(root->left) < 0) {
        root->left = LEFT_ROTATE(root->left);
        return RIGHT_ROTATE(root);
    }

    if (balance < -1 && GET_BALANCE_FACTOR(root->right) <= 0)
        return LEFT_ROTATE(root);

    if (balance < -1 && GET_BALANCE_FACTOR(root->right) > 0) {
        root->right = RIGHT_ROTATE(root->right);
        return LEFT_ROTATE(root);
    }

    return root;
}


void INORDER(Node* root) {
    if (root) {
        INORDER(root->left);
        printf("%d ", root->key);
        INORDER(root->right);
    }
}

Node* SEARCH(Node* node, int key) {
    if (node == NULL) {
        printf("Node not found\n");
        return NULL;
    }
    if (node->key == key) {
        printf("Key found: %d\n", key);
        return node;
    }
    if (key < node->key) {
        return SEARCH(node->left, key);
    } else {
        return SEARCH(node->right, key);
    }
}
