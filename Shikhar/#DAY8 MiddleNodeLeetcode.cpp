// In this file I have solved a leetcode question in which we had to find the middle node of a linked list when we are given the head of the LL.

// Problem Link:- https://leetcode.com/problems/middle-of-the-linked-list/

// In this I have created a vounter 'i' which iterates over the LL and finds the length+1
// Then I declare 'j=i/2' for the middle node
// Then I return the LL from the found middle node using a loop.

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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int i=0;
        while(temp != NULL){
            temp = temp->next;
            i++;
        }
        int j = i/2;
        ListNode* temp1 = head;
        int k=0;
        while(k!=j){
            temp1=temp1->next;
            k++;
        }
        return temp1;
    }
};