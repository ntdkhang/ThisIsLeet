from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        result = ListNode()
        currentNode = result

        if not(list1 or list2):
            return None
        while list1 and list2:
            val1 = list1.val
            val2 = list2.val
            if val1 <= val2:
                currentNode.next = list1
                list1 = list1.next
            else:
                currentNode.next = list2
                list2 = list2.next
            currentNode = currentNode.next

        currentNode.next = list1 or list2
        return result.next    

        
