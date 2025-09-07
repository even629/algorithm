#include <stdio.h>
#include <string.h>

int main() {
  int M, N;
  int tmp;
  int arr[10];
  memset(arr, 0, sizeof(arr));
  scanf("%d %d", &M, &N);
  for (int i = M; i <= N; i++) {
    tmp = i;
    while (tmp != 0) {
      arr[tmp % 10]++;
      tmp /= 10;
    }
  }
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
