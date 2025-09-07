#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int **arr;
  int n;
  // 0 -> 右
  // 1 -> 下
  // 2 -> 左
  // 3 -> 上
  int direction;

} Matrix;
void init_matrix(Matrix *matrix, int n) {
  matrix->arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    matrix->arr[i] = (int *)malloc(n * sizeof(int));
    memset(matrix->arr[i], 0, n * sizeof(int));
  }
  matrix->n = n;
  matrix->direction = 0;
}

void run(Matrix *matrix) {
  int i = 0, j = -1, index = 1;
  int max_num = matrix->n * matrix->n;
  while (index != max_num + 1) {
    switch (matrix->direction) {
    case 0: // 向右
      if (j == matrix->n - 1 || matrix->arr[i][j + 1] != 0) {
        matrix->direction = (matrix->direction + 1) % 4;
        continue;
      } else {
        j++;
      }
      break;
    case 1: // 向下
      if (i == matrix->n - 1 || matrix->arr[i + 1][j] != 0) {
        matrix->direction = (matrix->direction + 1) % 4;
        continue;
      } else {
        i++;
      }
      break;
    case 2: // 向左
      if (j == 0 || matrix->arr[i][j - 1] != 0) {
        matrix->direction = (matrix->direction + 1) % 4;
        continue;
      } else {
        j--;
      }

      break;
    case 3: // 向上
      if (i == 0 || matrix->arr[i - 1][j] != 0) {
        matrix->direction = (matrix->direction + 1) % 4;
        continue;
      }
      i--;
      break;
    default:
      __builtin_unreachable();
    }
    matrix->arr[i][j] = index;
    index++;
  }
}

void print_matrix(Matrix *matrix) {
  int len = matrix->n;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      printf("%3d", matrix->arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n;
  Matrix matrix;

  scanf("%d", &n);
  init_matrix(&matrix, n);
  run(&matrix);
  print_matrix(&matrix);
  return 0;
}
