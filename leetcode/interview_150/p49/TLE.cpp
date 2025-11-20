#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
    public:
	bool isAnagram(string s, string t)
	{
		if (s.size() != t.size()) {
			return false;
		}
		unordered_map<char, int> smap;
		for (char &ch : s) {
			smap[ch]++;
		}
		for (char &ch : t) {
			if (!smap.count(ch)) {
				return false;
			} else {
				smap[ch]--;
				if (smap[ch] < 0) {
					return false;
				}
			}
		}
		return true;
	}
	vector<vector<string> > groupAnagrams(vector<string> &strs)
	{
		vector<vector<string> > res;
		if (strs.empty()) {
			res.push_back(vector<string>());
			return res;
		}
		if (strs.size() == 1) {
			res.push_back(vector<string>(1, strs[0]));
			return res;
		}
		// 先按size分
		vector<vector<string> > diff_size_strs;
		unordered_map<int, int> size2index;

		for (string &s : strs) {
			if (!size2index.count(s.size())) {
				vector<string> vec;
				vec.push_back(s);
				diff_size_strs.push_back(vec);
				size2index[s.size()] = diff_size_strs.size() - 1;
			} else {
				diff_size_strs[size2index[s.size()]].push_back(s);
			}
		}

		for (vector<string> &vec : diff_size_strs) {
			int n = vec.size();
			int i, j = n - 1;

			while (j >= 0) {
				vector<string> curr;
				string base = vec[j];
				curr.push_back(vec[j]);
				j--;
				for (i = 0; i <= j; i++) {
					if (isAnagram(base, vec[i])) {
						curr.push_back(vec[i]);
						swap(vec[i], vec[j]);
						j--;
						i--; //重新检查当前位置
					}
				}
				res.push_back(curr);
			}
		}
		return res;
	}
};

int main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution S;
	S.groupAnagrams(strs);
}
