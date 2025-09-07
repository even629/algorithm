#include <stdio.h>
#include <math.h>

#define NUM sqrt(5)

int main(){
  int n;
  double fn;
  scanf("%d",&n);

  fn = (pow((1.0+NUM)/2,n) - pow((1.0-NUM)/2,n))/NUM;
  printf("%.2lf",fn);




}