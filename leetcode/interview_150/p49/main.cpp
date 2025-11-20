#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using std::unordered_map;
using std::string;
using std::vector;

class Solution {
    public:
	vector<vector<string> > groupAnagrams(vector<string> &strs)
	{
		vector<vector<string> > res;
		if (strs.empty()) {
			res.push_back(vector<string>());
			return res;
		}
		unordered_map<string, vector<string> > umap;
		for (string &s : strs) {
			string original(s);
			std::sort(s.begin(), s.end());
			if (!umap.count(s)) {
				umap[s] = vector<string>(1, original);
			} else {
				umap[s].push_back(original);
			}
		}
		for (auto [_, vec] : umap) {
			res.push_back(vec);
		}
		return res;
	}
};
