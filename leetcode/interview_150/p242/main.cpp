#include <string>
#include <unordered_map>
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
			}
			smap[ch]--;
			if (smap[ch] < 0) {
				return false;
			}
		}
		return true;
	}
};
