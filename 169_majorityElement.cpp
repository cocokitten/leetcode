#include<iostream>
#include<map>
#include<vector>
using namespace std;


class Solution {
public:
	int majorityElement(vector<int>& nums) {

		/*map<int, int> aMap;
		auto map_it = aMap.begin();


		for (int i = 0; i < nums.size(); i++)
		{
		if (aMap.find(nums[i]) != aMap.end()) {
		map_it = aMap.find(nums[i]);
		map_it->second++;
		if ((map_it->second) > (nums.size() / 2)) return map_it->first;
		}
		else {
		aMap.insert({ nums[i],1 });
		}
		}*/
		map<int, int> counts;
		int n = nums.size();
		for (int i = 0; i < n; i++)
			if (++counts[nums[i]] > n / 2)
				return nums[i];
	}
};
int main() {

	vector<int> a = { 1,2,3,4,4,4,4 };
	Solution sol;
	cout << sol.majorityElement(a) << endl;


	system("pause");
	return 0;

}