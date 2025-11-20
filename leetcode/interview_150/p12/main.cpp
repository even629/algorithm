#include <string>
#include <vector>
#include <utility>

using std::string;
using std::pair;
using std::vector;

class Solution {
    private:
	vector<pair<int, string> > roman;

    public:
	Solution()
	{
		roman = { { 1000, "M" }, { 900, "CM" }, { 500, "D" }, { 400, "CD" }, { 100, "C" },
			  { 90, "XC" },	 { 50, "L" },	{ 40, "XL" }, { 10, "X" },   { 9, "IX" },
			  { 5, "V" },	 { 4, "IV" },	{ 1, "I" } };
	}

	string intToRoman(int num)
	{
		string res;
		int i, j, n = roman.size();
		int times;
		for (i = 0; i < n; i++) {
			if (num < roman[i].first) {
				continue;
			}
			times = num / roman[i].first;
			num = num % roman[i].first;
			for (j = 0; j < times; j++) {
				res += roman[i].second;
			}
		}
		return res;
	}
};
