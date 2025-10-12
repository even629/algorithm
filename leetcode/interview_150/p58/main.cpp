#include <string>
using std::string;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int len = s.size();
    int i = len - 1;
    int end = 0, start = -1;
    while (i >= 0) {
      if (std::isalpha(s[i])) {
        end = i;
        break;
      }
      i--;
    }
    while (i >= 0) {
      if (!std::isalpha(s[i])) {
        start = i;
        break;
      }
      i--;
    }
    if (start != -1) {
      return end - start;
    } else {
      return end - 0 + 1;
    }
  }
};
