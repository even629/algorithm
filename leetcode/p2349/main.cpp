#include <map>
#include <set>
class NumberContainers {
public:
  NumberContainers() {}

  void change(int index, int number) {

    if (map.count(index)) { // map中原本有该index
      int last_number = map[index];
      min_map[last_number].erase(index);
    }
    map[index] = number;
    min_map[number].insert(index);
  }

  int find(int number) {
    if (min_map.count(number) && !min_map[number].empty()) {
      return *min_map[number].begin();
    } else {
      return -1;
    }
  }

private:
  std::map<int, int> map;
  std::map<int, std::set<int>> min_map;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 *      NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
