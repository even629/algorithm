#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr, *new_arr;
  int capacity = 2;
  int temp;
  int index = 0;

  arr = (int *)malloc(capacity * sizeof(int));

  while (scanf("%d", &temp)) {
    if (temp == 0) {
      break;
    }

    // 超过arr存储的范围
    if (index == capacity) {
      capacity = capacity + 10;
      new_arr = (int *)realloc(arr, capacity * sizeof(int));
      if (new_arr == NULL) {
        perror("realloc error");
        free(arr);
        return -1;
      } else {
        arr = new_arr;
      }
    }

    arr[index++] = temp;
  }
  if (index == 0) {
    return 0;
  }

  capacity = index;
  new_arr = (int *)realloc(arr, capacity * sizeof(int));
  if (new_arr == NULL) {
    perror("realloc error");
    free(arr);
    return -1;
  } else {
    arr = new_arr;
  }

  int *lptr = arr, *rptr = arr + capacity - 1;

  while (lptr < rptr) {
    temp = *lptr;
    *lptr = *rptr;
    *rptr = temp;
    lptr++;
    rptr--;
  }

  for (int i = 0; i < capacity; i++) {
    printf("%d ", arr[i]);
  }

  free(arr);
  return 0;
}
