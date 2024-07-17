/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> st;
        ListNode * temp = headA;
        while (temp) {
            st.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp) {
            if (st.find(temp) != st.end())
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};