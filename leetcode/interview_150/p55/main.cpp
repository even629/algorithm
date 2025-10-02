#include <queue>
#include <unordered_set>
#include <vector>

using std::queue;
using std::unordered_set;
using std::vector;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int n = nums.size();
    int jmp;
    int curr;
    int i, tmp;
    queue<int> que;
    unordered_set<int> uset;
    if (n == 1) {
      return true;
    }

    que.push(0);
    uset.insert(0);
    do {
      curr = que.front();
      jmp = nums[curr];
      if (jmp == 0) {
        que.pop();
        uset.erase(curr);
        continue;
      }

      for (i = 1; i <= jmp; i++) {
        tmp = curr + i;
        if (tmp == n - 1) {
          return true;
        } else if (tmp < n && uset.count(tmp) == 0) {
          que.push(tmp);
          uset.insert(tmp);
        }
      }
      uset.erase(curr);
      que.pop();

    } while (!que.empty());

    return false;
  }
};

#include <stdio.h>
int main() {
  Solution S;
  vector<int> vec = {2, 5, 0, 0};
  printf("%d\n", S.canJump(vec));
}
