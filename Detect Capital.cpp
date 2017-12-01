
/*********************************************************************************************
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

	1 All letters in this word are capitals, like "USA".
	2 All letters in this word are not capitals, like "leetcode".
	3 Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:
	Input: "USA"
	Output: True
Example 2:
	Input: "FlaG"
	Output: False

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

*********************************************************************************************/

class Solution {
public:
	bool detectCapitalUse(string word) {
		int uppercaseNum = 0;
		int lowercaseNum = 0;
		int length = word.size() - 1;
		if (word.size() == 1) return true;
		
		if (word[0] >= 65 && word[0] <= 90) {

			for (int i = 1; i < word.size(); i++)
			{
				if (word[i] >= 65 && word[i] <= 90)  //大写
				{
					uppercaseNum++;
				}
				if (word[i] >= 97 && word[i] <= 122) //小写
				{
					lowercaseNum++;
				}
			}

			if (uppercaseNum == length || lowercaseNum == length) return true;
			else return false;

		}
		if (word[0] >= 97 && word[0] <= 122) {

			for (int i = 1; i < word.size(); i++)
			{
				if (word[i] >= 65 && word[i] <= 90) 
				{
					return false;
				}
			}
			return true;
		}
	}
};