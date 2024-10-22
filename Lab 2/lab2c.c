#include <stdio.h>

// Function to calculate the Egyptian fraction of a/b
void egyptianFraction(int a, int b) {
    while (a != 0) {
        // Find the denominator of the closest unit fraction
        int denominator = (b + a - 1) / a;  // This is equivalent to "ceil(b/a)"
        printf("%d\n", denominator);
        
        // Update the fraction by subtracting the found unit fraction
        a = a * denominator - b;
        b = b * denominator;
    }
    
}

int main() {
    int n;
    scanf("%d", &n);  // Read the number of cases

    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);  // Read the numerator and denominator

        egyptianFraction(a, b);  // Calculate the Egyptian fraction
        
        printf("0\n"); // Separator for each fraction
    }

    return 0;
}
