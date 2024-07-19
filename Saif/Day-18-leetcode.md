[Leetcode-question: 2](https://leetcode.com/problems/add-two-numbers/)



````java

class Solution {
    public ListNode addTwoNumbers(ListNode firstList, ListNode secondList) {
        // Create a dummy node which will be the starting point of the result list.
        ListNode dummyNode = new ListNode(0);

        // This variable will keep track of the carry-over.
        int carry = 0;

        // This will be used to iterate over the new list.
        ListNode current = dummyNode;

        // Iterate as long as there is a node left in either list or there is a carry-over.
        while (firstList != null || secondList != null || carry != 0) {
            // Sum the values of the two nodes if they are not null, else add 0.
            int sum = (firstList == null ? 0 : firstList.val) +
                      (secondList == null ? 0 : secondList.val) + carry;

            // Update carry for the next iteration.
            carry = sum / 10;

            // Create a new node with the digit value of the sum.
            current.next = new ListNode(sum % 10);

            // Move to the next node in the result list.
            current = current.next;

            // Proceed in each input list.
            firstList = firstList == null ? null : firstList.next;
            secondList = secondList == null ? null : secondList.next;
        }

        // The first node was a dummy node, so the real list starts at dummyNode.next.
        return dummyNode.next;
    }
}
````