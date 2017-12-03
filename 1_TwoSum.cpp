//Accepted

#include<iostream>
using namespace std;

#include<vector>
#include<unordered_map>

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> res;
		for (int i = 0; i < numbers.size(); ++i) {
			for (int j = i + 1; j < numbers.size(); ++j) {
				if (numbers[j] + numbers[i] == target) {
					res.push_back(i + 1);
					res.push_back(j + 1);
				}
			}
		}
		return res;

	}

	vector<int> twoSum2(vector<int> &numbers, int target) {
		vector<int> result(2, 0);
		unordered_map<int, int> valToIndex;

		for (int i = 0; i < numbers.size(); i++) {
			int v = target - numbers[i];
			if (valToIndex.find(v) != valToIndex.end()) {
				result[0] = valToIndex[v] + 1;
				result[1] = i + 1;
				break;
			}
			valToIndex[numbers[i]] = i;
		}

		return result;
	}
};
int main() {
	int n[] = { 2,7,11,15 };
	int target = 9;
	vector<int> nummbers(n, n + 4);
	Solution one;
	vector<int> result;
	result = one.twoSum(nummbers, target);
	cout << result[0] << " " << result[1] << endl;


	system("pause");
	return 0;

}





