#include <algorithm>
#include <stack>
#include <string.h>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution {
public:
  bool isAnagram(string s1, string s2) {
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    if (strcmp(s1.c_str(), s2.c_str()) == 0) {
      return true;
    } else {
      return false;
    }
  }
  vector<string> removeAnagrams(vector<string> &words) {
    stack<string> st;
    vector<string> vec;
    string top_string;
    for (string word : words) {
      if (st.empty()) {
        st.push(word);
        continue;
      } else {
        top_string = st.top();
        if (isAnagram(top_string, word)) {
          continue;
        } else {
          st.push(word);
        }
      }
    }
    while (!st.empty()) {
      vec.push_back(st.top());
      st.pop();
    }
    std::reverse(vec.begin(), vec.end());
    return vec;
  }
};
