#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
  // 一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文
  // 并且 至少 有 h 篇论文被引用次数大于等于 h 。如果 h 有多种可能的值，h 指数
  // 是其中最大的那个。
  int hIndex(vector<int> &citations) {
    int n;
    n = citations.size();
    int h = 0;
    std::sort(citations.begin(), citations.end());
    for (int i = 1; i <= n; i++) { // 遍历h
      if (citations[n - i] >= i) {
        h = std::max(h, i);
      }
    }
    return h;
  }
};
