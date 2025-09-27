#include <stdbool.h>
#include <string.h>
bool isVowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
      c == 'E' || c == 'I' || c == 'O' || c == 'U') {
    return true;
  }
  return false;
}

bool doesAliceWin(char *s) {
  int vowel_num = 0;
  int len;
  len = strlen(s);
  // 统计所有的元音数目
  for (int i = 0; i < len; i++) {
    if (isVowel(s[i])) {
      vowel_num++;
    }
  }
  if (vowel_num == 0) {
    return false;
  }

  if (vowel_num % 2 == 0) { // 偶数
    return true;
  } else { // 奇数
    return true;
  }
}
