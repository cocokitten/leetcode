#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {  //最长有效括号子序列长度

		int res = 0;
		int start = 0;  //start记录有效子序列的开头位置
		stack<int> m;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(') m.push(i);    //如果是左括号，则将其下标入栈
			else if (s[i] == ')') {        //如果是右括号，则分两种情况
				if (m.empty()) start = i + 1;   //1：栈为空
				else
				{ 
					m.pop();                   //2：栈非空
					res = m.empty() ? max(res, i - start + 1) : max(res, i - m.top());
				}
			}
		}
		return res;
	}
};

int main() {

	string s1 = "()()()";
	string s2 = "))())";
	string s3 = "(";

	Solution sol;
	cout << sol.longestValidParentheses(s1) << endl;
	cout << sol.longestValidParentheses(s2) << endl;
	cout << sol.longestValidParentheses(s3) << endl;

	return 0;
}