#include <cstddef>
struct Node
{
    int val;
    struct Node *next;
    Node(int a)
    {
        val = a;
        next = NULL;
    }
};

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        // write your code here
        if (head == nullptr) {
            return head;
        }
        Node* curr = head;
        while (curr->next != nullptr) {
            Node* next = curr->next;
            if (next->val == curr->val) {
                curr->next = next->next;
                // free next?
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
