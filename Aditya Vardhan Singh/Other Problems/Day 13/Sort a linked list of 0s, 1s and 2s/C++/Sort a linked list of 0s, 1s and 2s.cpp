//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
// Time taken to solve this que: 6m 17s
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // Add code here
        
        /* Create map with all element init to 0 */
        map<int, int> mp;
        // for (int i = 0; i < 3; i++) {
        //     mp[i] = 0;
        // }
        /* Ends */

        /* Map no of 0, 1, 2 */        
        Node *temp = head;
        while (temp) {
            mp[temp->data]++;
            temp = temp->next;
        }
        /* Ends */
        
        /* Change list */
        temp = head;
        for (int i = 0; i < 3; i++) {
            while (mp[i]) {
                temp->data = i;
                mp[i]--;
                temp = temp->next;
            }
        }
        /* Ends */
        
        return head;
    }
};
/*
class Solution:
    #Function to sort a linked list of 0s, 1s and 2s.
    def segregate(self, head):
        #code here
        map = {x:0 for x in range(3)}
        temp = head
        while temp:
            map[temp.data] += 1
            temp = temp.next
        temp = head
        for value in range(3):
            while map[value] > 0:
                temp.data = value
                map[value] -= 1
                temp = temp.next
        return head
    
*/


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends