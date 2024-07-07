class Node {
    int val;
    Node next;

    Node(int val) {
        this.val = val;
        this.next = null;
    }
} 
//Remove Duplicate Element in a Linked List

public class RemoveDuplicates {

    public Node removeDuplicates(Node head) {
        Node current = head;
        while (current != null && current.next != null) {
            if (current.val == current.next.val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        return head;
    }

    public static void printList(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.val + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        Node node5 = new Node(5);
        Node node4_3 = new Node(4);
        Node node4_2 = new Node(4);
        Node node4_1 = new Node(4);
        Node node2_2 = new Node(2);
        Node node2_1 = new Node(2);
        Node head = new Node(1);

        head.next = node2_1;
        node2_1.next = node2_2;
        node2_2.next = node4_1;
        node4_1.next = node4_2;
        node4_2.next = node4_3;
        node4_3.next = node5;

        System.out.println("Linked list before removing duplicates:");
        printList(head);

        RemoveDuplicates solution = new RemoveDuplicates();
        Node newHead = solution.removeDuplicates(head);

        System.out.println("\nLinked list after removing duplicates:");
        printList(newHead);
    }
}
