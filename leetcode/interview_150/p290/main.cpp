#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::vector;
using std::stringstream;

class Solution {
    public:
	bool wordPattern(string pattern, string s)
	{
		vector<string> s_vec;
		stringstream ss(s);
		string curr;
		while (ss >> curr) {
			s_vec.push_back(curr);
		}
		int n = pattern.size();
		if (s_vec.size() != n) {
			return false;
		}
		unordered_map<char, string> p2smap;
		unordered_map<string, char> s2pmap;
		for (int i = 0; i < n; i++) {
			if (!p2smap.count(pattern[i]) && !s2pmap.count(s_vec[i])) {
				p2smap[pattern[i]] = s_vec[i];
				s2pmap[s_vec[i]] = pattern[i];
			} else {
				if (p2smap[pattern[i]] != s_vec[i] || s2pmap[s_vec[i]] != pattern[i]) {
					return false;
				}
			}
		}
		return true;
	}
};
