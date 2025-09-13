#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
  int n, *arr;
  int min = INT_MAX,max = INT_MIN;
  int result;
  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d",&arr[i]);
    if(arr[i] > max){
      max = arr[i];
    }
    if(arr[i] < min){
      min = arr[i];
    }
  }
  result = max -min;
  printf("%d",result);
}