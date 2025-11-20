/*
// Definition for a Node.
*/
#include <vector>

using std::vector;

class Node {
    public:
	int val;
	vector<Node *> neighbors;
	Node()
	{
		val = 0;
		neighbors = vector<Node *>();
	}
	Node(int _val)
	{
		val = _val;
		neighbors = vector<Node *>();
	}
	Node(int _val, vector<Node *> _neighbors)
	{
		val = _val;
		neighbors = _neighbors;
	}
};
#include <unordered_map>
#include <queue>
using std::queue;
using std::unordered_map;

class Solution {
    private:
	unordered_map<Node *, Node *> visited;

    public:
	// 给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
	Node *cloneGraph(Node *node)
	{
		if (node == nullptr) {
			return nullptr;
		}

		unordered_map<Node *, Node *> visited;
		queue<Node *> q;
		Node *cur, *cloneNode;

		cloneNode = new Node(node->val);
		visited[node] = cloneNode;
		q.push(node);

		while (!q.empty()) {
			cur = q.front();
			q.pop();
			for (Node *neighbor : cur->neighbors) {
				if (visited.count(neighbor) == 0) { // 未访问过
				   // 创建该节点对应的clone节点
					visited[neighbor] = new Node(neighbor->val);
					q.push(neighbor);
				}
				// 将刚创建的clone节点或者已经访问过的节点加入队首节点对应的clone节点的neighbor
				visited[cur]->neighbors.push_back(visited[neighbor]);
			}
		}

		return cloneNode;
	}
};
