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
    ListNode* oddEvenList(ListNode* head) {
        // If list has not more than 3 nodes, return list
        if (!(head && head->next && head->next->next)) {
            return head;
        }

        // Separate odd and even (indexed) lists
        ListNode * oddHead = head;
        ListNode * evenHead = head->next;

        ListNode *oddTemp = oddHead;
        ListNode *evenTemp = evenHead;

        while (oddTemp->next || evenTemp->next) {
            if (evenTemp->next) {
                oddTemp->next = evenTemp->next;
                evenTemp->next = nullptr;
                oddTemp = oddTemp->next;
            }
            if (oddTemp->next) {
                evenTemp->next = oddTemp->next;
                oddTemp->next = nullptr;
                evenTemp = evenTemp->next;
            }
        }

        // Join odd and even list
        oddTemp->next = evenHead;

        return oddHead;
    }
};
