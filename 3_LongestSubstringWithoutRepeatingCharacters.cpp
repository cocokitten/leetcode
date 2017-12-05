#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//求最长无重复字符的子串长度
//使用滑动窗口的方式（若暴力遍历所有子串，并判断所有子串是否有重复字符会超时）。
class Solution
{
public:
	int lengthOfLongestSubstring(string s) {
		int length = s.size();
		set<char> max_substring;
		int max_length = 0;
		int i = 0, j = 0;
		while (i < length &&j < length) {
			if (!max_substring.count(s[j])) {
				max_substring.insert(s[j]);
				j++;
				max_length = max(max_length, j - i);
			}
			else {
				max_substring.erase(s[i]);
				i++;
			}
		}
		return max_length;
	}
};

int main() {

	string s = "abasss";

	Solution sol;
	cout << sol.lengthOfLongestSubstring(s) << endl;
	system("pause");
	return 0;
}

