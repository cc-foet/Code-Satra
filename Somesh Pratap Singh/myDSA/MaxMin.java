import java.util.Scanner;

public class MinMax {  
    
    public class Node {  
        int data;  
        Node next;  
        public Node(int data) {  
            this.data = data;  
        }  
    }  
  
      
    public Node head = null;  
    public Node tail = null;  
  
      
    public void add(int data) {  
        
        Node newNode = new Node(data);  
          
        if (head == null) {  
             
            head = newNode;  
            tail = newNode;  
            newNode.next = head;  
        }
 else 
{  
             
            tail.next = newNode;  
            
            tail = newNode;  
            
            tail.next = head;  
        }  
    }  
  
    
    public void minNode() 
{  
        Node current = head;  
        
        int min = head.data;  
        if (head == null) {  
            System.out.println("List is empty");  
        }
 else 
{  
            do
 {  
                
                if (min > current.data) 
{  
                    min = current.data;  
                }  
                current = current.next;  
            }
 while (current != head);  
  
            System.out.println("Minimum value node in the list: " + min);  
        }  
    }  
  
   
    public void maxNode() 
{  
        Node current = head;  
        
        int max = head.data;  
        if (head == null) 
{  
            System.out.println("List is empty");  
        } 
else 
{  
            do
 {  
                  
                if (max < current.data) 
{  
                    max = current.data;  
                }  
                current = current.next;  
            } 
while (current != head);  
  
            System.out.println("Maximum value node in the list: " + max);  
        }  
    }  
  
    public static void main(String[] args)
 {  
        MinMax nodee = new MinMax();  
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter the number of elements to add to the list:");
        int numElements = sc.nextInt();
        
        for (int i = 0; i < numElements; i++)
 {
            System.out.println("Enter element " + (i + 1) + ":");
            int data = sc.nextInt();
            nodee.add(data);
        }
        
         
        nodee.minNode();  
        
        nodee.maxNode();  
        
        
    }  
}
