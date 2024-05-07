#include "_128.h"

int _128::longestConsecutive(std::vector<int>& nums) {
	std::unordered_map<int, int> map;

	if (nums.size() == 0) return false;

	for (auto n : nums) {
		if (map.count(n) == 0) {
			map[n] = 1;
		}
	}
	int maxVal = 1;
	for (auto n : map) {
		int k = n.first - 1;
		while (map.count(k) != 0)
		{
			if (map[k] != 1) {
				n.second = map[k] + n.first - k;
				break;
			}
			n.second++;
			map[k] = map[k+1] - 1;
			k--;
		}
		maxVal = std::max(maxVal, n.second);
	}
	return maxVal;
}