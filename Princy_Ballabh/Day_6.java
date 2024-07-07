public class Day_6 {
    Node head;

    class Node {
        int data;
        Node next;
        Node(int d)
        {
            data=d;
            next=null;
        }
    }

    public static void main(String args[])
    {
        Day_6 list=new Day_6();
        list.push(5);
        list.push(4);
        list.push(4);
        list.push(4);
        list.push(2);
        list.push(2);
        list.push(1);
        System.out.println("Before removal of duplicates");
        list.print();
        list.duplicate();
        System.out.println("After removal of elements");
        list.print();
    }

    void duplicate()
    {
        Node curr=head;
        while(curr!=null) {
            Node temp=curr;
            while(temp!=null && temp.data==curr.data){
                temp=temp.next;
            }
            curr.next=temp;
            curr=curr.next;
        }
    }

    public void push(int data)
    {
        Node n=new Node(data);
        n.next=head;
        head=n;
    }


    void print()
    {
        Node temp=head;
        while(temp!=null) {
            System.out.print(temp.data + " ");
            temp=temp.next;
        }
        System.out.println();
    }   
}
