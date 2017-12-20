/*Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4*/



/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
		ListNode *prehead = new ListNode(-1);
		ListNode *prev = prehead;

		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val) {
				prev->next = l1;
				l1 = l1->next;
			}
			else
			{
				prev->next = l2;
				l2 = l2->next;
			}
			prev = prev->next;
		}
		if (l1 != NULL)prev->next = l1;
		else prev->next = l2;

		return prehead->next;
	}
};



