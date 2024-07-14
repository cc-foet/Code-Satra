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
    ListNode * mergeList(ListNode * left, ListNode * right) {
        ListNode * dummy_head = new ListNode(-1);
        ListNode * temp = dummy_head;

        while (left && right) {
            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if (left) {
            temp->next = left;
        } else {
            temp->next = right;
        }

        return dummy_head->next;
    }
    ListNode * getMid(ListNode * head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode * slow = head;
        ListNode * fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode * sortList(ListNode* head) {
        if (!head || !head->next) { // already sorted
            return head;
        }

        ListNode * mid = getMid(head);
        ListNode * left = head;
        ListNode * right = mid->next;
        mid->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return mergeList(left, right);
    }
};