#include <vector>
using std::vector;

class Solution {
    public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		int i = 0, j = numbers.size() - 1, curr;
		while (i < j) {
			curr = numbers[i] + numbers[j];
			if (curr < target) {
				i++;
			} else if (curr > target) {
				j--;
			} else {
				break;
			}
		}
		return { i + 1, j + 1 };
	}
};
