#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_same(char **a, char **b, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != b[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void convert(int n, char **square, char **target, char **tmp, int method) {
  char **temp;

  switch (method) {
  case 1:
    // 1 转 90°：图案按顺时针转 90°。
    // square的第i行变成tmp的第n-i-1列
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        tmp[j][n - i - 1] = square[i][j];
      }
    }
    break;
  case 2:
    // 2 转 180°：图案按顺时针转 180°。
    // square的第i行变为tmp的第n-i-1行,第j列变为tmp的第n-j-1列
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        tmp[n - i - 1][n - j - 1] = square[i][j];
      }
    }
    break;
  case 3:
    // 3 转 270°：图案按顺时针转 270°。
    // 顺时针旋转270,相当于逆时针旋转90
    // square的第i行变为tmp的第i列
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        tmp[j][i] = square[i][j];
      }
    }
    break;
  case 4:
    // 4 反射：图案在水平方向翻转（以中央铅垂线为中心形成原图案的镜像）。
    // 水平方向翻转，按中央铅垂线形成镜像
    // 沿着竖直的中轴线左右交换
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        tmp[i][n - 1 - j] = square[i][j];
      }
    }
    break;
  case 5:
    // 5 组合：图案在水平方向翻转，然后再按照 1∼3 之间的一种再次转换。

    temp = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
      temp[i] = (char *)malloc(n * sizeof(char));
    }

    for (int i = 1; i <= 3; i++) {
      convert(n, square, target, tmp, 4);
      convert(n, tmp, target, temp, i);
      if (is_same(target, temp, n)) {
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        tmp[i][j] = temp[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      free(temp[i]);
    }
    free(temp);
    break;
  case 6:
    // 6 不改变：原图案不改变。
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        tmp[i][j] = square[i][j];
      }
    }
    break;
  case 7:

    break;
  default:
    perror("error method num\n");

    break;
  }
}

int main() {
  int n;
  char **square, **target, **tmp;
  scanf("%d", &n);

  square = (char **)malloc(n * sizeof(char *));
  target = (char **)malloc(n * sizeof(char *));
  tmp = (char **)malloc(n * sizeof(char *));

  for (int i = 0; i < n; i++) {
    square[i] = (char *)malloc(n * sizeof(char));
    tmp[i] = (char *)malloc(n * sizeof(char));
    target[i] = (char *)malloc(n * sizeof(char));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf(" %c", &square[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf(" %c", &target[i][j]);
    }
  }

  for (int i = 1; i < 7; i++) {
    convert(n, square, target, tmp, i);
    if (is_same(target, tmp, n)) {
      printf("%d", i);
      goto end;
    }
  }
  printf("7");
end:
  for (int i = 0; i < n; i++) {
    free(square[i]);
    free(target[i]);
    free(tmp[i]);
  }
  free(square);
  free(target);
  free(tmp);
}
