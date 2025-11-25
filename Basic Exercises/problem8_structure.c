#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    struct Student students[50];
    int n, i;
    float totalGPA = 0.0;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &students[i].id);
        printf("Enter Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Enter GPA: ");
        scanf("%f", &students[i].gpa);
        totalGPA += students[i].gpa;
    }
    
    printf("\n--- Student Records ---\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", 
               students[i].id, students[i].name, students[i].gpa);
    }
    
    printf("\nAverage GPA: %.2f\n", totalGPA / n);
    
    return 0;
}