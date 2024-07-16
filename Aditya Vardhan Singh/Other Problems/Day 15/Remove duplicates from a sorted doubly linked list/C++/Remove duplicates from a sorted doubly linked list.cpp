/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        if (!head->next) {
            return head;
        }
        
        // Your code here
        Node *temp = head;
        Node *del = nullptr;
        
        while (temp->next) {
            if (temp->data == temp->next->data) {
                del = temp->next;
                temp->next = temp->next->next;
                if (temp->next) {
                    temp->next->prev = temp;
                }
                del->next = del->prev = nullptr;
                delete(del);
            } else {
                temp = temp->next;
            }
        }
        
        return head;
    }
};