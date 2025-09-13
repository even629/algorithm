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

int maxFreqSum(char *s) {

  int len;
  int arr[58];
  len = strlen(s);

  memset(arr, 0, 58 * sizeof(int));

  for (int i = 0; i < len; i++) {
    arr[s[i] - 'A']++;
  }
  int vowel_max = 0;
  int consonant_max = 0;
  for (int i = 0; i < 58; i++) {

    if (isVowel('A' + i) && arr[i] > vowel_max) {
      vowel_max = arr[i];
    }

    if (!isVowel('A' + i) && arr[i] > consonant_max) {
      consonant_max = arr[i];
    }
  }
  return vowel_max + consonant_max;
}
int main() {

  int n;
  n = maxFreqSum("successes");
  printf("%d", n);
}
