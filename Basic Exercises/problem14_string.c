#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    char temp;
    
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int countVowels(char *str) {
    int count = 0;
    while (*str) {
        char ch = *str | 32;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        str++;
    }
    return count;
}

char* concatenateStrings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    
    char *ptr = result;
    while (*str1) {
        *ptr++ = *str1++;
    }
    while (*str2) {
        *ptr++ = *str2++;
    }
    *ptr = '\0';
    
    return result;
}

int main() {
    char str1[100], str2[100];
    char *result;
    
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;
    
    printf("\nVowels in string 1: %d\n", countVowels(str1));
    
    reverseString(str1);
    printf("Reversed string 1: %s\n", str1);
    
    result = concatenateStrings(str1, str2);
    printf("Concatenated: %s\n", result);
    
    free(result);
    return 0;
}