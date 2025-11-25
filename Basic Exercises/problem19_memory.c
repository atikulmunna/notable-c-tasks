#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    float *grades;
    int numGrades;
};

struct Person* createPerson(char *name, int age, int numGrades) {
    struct Person *p = (struct Person*)malloc(sizeof(struct Person));
    
    p->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(p->name, name);
    
    p->age = age;
    p->numGrades = numGrades;
    p->grades = (float*)malloc(numGrades * sizeof(float));
    
    return p;
}

void setGrades(struct Person *p) {
    printf("Enter %d grades:\n", p->numGrades);
    for (int i = 0; i < p->numGrades; i++) {
        scanf("%f", &p->grades[i]);
    }
}

float calculateAverage(struct Person *p) {
    float sum = 0.0;
    for (int i = 0; i < p->numGrades; i++) {
        sum += p->grades[i];
    }
    return sum / p->numGrades;
}

void displayPerson(struct Person *p) {
    printf("\nName: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Grades: ");
    for (int i = 0; i < p->numGrades; i++) {
        printf("%.2f ", p->grades[i]);
    }
    printf("\nAverage: %.2f\n", calculateAverage(p));
}

void freePerson(struct Person *p) {
    free(p->name);
    free(p->grades);
    free(p);
}

int main() {
    int n, i, age, numGrades;
    char name[100];
    struct Person **people;
    
    printf("Enter number of people: ");
    scanf("%d", &n);
    
    people = (struct Person**)malloc(n * sizeof(struct Person*));
    
    for (i = 0; i < n; i++) {
        printf("\nPerson %d:\n", i + 1);
        printf("Enter name: ");
        scanf(" %[^\n]", name);
        printf("Enter age: ");
        scanf("%d", &age);
        printf("Enter number of grades: ");
        scanf("%d", &numGrades);
        
        people[i] = createPerson(name, age, numGrades);
        setGrades(people[i]);
    }
    
    printf("\n--- All People ---\n");
    for (i = 0; i < n; i++) {
        displayPerson(people[i]);
    }
    
    for (i = 0; i < n; i++) {
        freePerson(people[i]);
    }
    free(people);
    
    return 0;
}