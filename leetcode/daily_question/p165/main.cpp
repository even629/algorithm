#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
using std::string;
using std::stringstream;
using std::vector;

class Solution {
public:
  int compareVersion(string version1, string version2) {
    int n, i;
    int v1, v2;
    int revision_number;
    string revision_number_str;
    vector<int> vec1, vec2;
    stringstream ss(version1);

    while (std::getline(ss, revision_number_str, '.')) {
      try {
        revision_number = std::stoi(revision_number_str);
      } catch (std::exception e) {
        printf("illegal input: %s\n", e.what());
        exit(-1);
      }
      vec1.push_back(revision_number);
    }

    // 覆盖缓冲区内容
    ss.str(version2);
    // 重置状态位
    ss.clear();
    while (std::getline(ss, revision_number_str, '.')) {
      try {
        revision_number = std::stoi(revision_number_str);
      } catch (std::exception e) {
        printf("Illegal input: %s\n", e.what());
        exit(-1);
      }
      vec2.push_back(revision_number);
    }
    n = vec1.size() > vec2.size() ? vec1.size() : vec2.size();

    for (i = 0; i < n; i++) {
      // 赋值
      if (i < vec1.size())
        v1 = vec1[i];
      else
        v1 = 0;
      if (i < vec2.size())
        v2 = vec2[i];
      else
        v2 = 0;

      if (v1 < v2) {
        return -1;
      } else if (v1 > v2) {
        return 1;
      } else {
        continue;
      }
    }
    return 0;
  }
};
