#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//开头结尾的空格去除，全是空格不输出,并且，单词之间保留一个空格
/*Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update(2015 - 02 - 12) :
	For C programmers : Try to solve it in - place in O(1) space.*/


class Solution {
public:	         
	void reverseWords(string &s) {    //Accepted
		reverse(s.begin(), s.end());
		int storeIndex = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ')
			{
				if (storeIndex != 0) s[storeIndex++] = ' ';
				int j = i;
				while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
				reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
				i = j;
			}
		}
		s.erase(s.begin() + storeIndex, s.end());
	}
};

int main() {

	string s = "   b   a a";
	Solution sol;
	sol.reverseWords(s);

	cout << s << endl;
	system("pause");
	return 0;
}