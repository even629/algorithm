#include <algorithm>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

const int MOD = 1000000007; // 10^9 + 7

class Solution {
public:
  bool magicalSeq(vector<int> &seq, int m, int k, int length) {
    // 魔法序列：seq 的序列长度为 m。
    // 0 <= seq[i] < nums.length
    // 2^seq[0] + 2^seq[1] + ... + 2^seq[m - 1] 的 二进制形式 有 m 个 置位。
    // 也就是说{seq[0], seq[1] ..seq[M-1]}中,如果两个数相同
    // 递归地将相同的数合并成一个原来的数值+1，直到没有相同地数为止
    int val;
    int set = 0;
    if (seq.size() != m) {
      return false;
    }

    std::sort(seq.begin(), seq.end());

    if (seq[0] < 0 || seq[m - 1] >= length) {
      return false;
    }

    stack<int, std::vector<int>> st(seq);

    while (!st.empty()) {
      val = st.top();
      st.pop();
      set++;
      if (!st.empty() && val == st.top()) {
        st.top()++;
        set--;
      }
    }

    if (set == k) {
      return true;
    } else {
      return false;
    }
  }

  int magicalSum(int m, int k, vector<int> &nums) {
    int i, j;
    int n = nums.size();
    unsigned long magical_sum = 0;
    unsigned long array_mul;

    vector<vector<int>> result;
    int res_size;

    if (m <= n) {
      // 生成长度为m的nums的所有子序列
      // predict数组，类似于SVE指令
      vector<int> predict(n, 0);
      // 从字典序最小的开始
      std::fill(predict.end() - m, predict.end(), 1);

      do {
        vector<int> tmp;
        for (i = 0; i < n; i++) {
          if (predict[i] != 0) {
            tmp.push_back(i);
          }
        }

        result.push_back(tmp);
      } while (std::next_permutation(predict.begin(), predict.end()));
    }

    res_size = result.size();
    // 判断是不是magic sequence
    for (i = 0; i < res_size; i++) {
      if (magicalSeq(result[i], m, k, n)) {
        // 如果是magic sequence，计算它的全排列的数组乘积
        // 但如果数字相同，排列不同，数组乘积是一样的
        // 因此直接乘以 m 的阶乘
        array_mul = 1;
        for (j = 0; j < m; j++) {
          array_mul = (array_mul * nums[result[i][j]]) % MOD;
        }
        for (j = 1; j <= m; j++) {
          array_mul = (array_mul * j) % MOD;
        }
        magical_sum = (magical_sum + array_mul) % MOD;
      }
    }
    return magical_sum;
  }
};
