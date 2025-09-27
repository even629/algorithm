#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <vector>

using std::map;
using std::multiset;
using std::queue;
using std::set;
using std::vector;

class Packet {
public:
  int source;
  int destination;
  int timestamp;
  bool operator<(const Packet &other) const {
    if (destination != other.destination)
      return destination < other.destination;
    if (timestamp != other.timestamp)
      return timestamp < other.timestamp;
    return source < other.source;
  }
};

class Router {
private:
  set<Packet> router_set;
  queue<Packet> fifo;
  // destination->[timestamp array]
  map<int, multiset<int>> router_map;
  int memoryLimit;

public:
  Router(int memoryLimit) { this->memoryLimit = memoryLimit; }

  bool addPacket(int source, int destination, int timestamp) {
    struct Packet newPacket = {source, destination, timestamp};

    if (router_set.find(newPacket) != router_set.end()) {
      return false;
    }

    if (router_set.size() >= memoryLimit ||
        fifo.size() >= memoryLimit) { // out of memory
      Packet s = fifo.front();
      fifo.pop();
      router_set.erase(s);

      multiset<int> &timestamp_multiset = router_map[s.destination];
      timestamp_multiset.erase(timestamp_multiset.find(s.timestamp));
    }

    router_set.insert(newPacket);
    fifo.push(newPacket);

    router_map[destination].insert(timestamp);

    return true;
  }
  vector<int> forwardPacket() {
    vector<int> res;
    if (fifo.empty()) {
      return {};
    }

    Packet resPacket = fifo.front();
    fifo.pop();
    res = {resPacket.source, resPacket.destination, resPacket.timestamp};
    router_set.erase(resPacket);

    multiset<int> &timestamp_multiset = router_map[resPacket.destination];
    timestamp_multiset.erase(timestamp_multiset.find(resPacket.timestamp));

    return res;
  }

  int getCount(int destination, int startTime, int endTime) {
    int count = 0;
    multiset<int> &timestamp_multiset = router_map[destination];
    // 返回第一个大于等于目标值的元素迭代器
    auto lower = std::lower_bound(timestamp_multiset.begin(),
                                  timestamp_multiset.end(), startTime);
    // 返回第一个小于目标值的元素迭代器
    auto upper = std::upper_bound(timestamp_multiset.begin(),
                                  timestamp_multiset.end(), endTime);

    count += std::distance(lower, upper);

    return count;
  }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
#include <iostream>

int main() {
  Router *obj = new Router(3);
  std::cout << "null\n"; // Router constructor

  std::cout << std::boolalpha;
  std::cout << obj->addPacket(1, 4, 90) << "\n";  // true
  std::cout << obj->addPacket(2, 5, 90) << "\n";  // true
  std::cout << obj->addPacket(1, 4, 90) << "\n";  // false
  std::cout << obj->addPacket(3, 5, 95) << "\n";  // true
  std::cout << obj->addPacket(4, 5, 105) << "\n"; // true

  auto v = obj->forwardPacket();
  std::cout << "[" << v[0] << "," << v[1] << "," << v[2] << "]\n"; // [2,5,90]

  std::cout << obj->addPacket(5, 2, 110) << "\n";  // true
  std::cout << obj->getCount(5, 100, 110) << "\n"; // 1
}
