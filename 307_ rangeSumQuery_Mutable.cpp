/*Given an integer array nums, find the sum of the elements between indices i and j(i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9 
update(1, 2)
sumRange(0, 2) -> 8
Note :
	The array is only modifiable by the update function.
	You may assume the number of calls to update and sumRange function is distributed evenly.
*/

//使用线段树
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NumArray {                          
public:
	NumArray(vector<int> nums) {
		numsArr = nums;
		length = nums.size();
		if (length > 0) {
			tree = vector<int>( length * 2, 0 );
			buildTree(nums);
		}
	}
	void buildTree(vector<int> nums) {
		for (int i = length, j = 0; i < 2 * length; i++, j++)
			tree[i] = nums[j];
		for (int i = length - 1; i >0; --i)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	void update(int i, int val) {
		i += length;
		tree[i] = val;
		while (i > 0) {
			int left = i;
			int right = i;
			if (i % 2 == 0) {
				right = i + 1;
			}
			else
			{
				left = i - 1;
			}
			tree[i / 2] = tree[left] + tree[right];
			i = i / 2;
		}		
	}

	int sumRange(int i, int j) {
		i = i + length;
		j = j + length;
		int sum = 0;
		while (i<=j)
		{
			if (( i % 2 )==1)
			{	
				sum = sum + tree[i];
				i++;
			}
			if ((j % 2) == 0) {
			
				sum = sum + tree[j];
				j--;
			}
			i = i / 2;
			j = j / 2;
		}
		return sum;
	}
private:
	vector<int> numsArr;
	vector<int> tree; //声明一个新的数组来表示树状数组
	int length;

};

int main() {

	vector<int> nums = { 9,-8,2,5 };
	//NumArray obj(nums);

	NumArray *obj = new NumArray(nums);

	obj->update(0, 3);
	cout << obj->sumRange(1, 1) << endl;
	obj->update(1, -3);
	cout << obj->sumRange(0, 3) << endl;

	system("pause");
	return 0;

}

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* obj.update(i,val);
* int param_2 = obj.sumRange(i,j);
*/






