#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool in(int left, int right, int num) { return num >= left && num <= right; }

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
  int a, b;
  int a_digit = 0, b_digit = 0, temp;
  // 5≤a<b≤100,000,000
  scanf("%d %d", &a, &b);

  /**
   * 十进制视角下的位数
   */
  temp = b;
  while (temp != 0) {
    temp /= 10;
    b_digit++;
  }
  temp = a;
  while (temp != 0) {
    temp /= 10;
    a_digit++;
  }
  /**
   * 生成a_digit~b_digit位的回文数
   */
  // 质数必定是奇数

  for (int i = a_digit; i <= b_digit; i++) {
    switch (i) {
      case 1:
        for (int d = 5; d <= 9; d += 2) {
          if (in(a, b, d) && is_prime(d)) {
            printf("%d\n", d);
          }
        }
        break;
      case 2:
        for (int d1 = 1; d1 <= 9; d1 += 2) {
          temp = d1 * 10 + d1;
          if (in(a, b, temp) && is_prime(temp)) {
            printf("%d\n", temp);
          }
        }
        break;

      case 3:
        for (int d1 = 1; d1 <= 9; d1 += 2) {
          for (int d2 = 0; d2 <= 9; d2++) {
            temp = d1 * 100 + d2 * 10 + d1;
            if (in(a, b, temp) && is_prime(temp)) {
              printf("%d\n", temp);
            }
          }
        }
        break;

      case 4:
        for (int d1 = 1; d1 <= 9; d1 += 2) {
          for (int d2 = 0; d2 <= 9; d2++) {
            temp = d1 * 1000 + d2 * 100 + d2 * 10 + d1;
            if (in(a, b, temp) && is_prime(temp)) {
              printf("%d\n", temp);
            }
          }
        }
        break;

      case 5:
        for (int d1 = 1; d1 <= 9; d1 += 2) {
          for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
              temp = d1 * 10000 + d2 * 1000 + d3 * 100 + d2 * 10 + d1;
              if (in(a, b, temp) && is_prime(temp)) {
                printf("%d\n", temp);
              }
            }
          }
        }
        break;

      case 6:
        for (int d1 = 1; d1 <= 9; d1 += 2) {
          for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
              temp = d1 * 100000 + d2 * 10000 + d3 * 1000 + d3 * 100 + d2 * 10 +
                     d1;
              if (in(a, b, temp) && is_prime(temp)) {
                printf("%d\n", temp);
              }
            }
          }
        }
        break;

      case 7:
        for (int d1 = 1; d1 <= 9; d1 += 2) {
          for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
              for (int d4 = 0; d4 <= 9; d4++) {
                temp = d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 +
                       d3 * 100 + d2 * 10 + d1;
                if (in(a, b, temp) && is_prime(temp)) {
                  printf("%d\n", temp);
                }
              }
            }
          }
        }
        break;

      case 8:
        for (int d1 = 1; d1 <= 9; d1 += 2) {
          for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
              for (int d4 = 0; d4 <= 9; d4++) {
                temp = d1 * 10000000 + d2 * 1000000 + d3 * 100000 + d4 * 10000 +
                       d4 * 1000 + d3 * 100 + d2 * 10 + d1;
                if (in(a, b, temp) && is_prime(temp)) {
                  printf("%d\n", temp);
                }
              }
            }
          }
        }
        break;

      default:
        break;
    }
  }
}