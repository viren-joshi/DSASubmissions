# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        n1=0
        n2=0
        mul1=1
        while l1 is not None:
            n1+=(l1.val*mul1)
            mul1*=10
            l1=l1.next
        mul2=1
        while l2 is not None:
            n2+=(l2.val*mul2)
            mul2*=10
            l2=l2.next
        s = n1+n2
        print(n1,n2,s)
        headNode = ListNode(s%10)
        s/=10
        currentNode = headNode
        flag=True
        while s>0 :
            currentNode.next=ListNode(s%10)
            currentNode = currentNode.next
            s/=10
            print("la",s)
        return headNode