// Solved a problem on detecting and finding the start of a loop in leetcode.
#include<iostream>
using namespace std;
 struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if(head == NULL){
            return NULL;
        }
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                slow = head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};