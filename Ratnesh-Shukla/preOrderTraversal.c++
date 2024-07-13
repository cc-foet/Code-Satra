#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
  int val;
  ListNode *next;
  ListNode(int x) {
    this -> val = x;
    this -> next = NULL;
  }
};

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) {
    this -> val = x;
    this -> left = NULL;
    this -> right = NULL;
  }
};

ListNode* middleElement(ListNode* head) {
  ListNode* prevPtr = NULL;
  ListNode* slowPtr = head;
  ListNode* fastPtr = head;

  while (fastPtr != NULL && fastPtr->next != NULL) {
    prevPtr = slowPtr;
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }

  if (prevPtr != NULL) {
    prevPtr->next = NULL;
  }

  return slowPtr;
}


TreeNode* sortToBST(ListNode* head) {
  if (head == NULL) {
    return NULL;
  }
  ListNode* mid = middleElement(head);    
  TreeNode* node = new TreeNode(mid->val);

  if (head == mid) {
    return node;
  }

  node->left = sortToBST(head);
  node->right = sortToBST(mid->next);
  return node;
}


void preorder(TreeNode* root) {
  if (root == NULL) {
    return;
  }
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}

int main() {
  int n;
  cout << "Enter the number of elements in the linked list: ";
  cin >> n;

  if (n <= 0) {
    cout << "Invalid input!" << endl;
    return 0;
  }

  ListNode* head = NULL;
  ListNode* tail = NULL;

  cout << "Enter the elements of the linked list in sorted order: ";
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    ListNode* newNode = new ListNode(val);
    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } 
    else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  TreeNode* root = sortToBST(head);
  cout << "Preorder traversal: ";
  preorder(root);
  cout << endl;

  return 0;
}
