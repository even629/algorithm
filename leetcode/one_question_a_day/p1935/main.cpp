#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

using std::string;
using std::stringstream;
using std::vector;

class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    stringstream ss(text);
    string token;
    vector<string> words;
    int broken = 0;
    while (std::getline(ss, token, ' ')) {
      words.push_back(token);
    }
    for (string word : words) {
      for (char ch : brokenLetters) {
        if (word.find(ch) != string::npos) {
          broken++;
          break;
        }
      }
    }
    return words.size() - broken;
  }
};

int main() {
  Solution s;
  int res = s.canBeTypedWords(string("hello world"), string("ad"));
  printf("%d\n", res);
}
