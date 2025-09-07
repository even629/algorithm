#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N;
  int last_i, last_j;
  int **arr;
  scanf("%d", &N);
  arr = (int **)malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    arr[i] = (int *)malloc(N * sizeof(int));
    memset(arr[i], 0, N * sizeof(int));
  }

  last_i = 0;
  last_j = N / 2;
  arr[last_i][last_j] = 1;

  for (int k = 2; k <= N * N; k++) {
    if (last_i == 0 && last_j != N - 1) { // k-1在第一行但不在最后一列
      last_i = N - 1;
      last_j = last_j + 1;
    } else if (last_i != 0 && last_j == N - 1) { // k-1在最后一列但不在第一行
      last_i = last_i - 1;
      last_j = 0;
    } else if (last_i == 0 && last_j == N - 1) { // k-1在第一行最后一列
      last_i = last_i + 1;
      last_j = last_j;
    } else { // k-1既不在第一行，也不在最后一列
      if ((last_i - 1 >= 0 && last_i - 1 <= N - 1) &&
          (last_j + 1 >= 0 && last_j + 1 <= N - 1) &&
          arr[last_i - 1][last_j + 1] == 0) { // k-1的右上方
        last_i = last_i - 1;
        last_j = last_j + 1;
      } else { // k-1的正下方
        last_i = last_i + 1;
        last_j = last_j;
      }
    }
    arr[last_i][last_j] = k;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}
