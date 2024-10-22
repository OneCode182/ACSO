#include <stdio.h>

int main()
{
  float a,b;
  int i, n;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%f",&a);
    scanf("%f",&b);
    if(a<b){
      printf("%f\n", b);
    }else{
      printf("%f\n", a);
    }

  }

}