// This program converts a sorted linked list into a binary search tree (BST) and prints its preorder traversal (root-left-right).

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev) {
        prev->next = nullptr;
    }

    return slow;
}

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    ListNode* mid = findMiddle(head);
    TreeNode* node = new TreeNode(mid->val);

    if (head == mid) return node;

    node->left = sortedListToBST(head);
    node->right = sortedListToBST(mid->next);

    return node;
}

void preorderTraversal(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    TreeNode* root = sortedListToBST(head);
    preorderTraversal(root);

    return 0;
}
