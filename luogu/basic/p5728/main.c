#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int chi;
  int math;
  int eng;
} StuGrade;

int main() {
  int N, pair = 0;
  StuGrade *arr;
  scanf("%d", &N);
  arr = (StuGrade *)malloc(N * sizeof(StuGrade));
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &arr[i].chi, &arr[i].math, &arr[i].eng);
  }

  int chi_offset, math_offset, eng_offset;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      chi_offset = abs(arr[i].chi - arr[j].chi);
      math_offset = abs(arr[i].math - arr[j].math);
      eng_offset = abs(arr[i].eng - arr[j].eng);
      if (chi_offset <= 5 && math_offset <= 5 && eng_offset <= 5 &&
          abs(arr[i].chi + arr[i].math + arr[i].eng - arr[j].chi - arr[j].math -
                  arr[j].eng <=
              10)) {
        pair++;
      }
    }
  }

  printf("%d", pair);
  free(arr);
  return 0;
}
