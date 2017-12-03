#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//������ظ��ַ����Ӵ�����
//ʹ�û������ڵķ�ʽ�����������������Ӵ������ж������Ӵ��Ƿ����ظ��ַ��ᳬʱ����
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

