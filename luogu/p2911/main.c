#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM 20 + 20 + 40

int main() {
  int S1, S2, S3;
  int arr[MAX_NUM + 1];
  int max = INT_MIN;
  int result;
  memset(arr, 0, sizeof(arr));
  scanf("%d %d %d", &S1, &S2, &S3);
  for (int i = 1; i <= S1; i++) {
    for (int j = 1; j <= S2; j++) {
      for (int k = 1; k <= S3; k++) {
        arr[i + j + k]++;
      }
    }
  }
  for (int i = 3; i < MAX_NUM + 1; i++) {
    if (arr[i] != 0 && arr[i] > max) {
      max = arr[i];
      result = i;
    }
  }
  printf("%d", result);
}
