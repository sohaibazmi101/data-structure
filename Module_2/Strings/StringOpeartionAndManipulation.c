#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* STRING_REVERSAL(char str[]);
char* STRING_CONCATENATION(char str1[], char str2[]);
// STRING_LENGTH(char str[]);
// SUBSTRING_EXTRACTION(char str[], int start, int end);
// STRING_COMPARISON(char str1[], char str2[]);
// STRING_PALINDROME(char str[]);
// BRUTE_FORCE_SEARCH(char text[], char pattern[]);
// STRING_REPLACEMENT(char str[], char oldSub, char newSub);
// IS_ANAGRAM(char str1[], char str2[]);
// KMP(char text[], char pattern);

int main(){
    // char str[] = "Hello How are you";
    // printf("%s",STRING_REVERSAL(str));

    char str1[] = "Mohd ";
    char str2[] = "Sohaib";
    printf("%s\n",STRING_CONCATENATION(str1, str2));
}

char* STRING_REVERSAL(char str[]){
    int left = 0;
    char temp;
    int right = strlen(str) - 1;
    while (left < right){
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left = left + 1;
        right = right - 1;
    }
    return str;
}

char* STRING_CONCATENATION(char str1[], char str2[]){
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    char* str = (char*)malloc((size1 + size2 + 1)*sizeof(char));
    if(str == NULL){
        printf("Memory allocation Failed\n");
        return NULL;
    }
    strcpy(str, str1);
    strcat(str, str2);
    return str;
}