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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode();
        ListNode *t1, *t2, *t3;
        t1 = l1;
        t2 = l2;
        t3 = l3;
        int sum = 0, carry = 0;

        while (t1 && t2) {
            sum = t1->val + t2->val + carry;
            if (carry) carry = 0;
            if (sum > 9) {
                carry++;
                sum -= 10;
            }

            t3->val = sum;

            t1 = t1->next;
            t2 = t2->next;
            t3->next = new ListNode();
            t3 = t3->next;
        }

        while (t1) {
            sum = t1->val + carry;
            if (carry) carry = 0;
            if (sum > 9) {
                carry++;
                sum -= 10;
            }

            t3->val = sum;

            t1 = t1->next;
            t3->next = new ListNode();
            t3 = t3->next;
        }

        while (t2) {
            sum = t2->val + carry;
            if (carry) carry = 0;
            if (sum > 9) {
                carry++;
                sum -= 10;
            }

            t3->val = sum;

            t2 = t2->next;
            t3->next = new ListNode();
            t3 = t3->next;
        }

        if (carry) {
            t3->val = 1;
            carry = 0;
        }

        t3 = l3;
        while (t3->next->next) {
            t3 = t3->next;
        }
        if (t3->next->val == 0) {
            delete(t3->next);
            t3->next = nullptr;
        }
        
        return l3;
    }
};