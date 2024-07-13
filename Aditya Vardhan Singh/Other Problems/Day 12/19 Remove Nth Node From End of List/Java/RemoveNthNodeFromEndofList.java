/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    ListNode header;
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int m = size(head) - n;
        if (head == null) {
            return head;
        }
        if (m == 0) {
            head = head.next;
            return head;
        }
        ListNode currNode = head;
        ListNode nextNode = head.next;
        for (int i = 1; i < m; i++) {
            currNode = currNode.next;
            nextNode = nextNode.next;
        }
        currNode.next = nextNode.next;
        return head;
    }

    public int size(ListNode head) {
        ListNode currNode = head;
        int size = 0;
        while (currNode != null) {
            size++;
            currNode = currNode.next;
        }
        return size;
    }
}