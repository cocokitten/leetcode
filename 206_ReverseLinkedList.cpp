/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


/*Reverse a singly linked list.
Hint:
A linked list can be reversed either iteratively or recursively.Could you implement both ?*/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//iteratively

class Solution {
public:
	ListNode* reverseList(ListNode* head) {   //Accepted 

		if (head == NULL || head->next == NULL) return head;

		ListNode *p1 = head;
		ListNode *p2 = p1->next;
		ListNode *p3 = NULL;

		while (p2) {

			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}

		head->next = NULL;
		head = p1;
		return head;
	}

	ListNode* reverseList2(ListNode* head) { //Accepted
		ListNode *pre = NULL;
		ListNode *cur = head;

		while (cur) {
			ListNode *nextTemp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nextTemp;
		}
		return pre;
	}
};
