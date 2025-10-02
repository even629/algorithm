#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isVowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
      c == 'E' || c == 'I' || c == 'O' || c == 'U') {
    return true;
  }
  return false;
}
// 递增
int comparefunc(const void *a, const void *b) {
  return *(char *)a - *(char *)b;
}
char *sortVowels(char *s) {

  int len;
  int vowel_count = 0;
  char *str, *vowels;
  int index = 0;

  len = strlen(s);
  // 注意要复制len + 1个字节
  str = malloc((len + 1) * sizeof(char));
  strcpy(str, s);

  for (int i = 0; i < len; i++) {
    if (isVowel(str[i])) {
      vowel_count++;
    }
  }
  vowels = (char *)malloc(vowel_count * sizeof(char));
  for (int i = 0; i < len && index < vowel_count; i++) {
    if (isVowel(str[i])) {
      vowels[index] = str[i];
      index++;
    }
  }
  qsort(vowels, vowel_count, sizeof(char), comparefunc);
  index = 0;
  for (int i = 0; i < len && index < vowel_count; i++) {
    if (isVowel(str[i])) {
      str[i] = vowels[index];
      index++;
    }
  }
  free(vowels);
  return str;
}

int main() {
  // 常量字符串不可修改
  char *s = "lEetcOde";
  char *str;
  str = sortVowels(s);
  printf("%s\n", str);
  free(str);
}
