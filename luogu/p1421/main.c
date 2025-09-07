#include <stdio.h>

#define PEN_PRICE 19

int main(){

  int a=0;
  int b=0;
  int pen_num = 0;

  scanf("%d %d",&a,&b);

  pen_num = (a*10+b)/PEN_PRICE;
  printf("%d",pen_num);
  

}