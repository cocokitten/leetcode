#include<iostream>
#include<string>
#include<algorithm>

#include<map>
using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) {
		int n = s.size();
		if (k > n) return 0;

		map<char, int> counts;
		for (int i = 0; i < n; i++)
		{
			counts[s[i]]++;
		}

		int  begin = 0, end = n - 1;

		/*while (begin < n) {
		if (counts[s[begin]] < k) begin++;
		}
		while (end >= 0) {
		if (counts[s[end]] < k) end--;
		}*/
		while (begin < n && counts[s[begin]] < k) begin++;
		while (end >= 0 && counts[s[end]] < k) end--;


		int i;
		for (i = begin; i <= end; i++)
		{
			if (counts[s[i]] < k)
				return max(longestSubstring(s.substr(begin, i - begin + 1), k), longestSubstring(s.substr(i + 1, end - i), k));
		}

		if (i == (end + 1)) return(end - begin + 1);
		else return 0;
	}
};
int main() {

	string s = "ababbc";
	Solution sol;

	cout << sol.longestSubstring(s, 2) << endl;

	system("pause");
	return 0;
}
