public class BinarySearchTree {
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    static class TreeNode {
        TreeNode left;
        int data;
        TreeNode right;

        TreeNode(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    public void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node last = head;
            while (last.next != null) {
                last = last.next;
            }
            last.next = newNode;
        }
    }

    public static int[] convertToBST(Node head) {
        if (head == null) {
            return new int[0];
        }

        int count = 0;
        Node temp = head;
        while (temp != null) {
            count++;
            temp = temp.next;
        }

        int[] traversal = new int[count];

        int[] arr = new int[count];
        temp = head;
        for (int i = 0; i < count; i++) {
            arr[i] = temp.data;
            temp = temp.next;
        }

        TreeNode root = constructBST(arr, 0, count - 1);

        preorderTraversal(root, traversal, 0);

        return traversal;
    }

    private static TreeNode constructBST(int[] arr, int start, int end) {
        if (start > end) {
            return null;
        }

        int mid = (start + end) / 2;

        TreeNode root = new TreeNode(arr[mid]);

        root.left = constructBST(arr, start, mid - 1);
        root.right = constructBST(arr, mid + 1, end);

        return root;
    }

    private static int preorderTraversal(TreeNode root, int[] preorder, int index) {
        if (root == null) {
            return index;
        }
        preorder[index] = root.data;
        index++;

        index = preorderTraversal(root.left, preorder, index);
        index = preorderTraversal(root.right, preorder, index);

        return index;
    }

    public static void main(String[] args) {
        BinarySearchTree list = new BinarySearchTree();
        list.insert(9);
        list.insert(14);
        list.insert(30);
        list.insert(46);
        list.insert(48);
        list.insert(66);
        list.insert(69);

        int[] preorder = convertToBST(list.head);

        for (int i = 0; i < preorder.length; i++) {
            System.out.print(preorder[i] + " ");
        }
    }
}
