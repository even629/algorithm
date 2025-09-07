#include <stdio.h>

// N=52×(7X+21K)=364X+1092K

int main() {
  int N, X = -1, K = 0;
  scanf("%d", &N);

  for (int k = 1; k <= N / 1092; k++) {
    if ((N - 1092 * k) % 364 == 0 && (N - 1092 * k) / 364 <= 100) {
      X = (N - 1092 * k) / 364;
      K = k;
      goto end;
    }
  }

end:
  printf("%d\n%d", X, K);
}