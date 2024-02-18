
// Definition for singly-linked list.
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;


        for (int i = 0; i < left; i++) {
            prev = prev->next;
        }

        ListNode *curr = prev-> next;

        for (int i = left; i < right; i++) {
            ListNode *next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};


/*
 * 1 <- 2 -> 3 -> 4
 * 1 <- 2 <- 3 -> 4
 *
 *
 */
