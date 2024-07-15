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
    ListNode* deleteMiddle(ListNode* head) {
        /* edge cases */
        if (!head->next) {
            // single node only
            delete(head);
            return nullptr;
        }
        if (!head->next->next) {
            // two nodes only
            delete(head->next);
            head->next = nullptr;
            return head;
        }
        /* ends */

        /* find middle of list */
        ListNode * slow, * fast;
        slow = fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        /* ends */

        /* remove middle node */
        slow->val = slow->next->val;
        ListNode *temp = slow->next; // node to be deleted
        slow->next = slow->next->next;
        temp->next = nullptr;
        delete(temp);
        /* ends */

        return head;
    }
};