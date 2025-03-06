#include<stdio.h>
#include<stdlib.h>
 struct Node{
    int data;
    struct Node *left, *right;
};
typedef struct Node Node;

Node* CREATE_NODE(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* INSERT(Node* root, int data){
    if(root == NULL){
        return CREATE_NODE(data);
    }
    if(data < root->data){
        root->left = INSERT(root->left, data);
    }else if(data > root->data){
        root->right = INSERT(root->right, data);
    }
    return root;
}

Node* SEARCH(Node* root, int key){
    if(root == NULL || root->data == key){
        return root;
    }
    if(key < root->data){
        return SEARCH(root->left, key);
    }
    return SEARCH(root->right, key);
}

Node* FIND_MIN(Node* root){
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node* DELETE_NODE(Node* root, int key){
    if(root == NULL)return root;
    if(key < root->data){
        root->left = DELETE_NODE(root->left, key);
    }else if(key > root->data){
        root->right = DELETE_NODE(root->right, key);
    }else {
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = FIND_MIN(root->right);
        root->data = temp->data;
        root->right = DELETE_NODE(root->right, temp->data);
    }
    return root;
}

void INORDER_TRAVERSAL(Node* root){
    if(root != NULL){
        INORDER_TRAVERSAL(root->left);
        printf("%d ",root->data);
        INORDER_TRAVERSAL(root->right);
    }
}

int main(){
    Node* root = NULL;
    int data, choice;
    do{
        printf("\n1. Insert\n2. Search\n3. Delete\n4. InOrderTraversal\n5. Exit\n");
        printf("Enter Yor Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Your data : ");
            scanf("%d", &data);
            root = INSERT(root, data);
            break;
        case 2:
            printf("Enter Your Key : ");
            scanf("%d",&data);
            if(SEARCH(root, data)){
                printf("Found : %d\n",data);
            }else{
                printf("Not Found : %d\n",data);
            }
            break;
        case 3:
            printf("Enert value to delete : ");
            scanf("%d", &data);
            root = DELETE_NODE(root, data);
            break;
        case 4:
            printf("Trees : ");
            INORDER_TRAVERSAL(root);
            break;
        case 5:
            printf("Exited\n\n");
        default:
            printf("Invalid Choice\n");
            break;
        }
    }while(choice != 5);
}