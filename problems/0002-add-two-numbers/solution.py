# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        ans = ListNode()
        head = ans
        while(l1 or l2):
            sum = 0
            if l1:
                sum+=l1.val
                l1 = l1.next
            if l2:
                sum+=l2.val
                l2 = l2.next
            sum += carry
            carry = int(sum/10) if sum > 9 else 0
            sum = sum%10
            head.next = ListNode(val = sum)
            head = head.next

        if(carry != 0):
            head.next = ListNode(val=carry)
        return ans.next
