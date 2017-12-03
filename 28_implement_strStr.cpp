//Accepted
#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {
		int i = 0;
		int j = 0;
		int h_len = haystack.size();
		int n_len = needle.size();

		while (i<h_len && j<n_len)
		{
			if (haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}
		}
		if (j == n_len) return i - j;
		else return -1;
	}
};

int main() {

	Solution sol;

	cout << sol.strStr("mississippi", "issip");
	cout << sol.strStr("hello", "ll");

	system("pause");
	return 0;
}
