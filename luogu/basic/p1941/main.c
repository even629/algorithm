#include <stdio.h>
#include <string.h>

int main() {
  int n;
  char pwd[50];
  int len;
  // n>1 && n<26
  scanf("%d", &n);
  scanf("%s", pwd);
  len = strlen(pwd);
  for (int i = 0; i < len; i++) {
    pwd[i] = (pwd[i] - 'a' + n) % 26 + 'a';
  }
  printf("%s", pwd);
}
