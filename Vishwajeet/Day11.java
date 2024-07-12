// Problem: Convert Sorted Linked List to Binary Search Tree in Pre Order Traversal

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
        left = right = null;
    }
}

public class Day11 {
    ListNode head;

    // Function to find the length of the linked list
    private int findLength(ListNode head) {
        int length = 0;
        while (head != null) {
            length++;
            head = head.next;
        }
        return length;
    }

    // Function to convert sorted linked list to BST
    private TreeNode sortedListToBST(int start, int end) {
        if (start > end) {
            return null;
        }

        int mid = start + (end - start) / 2;

        // Recursively build the left subtree
        TreeNode leftChild = sortedListToBST(start, mid - 1);

        // Root node will be the middle element
        TreeNode root = new TreeNode(head.val);
        root.left = leftChild;

        // Move to the next element in the list
        head = head.next;

        // Recursively build the right subtree
        root.right = sortedListToBST(mid + 1, end);

        return root;
    }

    public TreeNode sortedListToBST(ListNode head) {
        this.head = head;
        int length = findLength(head);
        return sortedListToBST(0, length - 1);
    }

    // Function to print preorder traversal of the BST
    private void preOrderTraversal(TreeNode node) {
        if (node == null) {
            return;
        }
        System.out.print(node.val + " ");
        preOrderTraversal(node.left);
        preOrderTraversal(node.right);
    }

    public static void main(String[] args) {
        Day11 obj = new Day11();

        // Creating a sorted linked list
        obj.head = new ListNode(1);
        obj.head.next = new ListNode(2);
        obj.head.next.next = new ListNode(3);
        obj.head.next.next.next = new ListNode(4);
        obj.head.next.next.next.next = new ListNode(5);
        obj.head.next.next.next.next.next = new ListNode(6);
        obj.head.next.next.next.next.next.next = new ListNode(7);

        TreeNode root = obj.sortedListToBST(obj.head);

        System.out.print("Preorder Traversal of constructed BST: ");
        obj.preOrderTraversal(root);
    }
}
