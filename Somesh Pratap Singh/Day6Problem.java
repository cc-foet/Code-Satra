package DSA;
class List 
{
    int val;
    List next;

    List(int val)
     {
        this.val = val;
        this.next = null;
    }
}

public class RemoveDuplicates 
{
    
    public static List deleteDuplicates(List head)
     {

        if (head == null) 
        {
            return null;
        }
        
        List cur = head;
        
        while (cur.next != null)
         {
            if (cur.val == cur.next.val)
             {
                cur.next = cur.next.next;
            } else 
            {
                cur = cur.next;
            }
        }
        
        return head;
    }

    public static void main(String[] args) 
    {
        
        List head = new List(1);
        head.next = new List(1);
        head.next.next = new List(2);
        head.next.next.next = new List(3);
        head.next.next.next.next = new List(3);
        head.next.next.next.next.next = new List(4);
        head.next.next.next.next.next.next = new List(5);
        head.next.next.next.next.next.next.next = new List(5);




        
        head = deleteDuplicates(head);

        
        List current = head;
        while (current != null) 
        {
            System.out.print(current.val + " ");
            current = current.next;
        }
    }
}
