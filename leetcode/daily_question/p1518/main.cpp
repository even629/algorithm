#include <stdio.h>
class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    // 每numExchange个bottles喝完可以换一瓶bottle
    int exchange_bootles = -1;
    int total_water = 0;
    do {
      exchange_bootles = numBottles / numExchange;
      numBottles = numBottles % numExchange;
      numBottles += exchange_bootles;
      total_water += exchange_bootles * numExchange;

    } while (numBottles >= numExchange);
    total_water += numBottles;
    return total_water;
  }
};

int main() {
  Solution s;
  printf("%d", s.numWaterBottles(9, 3));
}
