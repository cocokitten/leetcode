//Given two binary strings, return their sum(also a binary string).

//For example,
//a = "11"
//b = "1"
//Return "100".

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int a_len = a.size() - 1;
		int b_len = b.size() - 1;
		int p = 0;
		int c = 0;
		string s;
		while (a_len >= 0 && b_len >= 0) {
			c = ((a[a_len] - '0') + (b[b_len] - '0') + p) % 2;     //当前位的值
			p = ((a[a_len] - '0') + (b[b_len] - '0') + p) / 2;     //进位
			s.insert(0, to_string(c));
			a_len--;
			b_len--;
		}

		if (a_len >= 0) {
			while (a_len >= 0)
			{
				c = ((a[a_len] - '0') + p) % 2;
				p = ((a[a_len] - '0') + p) / 2;
				s.insert(0, to_string(c));
				a_len--;
			}
		}
		if (b_len >= 0) {
			while (b_len >= 0)
			{
				c = ((b[b_len] - '0') + p) % 2;
				p = ((b[b_len] - '0') + p) / 2;
				s.insert(0, to_string(c));
				b_len--;
			}
		}
		if (p > 0) s.insert(0, to_string(p));
		return s;
	}
};

int main() {


	string a = "11";
	string b = "1";

	Solution sol;
	cout << sol.addBinary(a, b);

	system("pause");
	return 0;

}