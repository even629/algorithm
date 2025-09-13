#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, *arr;
  int max_consi = 1, curr = -1, curr_max_consi;

  scanf("%d", &n);
  arr = (int*)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    // if (i == 0) {
    // curr = arr[0];
    // curr_max_consi = 1;
    // continue;
    // }
    if (curr + 1 == arr[i]) {
      curr_max_consi++;
      curr = arr[i];
      if (curr_max_consi > max_consi) {
        max_consi = curr_max_consi;
      }
    } else { // 第一个输入的数字必定不是0，因此可以去掉i==0的那个条件判断
      curr = arr[i];
      curr_max_consi = 1;
    }
  }

  printf("%d",max_consi);
}