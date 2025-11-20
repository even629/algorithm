#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    public:
	string convert(string s, int numRows)
	{
		if (numRows == 1) {
			return s;
		}
		int i, j, n = s.size();
		int offset = numRows + numRows - 2;
		int left = n % (offset);
		int complete = n - left;
		int base;

		string res;
		vector<vector<char> > grid = vector<vector<char> >(numRows, vector<char>());

		for (i = 0; i < complete; i += offset) {
			for (j = 0; j < numRows; j++) {
				grid[j].push_back(s[i + j]);
			}
			base = i + j;
			for (j = 0; j < numRows - 2; j++) {
				grid[numRows - 1 - 1 - j].push_back(s[base + j]);
			}
		}

		for (j = 0; j < left && j < numRows; j++) {
			grid[j].push_back(s[j + complete]);
		}

		if (left > numRows) {
			base = j + complete;
			for (j = 0; j < left - numRows; j++) {
				grid[numRows - 1 - 1 - j].push_back(s[base + j]);
			}
		}

		for (i = 0; i < numRows; i++) {
			for (char ch : grid[i]) {
				res += ch;
			}
		}
		return res;
	}
};
int main()
{
	Solution S;
	int numRows = 3;
	string s = "PAYPALISHIRING";
	S.convert(s, numRows);
}
