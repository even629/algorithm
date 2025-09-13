#include <math.h>
#include <stdio.h>
#include <string.h>
#define MAX_LEN 2000000 + 1
int main() {
  int n, t;
  double a;
  int arr[MAX_LEN];
  int temp;
  memset(arr, 0, sizeof(arr));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf %d", &a, &t);
    for (int j = 1; j <= t; j++) {
      temp = (int)(j * a);
      arr[temp] = ~arr[temp] & 0x00000001;
    }
  }

  for (int i = 1; i < MAX_LEN; i++) {
    if (arr[i] == 1) {
      printf("%d", i);
      break;
    }
  }
  return 0;
}
