#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  int len;
  int offset;
  scanf("%s", str);
  len = strlen(str);
  offset = 'a' - 'A';
  for (int i = 0; i < len; i++) {
    if ((str[i] >= 'a' && str[i] <= 'z')) {
      str[i] = str[i] - offset;
    }
  }
  printf("%s", str);
}
