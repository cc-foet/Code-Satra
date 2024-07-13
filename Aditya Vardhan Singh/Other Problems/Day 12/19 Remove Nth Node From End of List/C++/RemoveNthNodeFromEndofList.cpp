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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* Get size */
        int sz = 0;
        ListNode * temp = head;
        while (temp) {
            ++sz;
            temp = temp->next;
        }
        /* Ends */

        // mth node from start = nth node from back
        int m = sz - n + 1;

        if (m == 1) {
            ListNode * remove = head;
            head = head->next;
            delete(remove);
        } else {
            /* Remove mth node */
            int count = m - 2;

            temp = head;
            while (count && temp) {
                cout << temp->val << " ";
                --count;
                temp = temp->next;
            }

            if (temp->next) {
                ListNode *remove = temp->next;
                temp->next = temp->next->next;
                delete(remove);
            }
            /* Ends */
        }

        return head;
    }
};