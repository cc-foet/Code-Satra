//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        if (head->next == nullptr) {
            return {{}};
        }
        
        vector<pair<int, int>> ans;
        Node *front = head;
        Node *back = head;
        
        while (back->next) { back = back->next; }
        
        while (front != back && back->next != front) {
            int d1 = front->data;
            int d2 = back->data;
            
            if (d1 + d2 == target) {
                ans.push_back( {d1, d2} );
                front = front->next;
                back = back->prev;
            } else if (d1 + d2 < target) {
                front = front->next;
            } else {
                back = back->prev;
            }
        }
        
        return ans;
    }
};