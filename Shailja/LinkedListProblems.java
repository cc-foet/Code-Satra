
    class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
    }
     
    public class LinkedListProblems {
        public ListNode reverseList(ListNode head) {
            ListNode prev = null;
            ListNode curr = head;
            while (curr != null) {
                ListNode nextTemp = curr.next;
                curr.next = prev;
                prev = curr;
                curr = nextTemp;
            }
            return prev;
        }
    
        public static void main(String[] args) {
            LinkedListProblems listProblems = new LinkedListProblems();
            
            // Create linked list 1 -> 2 -> 3 -> 4 -> 5
            ListNode head = new ListNode(1);
            head.next = new ListNode(2);
            head.next.next = new ListNode(3);
            head.next.next.next = new ListNode(4);
            head.next.next.next.next = new ListNode(5);
    
            // Reverse the linked list
            ListNode reversedHead = listProblems.reverseList(head);
    
            // Print reversed linked list
            ListNode current = reversedHead;
            while (current != null) {
                System.out.print(current.val + " ");
                current = current.next;
            }
        }
    }
    
