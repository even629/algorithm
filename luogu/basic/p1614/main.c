#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m;
  int *arr;
  // 滑动窗口
  int lptr, rptr;
  int total, min = INT_MAX;

  scanf("%d %d", &n, &m);

  arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  lptr = 0;
  rptr = lptr + m - 1;
  while (rptr != n) {
    total = 0;
    for (int i = lptr; i <= rptr; i++) {
      total += arr[i];
    }
    if (total < min) {
      min = total;
    }
    lptr++;
    rptr++;
  }
  printf("%d", min);
}
