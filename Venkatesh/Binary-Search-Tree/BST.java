public class BST {

    Node head;


    class Node {
        int data;
        Node next;

        Node (int data) {
            this.data = data;
            this.next = null;
        }
    }

    static class TreeRoot {
        TreeRoot left;
        int data;
        TreeRoot right;
    
        TreeRoot (int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    public void insertion(int data) {
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
           
        int[] preorder = new int[count];
           
        int[] arr = new int[count];
        temp = head;
        for (int i = 0; i < count; i++) {
            arr[i] = temp.data;
            temp = temp.next;
        }
           
        TreeRoot root = convertToBST(arr, 0, count - 1);
        
        preorderTraversal(root, preorder, 0);
        
        return preorder;
    }

    private static TreeRoot convertToBST(int[] arr, int start, int end) {
        if (start > end) {
            return null;
        }
        
        int mid = (start + end) / 2;
        
        TreeRoot root = new TreeRoot(arr[mid]);
        
        root.left = convertToBST(arr, start, mid - 1);
        root.right = convertToBST(arr, mid + 1, end);
        
        return root;
    }

    private static int preorderTraversal(TreeRoot TreeRoot, int[] preorder, int index) {
        if (TreeRoot == null) {
            return index;
        }
        preorder[index] = TreeRoot.data;
        index++;
        
        index = preorderTraversal(TreeRoot.left, preorder, index);
        index = preorderTraversal(TreeRoot.right, preorder, index);
        
        return index;
    }
    
    public static void main(String[] args) {
        BST list = new BST();
        list.insertion(1);
        list.insertion(2);
        list.insertion(3);
        list.insertion(4);
        list.insertion(5);
        list.insertion(6);
        list.insertion(7);

        int[] preorder = convertToBST(list.head);

        for (int i = 0; i < preorder.length; i++) {
            System.out.print(preorder[i] + " ");
        }
    }
}