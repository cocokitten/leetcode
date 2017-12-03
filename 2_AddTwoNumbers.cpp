/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode dummy(-1);  //头指针
        ListNode *pa=l1;
        ListNode *pb=l2;
        ListNode *curr = &dummy;
        int carry = 0; //存储进位值；
        int a_val=0,b_val=0;
        
        for( ;pa !=nullptr||pb !=nullptr; pa=pa==nullptr?nullptr:pa->next,pb=pb==nullptr?nullptr:pb->next,curr =curr->next)
        {
            a_val= pa==nullptr?0:pa->val;
            b_val= pb==nullptr?0:pb->val;
            int value = (a_val+b_val+carry)%10;
            carry = (a_val+b_val+carry)/10;
            curr->next = new ListNode(value);
        }
        if(carry>0){
            curr->next = new ListNode(carry);
        }
        return dummy.next;    //?

    }
};