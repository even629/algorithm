#include <algorithm>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class RandomizedSet {
private:
  unordered_map<int, int> umap;
  vector<int> vec;

public:
  RandomizedSet() {}

  bool insert(int val) {

    if (umap.count(val) == 0) {
      vec.push_back(val);
      umap[val] = vec.size() - 1;
      return true;
    } else {
      return false;
    }
  }

  bool remove(int val) {
    if (umap.count(val) == 0) {
      return false;
    } else {
      umap[vec.back()] = umap[val];
      std::swap(vec[umap[val]], vec.back());

      vec.pop_back();
      umap.erase(val);

      return true;
    }
  }

  int getRandom() { return vec[std::rand() % vec.size()]; }
};
