#include<iostream>
#include<vector>
#include<map>
using namespace std;


//Given an array of integers, every element appears twice except for one. Find that single one.

class Solution {
public:
	int singleNumber(vector<int>& nums) {

		map<int,int> nmap;

		for (int i = 0; i < nums.size(); i++) {
			if (nmap.find(nums[i]) == nmap.end()) {
				nmap[nums[i]] = 1;
			}
			else nmap[nums[i]]++;
		}

		map<int, int>::iterator it = nmap.begin();

		while (it!=nmap.end())
		{
			if (it->second == 1)
				return it->first;
			else
				it++;
		}
	}
};


int main() {


	vector<int>nums = { 2,3,1,1,4,3,2,6,1,4 };
	map<int, int> nmap;

	Solution sol;
	cout<<sol.singleNumber(nums)<<endl;
	return 0;

}
