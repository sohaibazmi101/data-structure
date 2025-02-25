#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define CHAR_COUNT 256

char* STRING_REVERSAL(char str[]);
char* STRING_CONCATENATION(char str1[], char str2[]);
int STRING_LENGTH(char str[]);
char* SUBSTRING_EXTRACTION(char str[], int start, int end);
int STRING_COMPARISON(char str1[], char str2[]);
int STRING_PALINDROME(char str[]);
int BRUTE_FORCE_SEARCH(char text[], char pattern[]);
void STRING_REPLACEMENT(char str[], char oldSub[], char newSub[]);
int IS_ANAGRAM(char str1[], char str2[]);
// KMP(char text[], char pattern);

int main(){
    // char str[] = "Hello How are you";
    // printf("%s",STRING_REVERSAL(str));

    char str1[] = "Sohaib";
    char str2[] = "baihSo";
    printf("%s\n",STRING_CONCATENATION(str1, str2));
    printf("%d\n",STRING_LENGTH(str2));
    printf("%s\n",SUBSTRING_EXTRACTION(str2, 2,4));
    if(STRING_COMPARISON(str1,str2)){
        printf("String are same\n");
    }else{
        printf("string are not same\n");
    }
    if(STRING_PALINDROME("HELLEHo")){
        printf("Palindrome\n");
    }
    else{
        printf("Not palindrome\n");
    }
    if(BRUTE_FORCE_SEARCH("Hello world","o world")){
        printf("Matched\n");
    }else{
        printf("Not Matched\n");
    }
    char str[] = "Hello World How are you!";
    char oldStr[] = "Worlpojd";
    char newStr[] = "Universe";
    printf("\n%s\n",str);
    STRING_REPLACEMENT(str, oldStr, newStr);
    printf("\n%s\n",str);
    if(IS_ANAGRAM(str1,str2)){
        printf("Anagram\n");
    }else{
        printf("Not Anagram\n");
    }
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

int STRING_LENGTH(char str[]){
    return strlen(str);
}

char* SUBSTRING_EXTRACTION(char str[], int start, int end){
    int length = strlen(str);
    char* substr = (char*)malloc((end - start + 2)*sizeof(char));
    if(substr == NULL){
        printf("Memory allocation Failed\n");
        return NULL;
    }
    if(start < 0 || start > length - 1 || end > length - 1 || start > end){
        printf("Out of Bound String\n");
        return NULL;
    }
    for(int i = start; i <= end; i++){
        substr[i - start] = str[i];
    }
    substr[end - start + 1] = '\0';
    return substr;
}

int STRING_COMPARISON(char str1[], char str2[]){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 != len2){
        return 0;
    }
    for(int i = 0; i < len1; i++){
        if (str1[i] != str2[i])
        {
            return 0;
        }
    }
    return 1;
}

int STRING_PALINDROME(char str[]){
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right)
    {
        if(str[left] != str[right]){
            return 0;
        }
        left += 1;
        right -= 1;
    }
    return 1;
}

int BRUTE_FORCE_SEARCH(char text[], char pattern[]){
    int n = strlen(text);
    int m = strlen(pattern);
    for(int i = 0; i <= n-m; i++){
        int match = 1;
        for(int j = 0; j < m; j++){
            if(text[i+j] != pattern[j]){
                match = 0;
                break;
            }
        }
        if(match){
            return i;
        }
    }
    return -1;
}

void STRING_REPLACEMENT(char str[], char oldSub[], char newSub[]){
    int index = BRUTE_FORCE_SEARCH(str, oldSub);
    if(index == -1){
        return;
    }
    int n = strlen(str);
    int oldLen = strlen(oldSub);
    int newLen = strlen(newSub);
    char buffer[n - oldLen + newLen + 1];
    strncpy(buffer, str, index);
    buffer[index] = '\0';
    strcat(buffer, newSub);
    strcat(buffer, str + index + oldLen);
    strcpy(str, buffer);
}

int IS_ANAGRAM(char str1[], char str2[]){
    if(strlen(str1) != strlen(str2)){
        return 0;
    }
    int count[CHAR_COUNT] = {0};
    for(int i = 0; str1[i] && str2[i]; i++){
        count[(int)str1[i]]++;
        count[(int)str2[i]]--;
    }
    for(int i = 0; i < CHAR_COUNT; i++){
        if(count[i] != 0){
            return 0;
        }
    }
    return 1;
}

