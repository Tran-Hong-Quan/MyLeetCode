#include <iostream>
#include <vector>
#include <algorithm> 
#include <unordered_map>
#include <string> 

using namespace std;

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& score) {
		auto sortScore = score;
		unordered_map<int, string> scoreMap;

		vector<string> res;
		sort(sortScore.begin(), sortScore.end());
		for (int i = sortScore.size() - 1, order = 1; i >= 0; i--, order++) {
			int n = sortScore[i];
			string s = "";

			if (order == 1) {
				s = "Gold Medal";
			}
			else if (order == 2)
			{
				s = "Silver Medal";
			}
			else if (order == 3)
			{
				s = "Bronze Medal";
			}
			else
			{
				s = to_string(order);
			}

			scoreMap[n] = s;
		}

		for (auto s : score) {
			res.push_back(scoreMap[s]);
		}

		return res;

	}
};

int main()
{
	Solution s;
	vector<int> score = { 5,4,3,2,1 };
	auto r = s.findRelativeRanks(score);

	for (auto ri : r) {
		cout << ri << endl;
	}

	return 0;
}
