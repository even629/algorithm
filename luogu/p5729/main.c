#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int i;
  int j;
  int k;
} Cube;

typedef struct {
  Cube *arr;
  int len;
  int capacity;
} Stack;

void init_stack(Stack *stack) {
  stack->len = 0;
  stack->capacity = 2;
  stack->arr = (Cube *)malloc(stack->capacity * sizeof(Cube));
}

void push(Stack *stack, Cube *cube) {
  if (stack->len == stack->capacity) {
    stack->capacity += 10;
    Cube *new_arr;
    new_arr = realloc(stack->arr, stack->capacity * sizeof(Cube));
    if (new_arr != NULL) {
      stack->arr = new_arr;
    } else {
      free(stack->arr);
      perror("realloc error");
      exit(-1);
    }
  }

  stack->arr[stack->len] = *cube;
  stack->len++;
}

bool in(Stack *stack, Cube *cube) {
  for (int i = 0; i < stack->len; i++) {
    if (stack->arr[i].i == cube->i && stack->arr[i].j == cube->j &&
        stack->arr[i].k == cube->k) {
      return true;
    }
  }
  return false;
}

int main() {
  int w, x, h;
  int q;
  int *arr;
  int x1_tmp, y1_tmp, z1_tmp;
  int x2_tmp, y2_tmp, z2_tmp;

  scanf("%d %d %d", &w, &x, &h);
  scanf("%d", &q);
  Stack stack;
  init_stack(&stack);
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d %d %d %d", &x1_tmp, &y1_tmp, &z1_tmp, &x2_tmp, &y2_tmp,
          &z2_tmp);
    for (int a = x1_tmp; a <= x2_tmp; a++) {
      for (int b = y1_tmp; b <= y2_tmp; b++) {
        for (int c = z1_tmp; c <= z2_tmp; c++) {
          Cube curr_cube;
          curr_cube.i = a;
          curr_cube.j = b;
          curr_cube.k = c;
          if (!in(&stack, &curr_cube)) {
            push(&stack, &curr_cube);
          }
        }
      }
    }
  }

  printf("%d", (w * x * h) - stack.len);
  free(stack.arr);
}
