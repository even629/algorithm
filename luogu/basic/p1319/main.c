#include <stdio.h>
#include <stdlib.h>

int m_i = 0;
int m_j = 0;
void set_matrix_in_order(int **matrix, int N, int num);

int main() {
  int N;
  int **matrix;
  int total;
  int num = 0;
  int type = 0;

  scanf("%d", &N);
  total = N * N;
  int arr[N * N];

  for (int i = 0; i < N * N; i++) {
    scanf("%d", &arr[i]);
    total -= arr[i];
    num++;
    if (total == 0) {
      break;
    }
  }

  matrix = (int **)malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    matrix[i] = (int *)malloc(N * sizeof(int));
  }

  for (int i = 0; i < num; i++) {
    if (type == 0) { // 多少个0
      for (int j = 0; j < arr[i]; j++) {
        set_matrix_in_order(matrix, N, 0);
      }

    } else if (type == 1) { // 多少个1
      for (int j = 0; j < arr[i]; j++) {
        set_matrix_in_order(matrix, N, 1);
      }

    } else {
      __builtin_unreachable();
    }

    type = type ^ 1;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", matrix[i][j]);
    }
    printf("\n");
  }
}

void set_matrix_in_order(int **matrix, int N, int num) {
  matrix[m_i][m_j] = num;
  if (m_j == N - 1 && m_i != N - 1) {
    m_i++;
    m_j = 0;
  } else if (m_j == N - 1 && m_i == N - 1) {
    return;
  } else {
    m_j++;
  }
}
