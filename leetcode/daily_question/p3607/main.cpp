#include <vector>
#include <algorithm>

using std::vector;

class DSU {
    public:
	vector<int> parent; // 每个节点的父节点
	vector<int> rank; // （可选）用于按秩合并或记录集合大小

	DSU(int n)
	{
		parent.resize(n);
		rank.resize(n, 0);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int x)
	{
		// 路径压缩，使查找复杂度接近 O(1)
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void join(int x, int y)
	{
		// 按秩合并
		int rootX = find(x);
		int rootY = find(y);
		if (rootX == rootY) {
			return;
		}

		if (rank[rootX] < rank[rootY]) { //两个集合的秩中最大的为rootX
			std::swap(rootX, rootY);
		}

		parent[rootY] = rootX;

		if (rank[rootX] == rank[rootY]) { //如果两个集合秩相等，合并后的集合的秩+1
			rank[rootX]++;
		}
	}

	bool connected(int x, int y)
	{
		return find(x) == find(y);
	}
};
