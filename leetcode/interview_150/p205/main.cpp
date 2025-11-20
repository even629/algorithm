#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
    public:
	bool isIsomorphic(string s, string t)
	{
		if (s.size() != t.size()) {
			return false;
		}
		unordered_map<char, char> s2tmap;
		unordered_map<char, char> t2smap;
		int i, n = s.size();
		for (i = 0; i < n; i++) {
			if (!s2tmap.count(s[i]) && !t2smap.count(t[i])) {
				s2tmap[s[i]] = t[i];
				t2smap[t[i]] = s[i];
			} else {
				if (s2tmap[s[i]] != t[i] || t2smap[t[i]] != s[i]) {
					return false;
				}
			}
		}

		return true;
	}
};
