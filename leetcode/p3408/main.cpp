#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

template <typename T, typename Compare = std::less<T>> class Heap {
public:
  Heap() {}
  void push(T val) {
    vec.push_back(val);
    shiftUp(vec.size() - 1);
  }
  void pop() {
    if (vec.empty()) {
      return;
    }
    swap(vec[0], vec.back());
    vec.pop_back();
    shiftDown(0);
  }
  T top() { return vec.front(); }
  bool empty() { return vec.empty(); }

  void shiftUp(size_t index) {

    while (index != 0) {
      if (!cmp(vec[parent(index)], vec[index])) {
        break;
      }
      // vec[index]返回的是元素的引用而不是拷贝
      swap(vec[parent(index)], vec[index]);
      index = parent(index);
    }
  }
  void shiftDown(size_t index) {
    int n = vec.size();
    while (true) {
      size_t left = left_child(index);
      size_t right = right_child(index);
      size_t largest = index;

      if (left < n && cmp(vec[largest], vec[left]))
        largest = left;
      if (right < n && cmp(vec[largest], vec[right]))
        largest = right;
      if (largest == index)
        break;
      swap(vec[index], vec[largest]);
      index = largest;
    }
  }

  inline size_t left_child(size_t index) { return 2 * index + 1; }
  inline size_t right_child(size_t index) { return 2 * index + 2; }
  inline size_t parent(size_t index) { return (index - 1) / 2; }

  vector<T> vec;
  Compare cmp;
};

class TaskManager {
public:
  TaskManager(vector<vector<int>> &tasks) {
    for (vector<int> task : tasks) {
      max_heap.push(task);
    }
  }

  void add(int userId, int taskId, int priority) {
    vector<int> vec;
    vec.push_back(userId);
    vec.push_back(taskId);
    vec.push_back(priority);
    // 拷贝
    max_heap.push(vec);
  }

  void edit(int taskId, int newPriority) {
    int index = -1;
    int oldPriority;
    for (int i = 0; i < max_heap.vec.size(); i++) {
      if (max_heap.vec[i][1] == taskId) {
        index = i;
        oldPriority = max_heap.vec[i][2];
        max_heap.vec[i][2] = newPriority;
        break;
      }
    }
    if (index == -1) {
      return;
    }

    if (oldPriority < newPriority) {
      max_heap.shiftUp(index);
    } else {
      max_heap.shiftDown(index);
    }
  }

  void rmv(int taskId) {
    int index = -1;
    int oldPriority;
    for (int i = 0; i < max_heap.vec.size(); i++) {
      if (max_heap.vec[i][1] == taskId) {
        index = i;
        oldPriority = max_heap.vec[i][2];
        break;
      }
    }
    if (index == -1) {
      return;
    }

    if (index == max_heap.vec.size() - 1) {
      max_heap.vec.pop_back();
      return;
    }

    swap(max_heap.vec.back(), max_heap.vec[index]);
    max_heap.vec.pop_back();

    if (oldPriority > max_heap.vec[index][2]) {
      max_heap.shiftDown(index);
    } else {
      max_heap.shiftUp(index);
    }
  }

  int execTop() {
    int userId;
    if (max_heap.vec.empty()) {
      return -1;
    }
    userId = max_heap.top()[0];
    max_heap.pop();
    return userId;
  }

private:
  struct Compare {
    bool operator()(const vector<int> &a, const vector<int> &b) const {
      if (a[2] != b[2])
        return a[2] < b[2]; // priority 小的优先级低
      else
        return a[1] < b[1];
    }
  };
  Heap<vector<int>, Compare> max_heap;
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
#include <iostream>
int main() {
  // Step 1: 初始化任务
  vector<vector<int>> tasks = {{10, 26, 25}}; // 用户 10，任务 26，优先级 25
  TaskManager taskManager(tasks);

  // Step 2: 删除任务 26
  taskManager.rmv(26);

  int topUser = taskManager.execTop();
  std::cout << "execTop() -> " << topUser << std::endl;

  return 0;
}
