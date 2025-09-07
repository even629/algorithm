#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 5
int main() {
  int n;
  char *input = NULL;
  int **arr;
  int len;
  int start;
  scanf("%d", &n);
  input = (char *)malloc((n + 1) * sizeof(char));

  // 最后一列没有空列
  len = 4 * n - 1;
  arr = (int **)malloc(HEIGHT * sizeof(int *));
  for (int i = 0; i < HEIGHT; i++) {
    arr[i] = (int *)malloc(len * sizeof(int));
  }

  scanf("%s", input);

  for (int i = 0; i < n; i++) {
    start = i * 4;

    switch (input[i] - '0') {
    case 0:
      for (int k = start; k < start + 3; k++) {
        for (int j = 0; j < 5; j++) {
          if (k == start || k == start + 2) {
            arr[j][k] = 'X';
          } else {
            if (j == 0 || j == 4) {
              arr[j][k] = 'X';
            } else {
              arr[j][k] = '.';
            }
          }
        }
      }
      break;
    case 1:
      for (int k = start; k < start + 3; k++) {
        for (int j = 0; j < 5; j++) {
          if (k == start || k == start + 1) {
            arr[j][k] = '.';
          } else { // k==start+2
            arr[j][k] = 'X';
          }
        }
      }
      break;
    case 2:
      for (int k = start; k < start + 3; k++) {
        for (int j = 0; j < 5; j++) {
          if (k == start || k == start + 1) {
            arr[j][k] = '.';
          } else { // k==start+2
            arr[j][k] = 'X';
          }
        }
      }
      break;
    default:
      printf("input error");
      goto end;
      break;
    }
    if (i != n - 1) {
      for (int j = 0; j < 5; j++) {
        arr[start + 3][j] = '.';
      }
    }
  }

end:
  free(input);
  for (int i = 0; i < HEIGHT; i++) {
    free(arr[i]);
  }
  free(arr);
  return 0;
}
