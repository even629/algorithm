#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  int cute;
} Fish;

// int compare(const void *e1, const void *e2) {
//   return ((Fish *)e1)->cute - ((Fish *)e2)->cute;
// }

int main() {
  int n, *arr, temp;
  Fish *fish;
  scanf("%d", &n);

  fish = (Fish *)malloc(n * sizeof(Fish));
  arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    fish[i].id = i;
    scanf("%d", &fish[i].cute);
    temp = 0;
    for (int j = 0; j < i; j++) {
      if (fish[j].cute < fish[i].cute) {
        temp++;
      }
    }
    arr[i] = temp;
  }
  // qsort(fish, n, sizeof(Fish), compare);

  // for (int i = 0; i < n; i++) {
  //   arr[fish[i].id] = i;
  // }

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
