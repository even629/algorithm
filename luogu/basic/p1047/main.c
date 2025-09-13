#include <stdio.h>
#include <stdlib.h>

int main() {
  int l, m;
  int *road;
  int ltmp, rtmp;
  int total = 0;

  scanf("%d %d", &l, &m);
  l++;
  road = (int *)malloc(l * sizeof(int));
  for (int i = 0; i < l; i++) {
    road[i] = 1;
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &ltmp, &rtmp);
    for (int j = ltmp; j <= rtmp; j++) {
      road[j] = 0;
    }
  }

  for (int i = 0; i < l; i++) {
    if (road[i] == 1) {
      total++;
    }
  }
  printf("%d", total);

  free(road);
  return 0;
}
