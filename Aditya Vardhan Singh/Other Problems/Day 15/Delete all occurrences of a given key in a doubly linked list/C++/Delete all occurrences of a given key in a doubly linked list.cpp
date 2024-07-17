// User function Template for C++


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        struct Node * del;
        while ((*head_ref)->data == x) {
            del = *head_ref;
            *head_ref = (*head_ref)->next;
            del->next = del -> prev = nullptr;
            delete(del);
        }
        struct Node *temp = *head_ref;
        while (temp->next) {
            if (temp->next->data == x) {
                del = temp->next;
                temp->next = temp->next->next;
                del->next = del->prev = nullptr;
                delete(del);
            }
            else {
                temp = temp->next;
            }
        }
    }
};
