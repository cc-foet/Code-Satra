#include <iostream>
#include <vector>

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

ListNode* find_middle_of_list(ListNode* head) {
    ListNode* prev_ptr = nullptr;
    ListNode* slow_ptr = head;
    ListNode* fast_ptr = head;

    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
        prev_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    if (prev_ptr != nullptr) {
        prev_ptr->next = nullptr;
    }

    return slow_ptr;
}

TreeNode* sorted_list_to_bst(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode* mid = find_middle_of_list(head);

    TreeNode* node = new TreeNode(mid->val);

    if (head == mid) {
        return node;
    }

    node->left = sorted_list_to_bst(head);
    node->right = sorted_list_to_bst(mid->next);

    return node;
}

void preorder_traversal(TreeNode* root, std::vector<int>& result) {
    if (root == nullptr) {
        return;
    }

    result.push_back(root->val);
    preorder_traversal(root->left, result);
    preorder_traversal(root->right, result);
}

ListNode* create_list(const std::vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    std::vector<int> list_values = {1, 2, 3, 4, 5, 6, 7};
    ListNode* list = create_list(list_values);
    TreeNode* bst = sorted_list_to_bst(list);

    std::vector<int> preorder_result;
    preorder_traversal(bst, preorder_result);

    for (int val : preorder_result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
