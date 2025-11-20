#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

class Solution {
    public:
	bool canConstruct(string ransomNote, string magazine)
	{
		unordered_map<char, int> uset;
		for (auto &ch : magazine) {
			uset[ch]++;
		}
		for (auto &ch : ransomNote) {
			if (!uset.count(ch)) {
				return false;
			}
			if (uset[ch] == 0) {
				return false;
			}
			uset[ch]--;
		}
		return true;
	}
};
