

/********************************************************************************************
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

1 The length of both num1 and num2 is < 5100.
2 Both num1 and num2 contains only digits 0-9.
3 Both num1 and num2 does not contain any leading zero.
4 You must not use any built-in BigInteger library or convert the inputs to integer directly.

*********************************************************************************************/


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//============== first solution (wrong answer) =====================
//Because,the largest number of int can represent is 2147483647
//Note,The length of both num1 and num2 is <5100;
/*
class Solution {
public:
	int string2int(string num) {
		int inum = 0;
		int base = 1;
		for (int i = num.size() - 1; i >= 0; i--)
		{
			inum += (num[i] - '0')*base;
			base = base * 10;
		}
		return inum;
	}
	string addStrings(string num1, string num2) {
		int inum1 = string2int(num1);
		int inum2 = string2int(num2);
		return to_string(inum1 + inum2);
	}
};*/
//===============Soultion from other people=========================
/*class Solution {
public:
string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    while(i>=0 || j>=0 || carry){
        long sum = 0;
        if(i >= 0){sum += (num1[i] - '0');i--;}
        if(j >= 0){sum += (num2[j] - '0');j--;}
        sum += carry; 
        carry = sum / 10;
        sum = sum % 10;
        res =  res + to_string(sum);
    }
    reverse(res.begin(), res.end());
    return res;
}
};*/
//===============================Accepted=========================
// so complicated!
class Solution {
public:
	string addStrings(string num1, string num2) {
		int i = num1.size()-1;
		int j = num2.size()-1;
		int carry = 0;
		int temp = 0;
		string result;

		while ( i>=0&&j>=0 )
		{
			temp = (num1[i] - '0') + (num2[j] - '0') + carry;
			if (temp >= 10) {
				carry = 1;
				temp = temp - 10;
			}
			else
			{
				carry = 0;
			}
			result += to_string(temp);
			j--;
			i--;
		}
		if (i < 0 && j < 0 && carry > 0) {
			result += '1';
			carry = 0;
		}
		if (i >= 0) {
			for (int index = i; index >=0; index--)
			{	
				temp = (num1[index] - '0') + carry;

				if (temp >= 10) //num1="123" ,num2="1900
				{
					carry = 1;
					temp = temp - 10;
				}else
				{
					carry = 0;
				}
				result += to_string(temp);
			}
		
		}
		if (j >=0) {
			for (int index = j; index >= 0; index--)
			{
				temp = (num2[index] - '0') + carry;

				if (temp >= 10) //num1="123" ,num2="1900
				{
					carry = 1;
					temp = temp - 10;
				}
				else
				{
					carry = 0;
				}
				result += to_string(temp);
			}
		}
		if(carry>0) result += '1';
		reverse(result.begin(), result.end());
		return result;
	}
};

int main() {
	string snum1 = "1";
	string snum2 = "9";
	Solution sol;
	cout<<sol.addStrings(snum1, snum2)<<endl;
	system("pause");
}