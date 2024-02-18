# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

"""
Remove duplicates from a sorted linked list. Return the head of that new linked list 
"""

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None: 
            return head
        current = head.next
        prev = head
        appeared = {head.val}
        while current != None: 
            if current.val not in appeared:
                appeared.add(current.val)
                prev = current
                current = current.next
            else: 
                prev.next = current.next
                current = current.next
        
        return head

