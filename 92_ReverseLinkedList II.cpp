/*Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.*/

#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {   //Accepted! 存在边界问题，解决方案有点麻烦

		if (head == NULL || head->next == NULL) return head;
		if ( m == n ) return head;  
		
		int num1 = 1;
		ListNode * p1 = head;
		
		ListNode * front = NULL; //待修改序列的前一个结点
		ListNode * end = NULL;  //待修改序列结尾的后一个结点
		ListNode * b_front = NULL; //待修改序列的第一个结点
		ListNode * b_end = NULL;  //待修改序列的最后一个结点

		if (m == 1)
		{
			front = p1;
			b_front = p1;
		}
		else
		{
			while (m > num1)
			{
				front = p1;  //指向待修改序列的前一个结点
				p1 = p1->next;
				b_front = p1; //指向待修改序列的第一个结点 
				num1++;
			}

		}
				
		int num2 = m;
		ListNode *p2 = p1->next;
		ListNode *p3 = NULL;
		
		while (n > num2)
		{
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			num2++;
		}

		end = p3;
		b_end = p1;
		
		if (m == 1)
		{ 
			front->next = end;
			return b_end;
		}
		else { 
			front->next = b_end; 
			b_front->next = end;
			return head;
		}		
	}
};