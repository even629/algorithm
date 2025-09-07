#include <stdio.h>
#define SPEED 250

int main() {
  int x, n, workday=0,distance=0;
  
  scanf("%d %d", &x, &n);

  if(x+n-1<=7){ // 只有一周
    if(x>5){
      printf("0");
    }else if(x+n-1<=5){// 1<=x<=5
      workday += n;
    }else if(x+n-1>5){
      workday += 5 - x + 1;
    }
    distance += workday* SPEED;
    printf("%d",distance);
    return 0;
  }


  // 两周以上
  // 先算第一周，从周 x 开始
  if (x <= 5) {
    workday += 5 - x + 1;
  }else{
    workday += 0;
  }
  // 减去第一周的所有天数
  n = n - (7 - x + 1);
  // 之后的完整周数
  workday += (n / 7) * 5;
  // 最后一周是否满
  if (n % 7 > 0 && n % 7 < 5) {
    workday += n % 7;
  } else if (n % 7 >= 5) {
    workday += 5;
  }
  distance = workday *SPEED;
  printf("%d",distance);
}