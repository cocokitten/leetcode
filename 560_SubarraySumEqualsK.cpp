#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int sz = nums.size(), cnt = 0;
		vector<int> sum(sz + 1, 0);
		for (int i = 0; i<sz; ++i) sum[i + 1] = sum[i] + nums[i];
		for (int i = 0; i<sz; ++i) {
			for (int j = i + 1; j <= sz; ++j) {
				if (sum[j] - sum[i] == k) ++cnt;
			}
		}
		return cnt;
	}
};

int main() {

	Solution sol;
	vector<int> nums = { 1,1,1,1 };
	int k = 2;
	cout << sol.subarraySum(nums, k) << endl;

	system("pause");
	return 0;

}
