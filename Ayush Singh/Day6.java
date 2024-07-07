class LinkedList {
    Node head;

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public void removeDuplicates() {
        if (head == null) return;

        Node current = head;

        while (current != null && current.next != null) {
            if (current.data == current.next.data) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
    }

    public void append(int data) {
        if (head == null) {
            head = new Node(data);
            return;
        }

        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = new Node(data);
    }

    public void printList() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        list.append(1);
        list.append(1);
        list.append(2);
        list.append(3);
        list.append(3);
        list.append(4);
        list.append(4);
        list.append(5);

        System.out.println("Original list:");
        list.printList();

        list.removeDuplicates();

        System.out.println("List after removing duplicates:");
        list.printList();
    }
}

