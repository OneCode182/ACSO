#include <stdio.h>

int main() {
  // Define
  int k, n;
  int a, b, i;

  // Input
  scanf("%d", &k);

  while (k--) {
    scanf("%d", &n);
    int m = 0;

    while (n--) {
      scanf("%d", &i);
      m = m + i;

    }
    printf("%d\n", m);

  }

}