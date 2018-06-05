#include <iostream>
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		int val1, val2, sum = 0;
		ListNode result(0);
		ListNode *currentNode = &result;
		ListNode *i, *j;
		for (i = l1, j = l2; i != NULL && j != NULL; i = i->next,j = j->next) {
			val1 = i->val;
            val2 = j->val;
			sum = val1 + val2 + carry;
			carry = 0;
			if (sum >= 10) {
				sum -= 10;
				carry++;
			}
			ListNode *newNode = new ListNode(sum);
			currentNode->next = newNode;
			currentNode = currentNode->next;
		}
        if(i != NULL || j !=NULL){
            if(j!=NULL){
            i = j;
        }
        for (i; i != NULL; i=i->next){
            val1 = i->val;
            sum = val1 + carry;
            carry = 0;
            if(sum >= 10){
                sum -= 10;
                carry ++;
            }
            ListNode *newNode = new ListNode(sum);
			currentNode->next = newNode;
			currentNode = currentNode->next;
        }
        }
        
		if (carry != 0) {
			ListNode *newNode = new ListNode(carry);
			currentNode->next = newNode;
            
		}
		return result.next;
	}
};