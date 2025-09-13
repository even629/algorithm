#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 5
char cnt[10][5][3] = {
    {'X', 'X', 'X', 'X', '.', 'X', 'X', '.', 'X', 'X', '.', 'X', 'X', 'X', 'X'},
    {'.', '.', 'X', '.', '.', 'X', '.', '.', 'X', '.', '.', 'X', '.', '.', 'X'},
    {'X', 'X', 'X', '.', '.', 'X', 'X', 'X', 'X', 'X', '.', '.', 'X', 'X', 'X'},
    {'X', 'X', 'X', '.', '.', 'X', 'X', 'X', 'X', '.', '.', 'X', 'X', 'X', 'X'},
    {'X', '.', 'X', 'X', '.', 'X', 'X', 'X', 'X', '.', '.', 'X', '.', '.', 'X'},
    {'X', 'X', 'X', 'X', '.', '.', 'X', 'X', 'X', '.', '.', 'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'X', '.', '.', 'X', 'X', 'X', 'X', '.', 'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', '.', '.', 'X', '.', '.', 'X', '.', '.', 'X', '.', '.', 'X'},
    {'X', 'X', 'X', 'X', '.', 'X', 'X', 'X', 'X', 'X', '.', 'X', 'X', 'X', 'X'},
    {'X', 'X', 'X', 'X', '.', 'X', 'X', 'X', 'X', '.', '.', 'X', 'X', 'X',
     'X'}};

int main() {
  int n;
  char *input = NULL;
  char **arr;
  int len;
  int start;
  scanf("%d", &n);
  input = (char *)malloc((n + 1) * sizeof(char));

  // 最后一列没有空列
  len = 4 * n - 1;
  arr = (char **)malloc(HEIGHT * sizeof(char *));
  for (int i = 0; i < HEIGHT; i++) {
    arr[i] = (char *)malloc(len * sizeof(char));
  }

  scanf("%s", input);

  for (int i = 0; i < n; i++) {
    start = i * 4;

    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 3; k++) {
        arr[j][start + k] = cnt[input[i] - '0'][j][k];
      }
    }
    // 间隔
    if (i != n - 1) {
      for (int j = 0; j < 5; j++) {
        arr[j][start + 3] = '.';
      }
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < len; j++) {
      printf("%c", arr[i][j]);
    }
    printf("\n");
  }
  // 内存回收
  free(input);
  for (int i = 0; i < HEIGHT; i++) {
    free(arr[i]);
  }
  free(arr);
  return 0;
}
