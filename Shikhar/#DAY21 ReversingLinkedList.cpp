// In this code I have solved a leetcode question to reverse a LL when we are given its head node.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* ahead = temp->next;
            temp->next = prev;
            prev = temp;
            temp = ahead;
        }
        return prev;
    }
};

// An optimized version of the code using recursion is as follows:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
ListNode* revRec(ListNode* temp, ListNode*prev){
    if(temp==NULL){
        return prev;
    }
    else{
    ListNode* ahead = temp->next;
    temp->next = prev;
    prev = temp;
    temp = ahead;
    return revRec(temp, prev);
    }
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* ans = revRec(temp, prev);
        return ans;
    }
};