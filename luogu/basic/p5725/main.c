#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  int total;
  scanf("%d", &n);
  /**
   *  print square
   */
  total = n * n;
  for (int i = 1; i <= total; i++) {
    printf("%02d", i);
    if (i % n == 0) {
      printf("\n");
    }
  }

  printf("\n");
  /**
   * print triangle
   */
  int count = 1, space;
  for (int i = 1; i <= n; i++) {
    space = (n - i);
    for (int j = 1; j <= n; j++) {
      if (space > 0) {
        // 2 spaces
        printf("  ");
        space--;
        continue;
      }
      printf("%02d", count);
      count++;
    }
    printf("\n");
  }
}
