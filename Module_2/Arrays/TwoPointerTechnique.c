#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define N 100

void FIND_PAIR(int arr[], int n, int target);

int IS_PALINDROME(char str[]);

int main(){
    int arr[N], n, target, choice;

    do{
        printf("\n\n1. Find Pair in Array");
        printf("\n2. Check For palindrome");
        printf("\n3. Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Enter the size of array : ");
            scanf("%d", &n);
            for(int i = 0; i < n; i++){
                arr[i] = i * 2;
            }
            printf("Array Values : ");
            for(int i = 0; i < n; i++){
                printf("%d ", arr[i]);
            }
            printf("Enter the target : ");
            scanf("%d", &target);
            FIND_PAIR(arr, n, target);
        }
        else if(choice == 2){
            char str[] = "Welcome To data Structure and Algorithm";
            if(IS_PALINDROME(str)){
                printf("%s is Palindrome\n", str);
            }else{
                printf("%s is not Palindrome\n",str);
            }
        }
        else{
            printf("\nInvalid Input");
        }
    }while(choice != 3);
}

void FIND_PAIR(int arr[], int n, int target){
    int left = 0;
    int right = n - 1;
    int sum;
    while(left < right){
        sum = arr[left] + arr[right];
        if(sum == target){
            printf("Target FOUND (%d, %d)", arr[left], arr[right]);
            return;
        }
        else if(sum < target){
            left = left + 1;
        }
        else {
            right = right - 1;
        }
    }
    printf("No PAIR FOUND");
}

int IS_PALINDROME(char str[]){
    int left = 0;
    int right = strlen(str) - 1;
    while(left < right){
        while(!isalnum(str[left]) && left < right){
            left++;
        }
        while (!isalnum(str[right]) && left < right)
        {
            right--;
        }
        if(tolower(str[left]) != tolower(str[right])){
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}