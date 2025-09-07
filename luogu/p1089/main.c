#include <stdio.h>

#define MONTH 12
int main() {
  int arr[MONTH];
  int money = 0, save = 0;

  for (int i = 0; i < MONTH; i++) {
    money += 300;
    scanf("%d", &arr[i]);
    // cost of current month
    money -= arr[i];
    if (money < 0) {  // short of money
      printf("-%d", i + 1);
      return 0;
    } else if (money > 100) {  // have more than 100 left
      save = save + (money / 100) * 100;
      money = money % 100;
    }
  }
  save = save * 1.2 + money;
  printf("%d", save);
  return 0;
}