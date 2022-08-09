# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if(list1 == None and list2 == None):
            return None
        head=ListNode()
        currentNode=head
        flag = True
        while list1 != None and list2 != None:
            print("l1 : ",list1.val,"  l2 : ",list2.val)
            if ( list1.val < list2.val):
                currentNode.val=list1.val
                list1=list1.next
            elif (list1.val > list2.val) :
                currentNode.val=list2.val
                list2=list2.next
            elif (list1.val == list2.val) :
                currentNode.val=list1.val
                currentNode.next=ListNode(list2.val)
                if(list1.next != None or list2.next != None):
                    currentNode.next.next=ListNode()
                    currentNode = currentNode.next.next
                print(head)
                list1=list1.next
                list2=list2.next
                continue
            # currentNode.val
            currentNode.next=ListNode()
            currentNode = currentNode.next
        # print(list1)
        while list1 != None:
            currentNode.val=list1.val
            if list1.next != None :
                currentNode.next=ListNode()
            currentNode=currentNode.next
            list1=list1.next
        # print(list2)
        while list2 != None:
            currentNode.val = list2.val
            if list2.next != None :
                currentNode.next=ListNode()
            currentNode=currentNode.next
            list2=list2.next
        return head
            