#include <cstddef>
using namespace std;

struct Node
{
    int val;
    struct Node *next;
    struct Node *prev;
    Node(int a)
    {
        val = a;
        next = NULL;
        prev = NULL;
    }
};
class Solution {
public:
    Node* reverseList(Node* head) {
        if (head->next == nullptr) {
            return head;
        }
        Node* curr = head->next;
        head->next = nullptr;
        head->prev = curr;
        while(curr->next != nullptr) {
            Node* next = curr->next;
            curr->next = curr->prev;
            curr->prev = next;
            curr = next;
        }
        curr->next = curr->prev;
        curr->next = nullptr;
        return curr;
    }
};
