#include <stdio.h>

int main() {
  float s, temp = 0, step = 2;
  int count = 0;
  scanf("%f", &s);
  while (1) {
    temp += step;
    step *= 0.98;
    count++;
    if(temp>=s){
      printf("%d",count);
      break;
    }
  }

  return 0;
}