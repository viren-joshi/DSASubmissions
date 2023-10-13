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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head1 = l1, head2 = l2;
        ListNode ans = new ListNode();
        ans.val = -1;
        ListNode ansHead = ans;
        int val1 = 0,val2 = 0, carry = 0, temp = 0, sum=0;
        while(head1 != null || head2 != null) {
            ans.next = new ListNode();
            ans = ans.next;

            if(head1 != null) {
                temp = head1.val;
                head1 = head1.next;
            }
            val1 = temp;
            temp = 0;

            if(head2 != null) {
                temp = head2.val;
                head2 = head2.next;
            }
            val2 = temp;
            temp = 0;

            sum = val1 + val2 + carry;
            carry = 0;
            if(sum > 9) {
                ans.val = sum%10;
                carry = sum/10;
            } else {
                ans.val = sum;
            }
            // ans.next = new ListNode();
            // ans = ans.next;
        }
        if(carry != 0) {
            ans.next = new ListNode(carry);
        }
        return ansHead.next;
    }
}