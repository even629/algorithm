#include <sstream>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>

using std::pair;
using std::string;
using std::vector;

class Spreadsheet {
private:
  vector<vector<int>> sheet;
  pair<int, int> get_row_and_column(const string &s) {
    int column = s[0] - 'A';
    int row;
    try {
      row = std::stoi(s.substr(1).c_str());
    } catch (std::exception &e) {
      printf("%s\n", e.what());
      exit(-1);
    }
    row = row - 1;
    return {row, column};
  }

public:
  Spreadsheet(int rows) {
    // 初始化
    sheet.assign(rows, vector<int>(26, 0));
  }

  void setCell(string cell, int value) {
    auto [row, column] = get_row_and_column(cell);
    sheet[row][column] = value;
  }

  void resetCell(string cell) {
    auto [row, column] = get_row_and_column(cell);
    sheet[row][column] = 0;
  }

  int getValue(string formula) {
    int res_value = 0;
    string formula_s = formula.substr(1);
    std::stringstream ss(formula_s);
    vector<string> values;
    string token;
    while (std::getline(ss, token, '+')) {
      values.push_back(token);
    }
    int int_value;
    for (string value : values) {
      try {
        int_value = std::stoi(value);
      } catch (std::invalid_argument) {
        auto [row, column] = get_row_and_column(value);
        int_value = sheet[row][column];
      }
      res_value += int_value;
    }
    return res_value;
  }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
int main() {
  // ["Spreadsheet","getValue"]
  // [[458],["=O126+10272"]]

  Spreadsheet *obj = new Spreadsheet(458);
  int result = obj->getValue("=O126+10272");
  printf("result is %d\n", result);
  delete obj;

  return 0;
}
