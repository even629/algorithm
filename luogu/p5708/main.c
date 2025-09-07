#include <stdio.h>
#include <math.h>

int main(){
  float a,b,c;
  float p = 0;
  float square = 0;

  scanf("%f %f %f",&a,&b,&c);
  p = (a+b+c)/2;
  square = sqrt((double)(p * ( p-a)*(p-b)* (p-c)));
  printf("%.1f",square);


}