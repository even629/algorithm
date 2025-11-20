#include <vector>
#include <unordered_map>
#include <queue>

using std::vector;
using std::queue;
using std::unordered_map;

class Solution {
    public:
	vector<int> findOrder(int numCourses,
			      vector<vector<int> > &prerequisites)
	{
		unordered_map<int, vector<int> > graph;
		unordered_map<int, int> indegree;
		// =====建图======
		int i, n = prerequisites.size();

		for (i = 0; i < numCourses; i++) {
			graph[i] = vector<int>();
			indegree[i] = 0;
		}

		int curr, prev;

		for (i = 0; i < n; i++) {
			curr = prerequisites[i][0];
			prev = prerequisites[i][1];
			graph[prev].push_back(curr);
			indegree[curr] += 1;
		}
		// 拓扑排序
		int p;
		vector<int> order;
		queue<int> que;
		for (i = 0; i < numCourses; i++) {
			if (indegree[i] == 0) {
				que.push(i);
			}
		}

		while (!que.empty()) {
			p = que.front();
			que.pop();
			order.push_back(p);
			for (auto val : graph[p]) {
				indegree[val] --;
				if(indegree[val] == 0){
				    que.push(val);
				}
			}
		}
		if(order.size() == numCourses){
		    return order;
		}
		return vector<int>();
	}
};
