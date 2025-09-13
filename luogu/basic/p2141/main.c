#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int compare_func(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  int n;
  int *arr;
  int res = 0;

  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  qsort(arr, n, sizeof(int), compare_func);

  for (int k = n - 1; k >= 2; k--) {

    for (int i = k - 1; i >= 1; i--) {
      for (int j = k - 2; j >= 0; j--) {
        if (arr[i] == arr[j]) {
          continue;
        }
        if (arr[i] + arr[j] == arr[k]) {
          res++;
          goto next;
        }
      }
    }
  next:
  }
  printf("%d", res);
  free(arr);
}
