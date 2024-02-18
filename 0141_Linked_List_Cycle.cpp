// Given the head of a linked list, determine if the linked list has a cycle in it.


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == 0 || head -> next == 0) {
            return false;
        }
        ListNode* turtle = head;
        ListNode* hare = head;
        while (true) {
            turtle = turtle -> next;
            hare = hare -> next -> next;
            if (hare == 0 || hare -> next == 0) 
                return false;
            if (hare == turtle)
                return true;
        }
    }
};
