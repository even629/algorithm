#define _GNU_SOURCE
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char *str = NULL;
  size_t len = 0;
  ssize_t nread;
  int type = 0;
  int tmp = 0;
  int N;

  nread = getline(&str, &len, stdin);
  // len = 8, 7个字符+\n
  if (nread != -1) {
    // 去掉换行符
    str[strcspn(str, "\n")] = '\0';
  } else {
    perror("geline failed\n");
    exit(-1);
  }
  N = strlen(str);
  printf("%d ", N);

  // 处理第一行
  for (int j = 0; j < N; j++) {
    if (str[j] - '0' == type) {
      tmp++;
    } else {
      type = type ^ 1;
      printf("%d ", tmp);
      tmp = 1;
    }
  }

  for (int i = 1; i < N; i++) {
    nread = getline(&str, &len, stdin);
    if (nread != -1) {
      // 去掉换行符
      str[strcspn(str, "\n")] = '\0';
    } else {
      perror("geline failed\n");
      exit(-1);
    }
    for (int j = 0; j < N; j++) {
      if (str[j] - '0' == type) {
        tmp++;
      } else {
        type = type ^ 1;
        printf("%d ", tmp);
        tmp = 1;
      }
    }
  }
  printf("%d ", tmp);
  return 0;
}
