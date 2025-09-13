#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_prime(int num) {
  if (num <= 0 || num == 1) {
    return false;
  }
  // 只检查到sqrt(num)
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  int n, temp;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      temp = n / i;
      if(is_prime(temp)){
        printf("%d",temp);
        return 0 ;
      }
    }
  }
}