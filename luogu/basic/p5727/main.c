#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *arr;
  int length;
  int capacity;
} Stack;

void init_stack(Stack *s) {
  s->capacity = 2;
  s->length = 0;
  s->arr = (int *)malloc(s->capacity * sizeof(int));
}

void push(Stack *s, int num) {
  if (s->length == s->capacity) {
    s->capacity += 10;
    int *new_arr = (int *)realloc(s->arr, s->capacity * sizeof(int));

    if (new_arr == NULL) {
      perror("out of memory\n");
      free(s->arr);
      return;
    } else {
      s->arr = new_arr;
    }
  }
  s->arr[s->length] = num;
  s->length++;
}

bool pop(Stack *s, int *res) {
  if (s->length == 0) {
    return false;
  }
  *res = s->arr[s->length - 1];
  s->length--;

  return true;
}

void destroy_stack(Stack *s) {
  free(s->arr);
  s->length = 0;
  s->capacity = 0;
}

int main() {
  int n;
  Stack s;
  scanf("%d", &n);

  if (n == 1) {
    printf("1");
    return 0;
  }

  init_stack(&s);
  push(&s, n);

  do {
    if (n % 2 != 0) {
      // 奇数
      n = n * 3 + 1;
    } else {
      // 偶数
      n = n / 2;
    }
    push(&s, n);

  } while (n != 1);

  while (pop(&s, &n)) {
    printf("%d ", n);
  }

  destroy_stack(&s);
  return 0;
}
