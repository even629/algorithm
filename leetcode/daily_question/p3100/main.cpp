class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    // 贪心，总是喝完所有水，如果没水就交换
    int full_bottles = numBottles;
    int empty_bottles = 0;
    int num_exchange = numExchange;
    int bottle_drunk = 0;

    while (full_bottles > 0 || empty_bottles >= num_exchange) {
      // drink
      bottle_drunk += full_bottles;
      empty_bottles += full_bottles;
      full_bottles = 0;
      // exchange
      while (empty_bottles >= num_exchange) {
        empty_bottles -= num_exchange;
        num_exchange++;
        full_bottles++;
      }
    }
    return bottle_drunk;
  }
};
