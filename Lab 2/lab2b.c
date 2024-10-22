#include <stdio.h>

// Function to calculate the GCD
int calGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        
    } return a;
}

// Main function
int main() {
    int n;
    scanf("%d", &n);  // Read the number of cases

    while (n--) {
        int pBelgium, pEngland, pNorway, pIreland, pFrance;
        scanf("%d %d %d %d %d", &pBelgium, &pEngland, &pNorway, &pIreland, &pFrance);

        // Calculate the GCD of all the numbers of passengers
        int gcd = calGCD(pBelgium, calGCD(pEngland, calGCD(pNorway, calGCD(pIreland, pFrance))));

        // Calculate the number of planes needed for each country
        int aBelgium = pBelgium / gcd;
        int aEngland = pEngland / gcd;
        int aNorway = pNorway / gcd;
        int aIreland = pIreland / gcd;
        int aFrance = pFrance / gcd;

        // Calculate the total number of planes
        int total = aBelgium + aEngland + aNorway + aIreland + aFrance;

        // Print the results
        printf("%d\n", gcd);
        printf("%d\n%d\n%d\n%d\n%d\n", aBelgium, aEngland, aNorway, aIreland, aFrance);
        printf("%d\n", total);
    }

    return 0;
}