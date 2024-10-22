#include <stdio.h>

int main() {
  // Define
  int k, n;
  float a, b, i;

  // Input
  scanf("%d", &k);

  while (k--) {
    scanf("%d", &n);
    float min = 1000;

    while (n--) {
      scanf("%f", &i);
      if (i < min) {
        min = i;
      }

    }
    printf("%f\n", min);

  }

}