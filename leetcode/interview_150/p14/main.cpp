#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

struct Node {
	unordered_map<char, Node *> children;
	bool isEnd = false;
};

class Solution {
    public:
	string longestCommonPrefix(vector<string> &strs)
	{
		if (strs.empty())
			return "";
		Node *root = new Node();

		//插入所有字符串到 Trie
		for (const string &s : strs) {
			Node *p = root;
			for (char c : s) {
				if (!p->children.count(c)) {
					p->children[c] = new Node();
				}
				p = p->children[c];
			}
			p->isEnd = true;
		}

		//从 root 出发，沿着“唯一分支”走下去
		string prefix;
		Node *p = root;
		while (p && p->children.size() == 1 && !p->isEnd) {
			char next = p->children.begin()->first;
			prefix.push_back(next);
			p = p->children[next];
		}

		return prefix;
	}
};
