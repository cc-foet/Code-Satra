#include <iostream>
using namespace std;

// Definition for singly-linked list node
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for a binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Class to handle operations related to linked list
class LinkedList {
public:
    ListNode* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end
    void insert(int value) {
        if (head == nullptr) {
            head = new ListNode(value);
        } else {
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new ListNode(value);
        }
    }

    // Function to find the middle element of the linked list
    ListNode* findMiddleElement(ListNode* start, ListNode* end) {
        ListNode* slowPtr = start;
        ListNode* fastPtr = start;

        while (fastPtr != end && fastPtr->next != end) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        return slowPtr;
    }
};

// Class to handle operations related to BST
class BST {
public:
    // Function to convert the sorted linked list to BST
    TreeNode* sortedListToBST(ListNode* start, ListNode* end) {
        if (start == end) {
            return nullptr;
        }

        // Find the middle element of the list
        ListNode* mid = findMiddleElement(start, end);

        // The middle element becomes the root
        TreeNode* node = new TreeNode(mid->val);

        // Recursively form the left and right subtrees
        node->left = sortedListToBST(start, mid);
        node->right = sortedListToBST(mid->next, end);

        return node;
    }

    // Function to print preorder traversal of the BST
    void preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

private:
    // Helper function to find the middle element (to be used internally)
    ListNode* findMiddleElement(ListNode* start, ListNode* end) {
        ListNode* slowPtr = start;
        ListNode* fastPtr = start;

        while (fastPtr != end && fastPtr->next != end) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        return slowPtr;
    }
};

int main() {
    // Creating and populating the linked list
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);
    ll.insert(7);

    // Converting the sorted linked list to BST
    BST bst;
    TreeNode* root = bst.sortedListToBST(ll.head, nullptr);

    // Displaying the BST in preorder
    cout << "Preorder traversal of the BST: ";
    bst.preorderTraversal(root);
    cout << endl;

    return 0;
}
