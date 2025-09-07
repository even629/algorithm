#include <stdio.h>
#include <stdlib.h>
// num * right 结果存放在num中，返回num的长度len
int high_accuracy_multiply(int **num, int len, int right) {
  int carry = 0, i = 0, temp = 0;
  int *new_arr;
  while (1) {
    if (i <= len - 1) {
      temp = ((*num)[i] * right + carry) / 10;
      (*num)[i] = ((*num)[i] * right + carry) % 10;
      carry = temp;
      i++;
    } else if (i == len && carry != 0) {  // 最高位有进位但是没有容量了
      new_arr = (int *)realloc(*num, (len + 1) * sizeof(int));
      if (new_arr == NULL) {
        perror("realloc error");
        free(*num);
        exit(-1);
      } else {
        *num = new_arr;
      }
      len++;
      (*num)[i] = carry % 10;
      carry = carry / 10;
      i++;
    } else if (i == len && carry == 0) {
      break;
    }
  }
  return len;
}

// num1+num2结果存在res中,返回res的长度len
int high_accuracy_add(int num1[], int len1, int num2[], int len2, int **res) {
  int carry = 0, temp = 0;
  int *left, llen;
  int *right, rlen;
  int *new_arr;
  int *result;
  /**
   * find the longer one and name it as left ,the other as right
   */
  if (len1 >= len2) {
    left = num1;
    llen = len1;
    right = num2;
    rlen = len2;
  } else {
    left = num2;
    llen = len2;
    right = num1;
    rlen = len1;
  }

  result = (int *)malloc(llen * sizeof(int));

  /**
   * calcualte
   */
  for (int i = 0; i < llen; i++) {
    if (i < rlen) {
      temp = right[i];
    } else {
      temp = 0;
    }
    result[i] = (left[i] + temp + carry) % 10;
    carry = (left[i] + temp + carry) / 10;
  }
  if (carry != 0) {  // 最高位有进位
    new_arr = (int *)realloc(result, (llen + 1) * sizeof(int));
    if (new_arr == NULL) {
      perror("realloc error\n");
      free(result);
      exit(-1);
    } else {
      result = new_arr;
      llen++;
      result[llen - 1] = carry;
    }
  }

  if (*res == num2) {
    free(num2);
  } else if (*res == num1) {
    free(num1);
  }
  *res = result;
  return llen;
}

int main() {
  int n = 0;
  int *result, len;
  int *S, slen;

  scanf("%d", &n);

  /**
   * 计算阶乘并保存到factorial数组中，长度保存在lens中
   */
  result = (int *)malloc(sizeof(int));
  len = 1;
  result[0] = 1;

  S = (int *)malloc(sizeof(int));
  slen = 1;
  S[0] = 1;

  for (int i = 1; i < n; i++) {
    len = high_accuracy_multiply(&result, len, i + 1);
    slen = high_accuracy_add(result, len, S, slen, &S);
  }

  for (int i = slen - 1; i >= 0; i--) {
    printf("%d", S[i]);
  }
  return 0;
}