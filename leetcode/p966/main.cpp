#include <ctype.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  // 存储未处理的字符串
  unordered_set<string> words_perfect;
  // 存储小写后的字符串和原字符串的映射
  unordered_map<string, string> words_cap;
  // 存储将元音字母都转换为*的字符串和原字符串的映射
  unordered_map<string, string> words_vow;

  // 将元音字母都转换为*
  string devowel(string word) {
    string ans;
    for (char c : word) {
      ans += isVowel(c) ? '*' : c;
    }
    return ans;
  }
  // 判断是否是否是元音字母
  bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }

  string match(string query) {
    // 完全匹配
    if (words_perfect.count(query)) {
      return query;
    }
    // 大小写
    string queryL;
    for (char c : query) {
      queryL += tolower(c);
    }
    if (words_cap.count(queryL)) {
      return words_cap[queryL];
    }
    // 都转为小写字母后，查找元音字母
    string queryLV = devowel(queryL);
    if (words_vow.count(queryLV)) {
      return words_vow[queryLV];
    }

    return "";
  }

public:
  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    // 填充set和两个map
    for (string word : wordlist) {
      words_perfect.insert(word);
      string wordlow;
      for (char c : word) {
        wordlow += tolower(c);
      }
      if (!words_cap.count(wordlow)) {
        words_cap[wordlow] = word;
      }
      // 都转成小写字母后再将元音字母转为*
      string wordlowDV = devowel(wordlow);
      if (!words_vow.count(wordlowDV)) {
        words_vow[wordlowDV] = word;
      }
    }

    vector<string> ans;
    for (string query : queries) {
      ans.push_back(match(query));
    }
    return ans;
  }
};
