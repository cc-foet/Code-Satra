#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~node() {
        int value = this->data;
    }
};

node* uniqueSortedList(node* head) {
    if (head == NULL) {
        return NULL;
    }

    node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            node* next_next = curr->next->next;
            node* nodeToDelete = curr->next;
            curr->next = next_next;
            delete nodeToDelete;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    if (n == 0) {
        cout << "The list is empty." << endl;
        return 0;
    }

    cout << "Enter the elements of the linked list: ";
    int data;
    cin >> data;
    node* head = new node(data);
    node* tail = head;

    for (int i = 1; i < n; ++i) {
        cin >> data;
        node* newNode = new node(data);
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Input: ";
    printList(head);

    head = uniqueSortedList(head);
    cout << endl <<"Output: ";
    printList(head);

    
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
