
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) {
		numsArr = nums;

	}

	int sumRange(int i, int j) {
		int result = 0;
		for (int index = i; index <= j; index++)
		{
			result += numsArr[index];
		}
		return result;
	}

private:
	vector<int> numsArr;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/

int main() {

	vector<int> nums = { -2,0,3,-5,2,1 };
	//NumArray obj(nums);
	NumArray *obj = new NumArray(nums);

	cout << obj->sumRange(0, 2);


	system("pause");
	return 0;

}