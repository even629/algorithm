#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using std::pair;
using std::priority_queue;
using std::unordered_map;
using std::vector;

class TaskManager {
private:
  unordered_map<int, pair<int, int>> map;
  priority_queue<pair<int, int>> heap;

public:
  TaskManager(vector<vector<int>> &tasks) {
    int userId, taskId, priority;
    for (vector<int> &task : tasks) {
      userId = task[0];
      taskId = task[1];
      priority = task[2];
      map[taskId] = {priority, userId};
      heap.emplace(priority, taskId);
    }
  }

  void add(int userId, int taskId, int priority) {
    heap.emplace(priority, taskId);
    map[taskId] = {priority, userId};
  }

  void edit(int taskId, int newPriority) {
    if (map.find(taskId) != map.end()) {
      map[taskId].first = newPriority;
      heap.emplace(newPriority, taskId);
    }
  }

  void rmv(int taskId) { map.erase(taskId); }

  int execTop() {
    int top_userId, top_taskId, top_priority;

    while (!heap.empty()) {
      top_priority = heap.top().first;
      top_taskId = heap.top().second;

      if (map.find(top_taskId) != map.end() &&
          map[top_taskId].first == top_priority) { // 存在,且priority相同
        top_userId = map[top_taskId].second;
        map.erase(top_taskId);
        heap.pop();
        return top_userId;
      } else { // 应该删除的元素
        heap.pop();
      }
    }
    return -1;
  }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
