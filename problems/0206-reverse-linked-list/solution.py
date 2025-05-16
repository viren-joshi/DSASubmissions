# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p1 = head
        p2 = None
        while(p1):
            p3 = p1.next
            p1.next = p2
            p2 = p1
            p1 = p3
        return p2
