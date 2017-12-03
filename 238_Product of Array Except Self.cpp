//Given an array of n integers where n > 1, nums, return an array output such that output[i] 
//is equal to the product of all the elements of nums except nums[i].

//Solve it without division and in O(n).
//For example, given[1, 2, 3, 4], return[24, 12, 8, 6].

//Follow up :
//Could you solve it with constant space complexity ? 
//(Note : The output array does not count as extra space for the purpose of space complexity analysis.)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();

		int p = 1;
		vector<int> res;
		for (int i = 0; i < n; i++)
		{
			res.push_back(p);
			p = p*nums[i];
		}

		int q = 1;
		for (int j = n - 1; j >= 0; j--)
		{
			res[j] = res[j] * q;
			q = q*nums[j];
		}
		return res;
	}
};
int main() {
	vector<int> nums = { 1,2,3,4 };
	Solution sol;
	vector<int> res = sol.productExceptSelf(nums);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	system("pause");
	return 0;
}

