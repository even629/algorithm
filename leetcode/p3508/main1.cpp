
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <vector>

using std::map;
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
  map<int, vector<int>> router_map;
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
      vector<int> &timestamp_array = router_map[s.destination];
      timestamp_array.erase(
          find(timestamp_array.begin(), timestamp_array.end(), s.timestamp));
    }

    router_set.insert(newPacket);
    fifo.push(newPacket);

    router_map[destination].push_back(timestamp);

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

    vector<int> &timestamp_array = router_map[resPacket.destination];
    timestamp_array.erase(find(timestamp_array.begin(), timestamp_array.end(),
                               resPacket.timestamp));
    return res;
  }

  int getCount(int destination, int startTime, int endTime) {
    vector<int> &vec = router_map[destination];
    return std::distance(std::lower_bound(vec.begin(), vec.end(), startTime),
                         std::upper_bound(vec.begin(), vec.end(), endTime));
  }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
