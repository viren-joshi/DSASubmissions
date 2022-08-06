# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # node = head
        s=""
        l=0
        while head is not None:
            s+=str(head.val)
            head=head.next
            l+=1
        for i in range(l/2):
            if(s[i]!=s[l-1-i]):
                return False
        return True