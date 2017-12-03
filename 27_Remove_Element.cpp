#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution_one {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0, j = nums.size();
		while (i < j)
		{
			if (nums[i] == val) {
				nums[i] = nums[j - 1];
				j--;
			}
			else {
				i++;
			}
		}
		return j;
	}
};

class Solution_two {
public:
	int removeElement(vector<int>& nums, int val) {

		sort(nums.begin(), nums.end());   //ÏÈÅÅÐò
		int j = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val) {
				nums[j] = nums[i];
				j++;
			}
		}
		return j;
	}
};


int main() {
	//Solution_two sol;
	Solution_one sol;
	vector<int> nums = { 3,2,2,3,1,3,7 };
	int val = 3;
	cout << sol.removeElement(nums, val);

	/*sort(nums.begin(), nums.end());

	vector<int>::iterator it;
	for (it = nums.begin(); it != nums.end(); it++)
	cout << *it << ' ';*/

	system("pause");
	return 0;
}