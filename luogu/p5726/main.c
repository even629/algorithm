#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
  int n, *arr;
  int max = INT_MIN, min = INT_MAX , total = 0;
  double score;

  scanf("%d", &n);

  arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d",&arr[i]);
    if(arr[i]>max){
      max = arr[i];
    }
    if(arr[i]< min){
      min = arr[i];
    }
    total += arr[i];
  }

  score = ((double)(total-max-min))/ (n-2);
  printf("%.2lf",score);
  
  
}