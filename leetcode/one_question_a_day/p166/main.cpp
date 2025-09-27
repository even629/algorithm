#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {

    unsigned long long dividend;
    unsigned long long divisor;
    unsigned long long quotient;
    unsigned long long reminder;
    int dot = -1;
    int bracket = -1;
    // 记录结果
    vector<int> res_vec;
    // 记录numerator的每一位
    vector<int> numerator_vec;
    // 记录所有被除数
    unordered_map<unsigned long long, unsigned long long> div_map;
    string res;
    int i = 0;
    int n;
    bool negative = false;

    // 0除以任何数都为0
    if (numerator == 0) {
      return "0";
    }
    if ((numerator < 0 && denominator > 0) ||
        (numerator > 0 && denominator < 0)) {
      negative = true;
    }
    // 不用abs主要是因为abs返回的是unsigned int存在范围问题
    dividend = std::llabs((long long)numerator);
    divisor = std::llabs((long long)denominator);

    // 先都除以最大公因数
    // n = std::gcd(dividend, divisor);
    // dividend /= n;
    // divisor /= n;

    // 将numerator每一位放入numerator_vec中
    while (dividend != 0) {
      numerator_vec.insert(numerator_vec.begin(), dividend % 10);
      dividend /= 10;
    }
    dividend = 0;
    // 高精度除法

    // 第一个被除数
    n = numerator_vec.size();
    while (i < n && dividend < divisor) {
      dividend = dividend * 10 + numerator_vec[i];
      i++;
    }

    do {
      // 记录被除数
      if (div_map.find(dividend) != div_map.end() && dot > 0) { // 重复了
        bracket = div_map[dividend];                            // 重复的位置
        break;
      } else {
        div_map[dividend] = res_vec.size();
      }
      // 商 = 被除数/除数
      quotient = dividend / divisor;
      // 余数 = 被除数/除数
      reminder = dividend % divisor;
      res_vec.push_back(quotient);

      if (i < numerator_vec.size()) {
        dividend = reminder * 10 + numerator_vec[i];
        i++;
        reminder = 1; // 防止退出循环
      } else {
        dividend = reminder * 10;
        if (dot < 0)
          dot = res_vec.size();
      }

    } while (reminder != 0);

    if (bracket >= 0 && dot > 0 && bracket < dot) {
      n = dot - bracket;
      for (i = 0; i < n; i++) {
        res_vec.push_back(res_vec[i + bracket]);
      }
      bracket = dot;
    }

    n = res_vec.size();
    // 构建字符串
    if (negative) {
      res += '-';
    }

    for (i = 0; i < n; i++) {
      if (i == dot) {
        res += '.';
      }
      if (i == bracket) {
        res += '(';
      }

      res += '0' + res_vec[i];
    }

    if (bracket > 0) {
      res += ')';
    }

    return res;
  }
};

int main() {
  Solution s;
  printf("%s\n", s.fractionToDecimal(420, 226).c_str());
  printf("%s\n", s.fractionToDecimal(-22, -2).c_str());
  printf("%s\n", s.fractionToDecimal(500, 10).c_str());
  printf("%s\n", s.fractionToDecimal(4, 333).c_str());
  printf("%s\n", s.fractionToDecimal(50, 8).c_str());
}
