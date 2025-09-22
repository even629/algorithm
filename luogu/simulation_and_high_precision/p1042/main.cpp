#include <stdio.h>

#include <iostream>
#include <string>

using std::string;

// 其中 W 表示华华获得一分, L 表示华华对手获得一分
void judge_competition(const string &info, int score_type) {
  if (info.empty()) {
    printf("0:0\n");
    return;
  }

  int hua = 0, rival = 0;
  int n = info.size();
  char ch;
  for (int i = 0; i < n; i++) {
    ch = info[i];
    if (ch == 'W') {
      hua++;
    } else if (ch == 'L') {
      rival++;
    } else {
      perror("wrong info\n");
      exit(-1);
    }
    //
    if (((hua >= score_type || rival >= score_type) &&
         std::abs(hua - rival) >= 2) ||
        i == n - 1) {
      printf("%d:%d\n", hua, rival);
      hua = 0;
      rival = 0;
    }
  }
}

int main() {
  string competition_info;
  string info;
  bool end = false;

  while (std::getline(std::cin, competition_info, '\n')) {
    if (competition_info.find('E') != string::npos) {
      competition_info.erase(competition_info.begin() +
                                 competition_info.find('E'),
                             competition_info.end());

      end = true;
    }
    info += competition_info;

    if (end)
      break;
  }
  // 11分制
  judge_competition(info, 11);
  printf("\n");
  // 21分制
  judge_competition(info, 21);

  return 0;
}
