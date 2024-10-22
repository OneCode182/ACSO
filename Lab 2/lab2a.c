#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    // Number of equations
    int n;
    double a, b, c;
    scanf("%d", &n);
    
    while (n--) {
        scanf("%lf %lf %lf", &a, &b, &c);  // Reading coefficients a, b and c
        double disc = b * b - 4 * a * c;
        
        // Evaluate the discriminant to determine the roots
        if (disc > 0) {
            double root1 = (-b + sqrt(disc)) / (2 * a);
            double root2 = (-b - sqrt(disc)) / (2 * a);
            printf("%.2lf\n%.2lf\n", root1, root2); 
            
        } else if (disc == 0) {
            double root = -b / (2 * a);
            printf("%.2lf\n", root);
            
        } else {
            printf("no roots\n");
            
        }
        
    }

    return 0;
}