public class Day6 {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data=data;
        }
    }
    public static class LinkedList{
        Node head=null;
        Node tail=null;
        int size=0;
        public void add (int data){
            Node temp=new Node(data);
            if (head==null) head=temp;
            else tail.next=temp;
            tail=temp;
            size++;
        }
        public void display(){
            Node temp=head;
            while (temp!=null) {
                System.out.print(temp.data+" ");
                temp=temp.next;
            }
            System.out.println();
        }
        public void removeduplicates(){
            Node temp=head;
            while (temp != null && temp.next != null) {
                if (temp.data == temp.next.data) {
                    temp.next = temp.next.next;
                } else {
                    temp = temp.next;
                }
            }
        }
    }
    public static void main(String[] args) {
    LinkedList list = new LinkedList();
    list.add(1);
    list.add(2);
    list.add(2);
    list.add(4);
    list.add(4);
    list.add(4);
    list.add(5);
    list.display();
    list.removeduplicates();
    list.display();
    }
    
}
