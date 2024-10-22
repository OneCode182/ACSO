#include <stdio.h>

int main() {
    int num_operations, i;
    scanf("%d", &num_operations);

    for (i = 0; i < num_operations; i++) {
        char operatorC;
        float operand1, operand2, result;

        scanf(" %c", &operatorC);
        scanf("%f", &operand1);
        scanf("%f", &operand2);

        if (operatorC == '+') {
            result = operand1 + operand2;
        } else if (operatorC == '-') {
            result = operand1 - operand2;
        } else if (operatorC == '*') {
            result = operand1 * operand2;
        } else if (operatorC == '/') {
            result = operand1 / operand2;
        }

        printf("%f\n", result);
    }

    return 0;
}