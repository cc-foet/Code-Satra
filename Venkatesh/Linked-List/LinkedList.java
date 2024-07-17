public class LinkedList {

    Node head;

    class Node {
        int data;
        Node next;

        Node (int data) {
            this.data = data;
            this.next = null;
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

    public void removeDuplicates() {
        Node temp = head;
        if (temp == null) {
            return;
        }
        while (temp.next != null) {
            if (temp.data == temp.next.data) {
                temp.next = temp.next.next;
            } else {
                temp = temp.next;
            }
        }
    }

    public void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + (temp.next != null ? " -> " : ""));
            temp = temp.next;
        }
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.insertion(1);
        list.insertion(2);
        list.insertion(2);
        list.insertion(4);
        list.insertion(4);
        list.insertion(4);
        list.insertion(5);

        list.removeDuplicates();
        list.printList();
    }
}