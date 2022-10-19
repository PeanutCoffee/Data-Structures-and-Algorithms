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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = new ListNode(0);
        ListNode fast = temp;
        ListNode slow = temp;
        temp.next = head;
        int count = 1;
        
        
        // stop slow one before the element that has to be removed
        while(fast!=null && count < n+1) {
            fast = fast.next;
            count++;
        }
        
        while(fast.next!=null) {
            slow = slow.next;
            fast = fast.next;          
        }
        slow.next = slow.next.next;
        return temp.next;
    }
}