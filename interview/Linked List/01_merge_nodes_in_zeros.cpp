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
    public ListNode mergeNodes(ListNode head) {
        int sum = 0;
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        ListNode temp = head.next; // Skip the initial zero
        
        while (temp != null) {
            if (temp.val == 0) {
                // Create a new node with the sum and attach it to the new list
                current.next = new ListNode(sum);
                current = current.next;
                sum = 0; // Reset sum for the next segment
            } else {
                sum += temp.val;
            }
            temp = temp.next;
        }
        
        return dummy.next;
    }
}
