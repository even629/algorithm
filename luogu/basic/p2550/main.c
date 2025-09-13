#include <stdio.h>
#include <string.h>

int winning_rank(int winning_number[], int arr[]) {
  int result = 0;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      if (winning_number[j] == arr[i]) {
        result++;
        break;
      }
    }
  }
  return result;
}

int main() {
  int n;
  int winning_number[7];
  int prize_nums[7];
  int arr[7];
  // 清零
  memset(prize_nums, 0, sizeof(prize_nums));
  scanf("%d", &n);

  scanf("%d %d %d %d %d %d %d", &winning_number[0], &winning_number[1],
        &winning_number[2], &winning_number[3], &winning_number[4],
        &winning_number[5], &winning_number[6]);

  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4],
          &arr[5], &arr[6]);
    prize_nums[7 - winning_rank(winning_number, arr)]++;
  }

  printf("%d %d %d %d %d %d %d", prize_nums[0], prize_nums[1], prize_nums[2],
         prize_nums[3], prize_nums[4], prize_nums[5], prize_nums[6]);
}
