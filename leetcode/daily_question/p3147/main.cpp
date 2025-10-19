#include <algorithm>
#include <climits>
#include <vector>
using std::vector;

class Solution {
public:
  int maximumEnergy(vector<int> &energy, int k) {

    // 所有路径{0..k-1} - {n-1-k..n-1}
    // 每条路径起点为0~k-1，计算每条路径的最大能量，然后从这几个路径的最大能量中找最大的
    // 对于一条路径的最大能量就是找从一个起点开始到最后一个值的最大和
    // 那么不妨从最后一个起点向前遍历，记录最大和

    int i, j;
    int total = 0;
    int n = energy.size();
    vector<int> way(n, INT_MIN);

    for (i = 0; i < k; i++) { // 每条路径
      j = 0;
      while (i + j * k < n) {
        j++;
      }
      j--;
      total = 0;

      while (j >= 0) {
        total += energy[i + j * k];
        way[i] = std::max(way[i], total);
        j--;
      }
    }

    return *std::max_element(way.begin(), way.end());
  }
};

#include <stdio.h>
int main() {
  Solution s;
  vector<int> vec = {5, 2, -10, -5, 1};
  printf("%d\n", s.maximumEnergy(vec, 3));
}
