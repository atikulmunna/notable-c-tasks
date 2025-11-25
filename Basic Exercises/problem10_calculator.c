#include <stdio.h>

float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return b != 0 ? a / b : 0; }

int main() {
    float num1, num2, result;
    char operator;
    int continueCalc = 1;
    
    while (continueCalc) {
        printf("\nEnter operation (e.g., 5 + 3): ");
        scanf("%f %c %f", &num1, &operator, &num2);
        
        switch (operator) {
            case '+':
                result = add(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case '-':
                result = subtract(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case '*':
                result = multiply(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case '/':
                if (num2 != 0) {
                    result = divide(num1, num2);
                    printf("Result: %.2f\n", result);
                } else {
                    printf("Error: Division by zero\n");
                }
                break;
            default:
                printf("Invalid operator\n");
        }
        
        printf("Continue? (1=Yes, 0=No): ");
        scanf("%d", &continueCalc);
    }
    
    return 0;
}