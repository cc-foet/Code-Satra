class Node {
    int data;
    Node next;
    
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    public LinkedList() {
        this.head = null;
    }

    // Method to add a node at the beginning of the linked list
    public void insertAtBegin(int data) {
        Node newNode = new Node(data);
        if (this.head == null) {
            this.head = newNode;
            return;
        }
        newNode.next = this.head;
        this.head = newNode;
    }

    // Method to add a node at a specific index in the linked list
    public void insertAtIndex(int data, int index) {
        Node newNode = new Node(data);
        Node currentNode = this.head;
        int position = 0;

        if (position == index) {
            insertAtBegin(data);
        } else {
            while (currentNode != null && position + 1 != index) {
                position++;
                currentNode = currentNode.next;
            }

            if (currentNode != null) {
                newNode.next = currentNode.next;
                currentNode.next = newNode;
            } else {
                System.out.println("Index not present");
            }
        }
    }

    // Method to add a node at the end of the linked list
    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (this.head == null) {
            this.head = newNode;
            return;
        }

        Node currentNode = this.head;
        while (currentNode.next != null) {
            currentNode = currentNode.next;
        }

        currentNode.next = newNode;
    }

    // Method to update a node's value at a given index
    public void updateNode(int data, int index) {
        Node currentNode = this.head;
        int position = 0;

        if (position == index) {
            currentNode.data = data;
        } else {
            while (currentNode != null && position != index) {
                position++;
                currentNode = currentNode.next;
            }

            if (currentNode != null) {
                currentNode.data = data;
            } else {
                System.out.println("Index not present");
            }
        }
    }

    // Method to remove the first node of the linked list
    public void removeFirstNode() {
        if (this.head == null) return;

        this.head = this.head.next;
    }

    // Method to remove the last node of the linked list
    public void removeLastNode() {
        if (this.head == null) return;

        Node currentNode = this.head;
        while (currentNode.next != null && currentNode.next.next != null) {
            currentNode = currentNode.next;
        }

        if (currentNode.next != null) {
            currentNode.next = null;
        }
    }

    // Method to remove a node at a given index
    public void removeAtIndex(int index) {
        if (this.head == null) return;

        Node currentNode = this.head;
        int position = 0;

        if (position == index) {
            removeFirstNode();
        } else {
            while (currentNode != null && position + 1 != index) {
                position++;
                currentNode = currentNode.next;
            }

            if (currentNode != null && currentNode.next != null) {
                currentNode.next = currentNode.next.next;
            } else {
                System.out.println("Index not present");
            }
        }
    }

    // Method to remove a node with a specific value
    public void removeNode(int data) {
        if (this.head == null) return;

        Node currentNode = this.head;

        if (currentNode.data == data) {
            removeFirstNode();
            return;
        }

        while (currentNode.next != null && currentNode.next.data != data) {
            currentNode = currentNode.next;
        }

        if (currentNode.next != null) {
            currentNode.next = currentNode.next.next;
        }
    }

    // Method to get the size of the linked list
    public int sizeOfLL() {
        int size = 0;
        Node currentNode = this.head;

        while (currentNode != null) {
            size++;
            currentNode = currentNode.next;
        }

        return size;
    }

    // Method to print the linked list
    public void printLL() {
        Node currentNode = this.head;
        while (currentNode != null) {
            System.out.print(currentNode.data + " -> ");
            currentNode = currentNode.next;
        }
        System.out.println("null");
    }

    // Method to remove duplicates from a sorted linked list
    public void removeDuplicates() {
        if (this.head == null || this.head.next == null) return;

        Node currentNode = this.head;
        while (currentNode.next != null) {
            if (currentNode.data == currentNode.next.data) {
                currentNode.next = currentNode.next.next;
            } else {
                currentNode = currentNode.next;
            }
        }
    }

    public static void main(String[] args) {
        // Create a new linked list
        LinkedList llist = new LinkedList();

        // Add nodes to the linked list
        int[] arr = {1, 1, 2, 2, 4, 4, 4, 5, 5};
        for (int i : arr) {
            llist.insertAtEnd(i);
        }

        // Print the original linked list
        System.out.println("Original List:");
        llist.printLL();

        // Remove duplicates and print the linked list
        System.out.println("List after removing duplicates:");
        llist.removeDuplicates();
        llist.printLL();
    }
}
