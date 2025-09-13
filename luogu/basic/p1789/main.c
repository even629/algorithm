#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void light_up(int **arr, int n, int x_pos, int y_pos, int type) {
  x_pos = x_pos - 3;
  y_pos = y_pos - 3;
  switch (type) {
  case 0: // 火把
    for (int i = x_pos; i < x_pos + 5; i++) {
      for (int j = y_pos; j < y_pos + 5; j++) {
        if (i >= 0 && i < n && j >= 0 && j < n) {
          if ((i - x_pos == 2 || j - y_pos == 2) ||
              (i - x_pos == 3 && j - y_pos == 1) ||
              (i - x_pos == 1 && j - y_pos == 3) ||
              (i - x_pos == 1 && j - y_pos == 1) ||
              (i - x_pos == 3 && j - y_pos == 3)) {
            arr[i][j] = 1;
          }
        }
      }
    }
    break;
  case 1: // 萤石
    for (int i = x_pos; i < x_pos + 5; i++) {
      for (int j = y_pos; j < y_pos + 5; j++) {
        if (i >= 0 && i < n && j >= 0 && j < n) {
          arr[i][j] = 1;
        }
      }
    }
    break;
  default:
    __builtin_unreachable();
  }
}

int main() {
  int n, m, k;
  int xi, yi, oi, pi;
  int **arr;
  int monster_num = 0;
  scanf("%d %d %d", &n, &m, &k);
  arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(n * sizeof(int));
    memset(arr[i], 0, n * sizeof(int));
  }

  // 火把
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &xi, &yi);
    light_up(arr, n, xi, yi, 0);
  }
  // 萤石
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &oi, &pi);
    light_up(arr, n, oi, pi, 1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == 0) {
        monster_num++;
      }
    }
  }
  printf("%d", monster_num);

  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);
}
