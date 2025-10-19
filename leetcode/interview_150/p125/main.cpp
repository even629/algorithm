#include <algorithm>
#include <cstring>
#include <string>
using std::string;

class Solution {
public:
  bool isPalindrome(string s) {
    int i;
    int n = s.size();
    string original;
    for (i = 0; i < n; i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        s[i] = s[i] - ('A' - 'a');
      }
      if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= '0' && s[i] <= '9')) {
        s[i] = '*';
      }
    }

    s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
    original = s;
    std::reverse(s.begin(), s.end());
    if (std::strcmp(s.c_str(), original.c_str()) == 0) {
      return true;
    } else {
      return false;
    }
  }
};
