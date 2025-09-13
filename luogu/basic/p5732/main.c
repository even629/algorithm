#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  int **arr;
  scanf("%d", &n);
  arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(n * sizeof(int));
    memset(arr[i], 0, n * sizeof(int));
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == 0) {
        arr[i][j] = 1;
      } else if (i == 0) {
        arr[i][j] = 0;
      } else {
        arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] != 0) {
        printf("%d ", arr[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}
