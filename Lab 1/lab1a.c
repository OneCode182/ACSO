#include <stdio.h>

int main()
{
    int n,a,b, i;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
      scanf("%d",&a);
      scanf("%d",&b);
      printf("%d\n",a + b);
    }

}