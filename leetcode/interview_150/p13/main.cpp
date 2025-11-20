#include <string>
#include <unordered_map>
#include <queue>

using std::unordered_map;
using std::string;
using std::queue;

class Solution {
    private:
	unordered_map<string, int> roman_alpha_to_int;

    public:
	Solution()
	{
		roman_alpha_to_int = { { "I", 1 },   { "V", 5 },   { "X", 10 },	 { "L", 50 },	{ "IV", 4 },
				       { "IX", 9 },  { "XL", 40 }, { "XC", 90 }, { "CD", 400 }, { "CM", 900 },
				       { "C", 100 }, { "D", 500 }, { "M", 1000 } };
	}
	int romanToInt(string s)
	{
		queue<char> ch_que;
		int res = 0;
		char front, next;

		for (char ch : s) {
			ch_que.push(ch);
		}

		while (!ch_que.empty()) {
			front = ch_que.front();
			ch_que.pop();
			string tmp;
			tmp.push_back(front);
			if (!ch_que.empty()) {
				next = ch_que.front();
				tmp.push_back(next);
				if (!roman_alpha_to_int.count(tmp)) { //
					tmp.pop_back();
				} else {
					ch_que.pop();
				}
			}
			res += roman_alpha_to_int[tmp];
		}
		return res;
	}
};
int main()
{
	Solution S;
	string s = "III";
	S.romanToInt(s);
}
