// In this question I have solved the Linked List problem of removing duplicate elements.

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        if(this->next!=NULL){
            this->next = NULL;
            delete next;
        }
    }
};

void printLinkedList(Node* &head){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
// This the logic for duplicate removal in which I have used a 'prev' and 'curr' node to compare the values and remove the nodes.
void removeDuplicates(Node* &head){
    Node* curr = head->next;
    Node* prev = head;
    while(curr!=NULL){
        if(prev->data == curr->data){
            prev->next = curr->next;
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            delete temp;
            continue;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
}

int main(){
    Node* head= new Node(1);
    Node* node1= new Node(2);
    Node* node2= new Node(2);
    Node* node3= new Node(4);
    Node* node4= new Node(4);
    Node* node5= new Node(4);
    Node* node6= new Node(5);
    head->next= node1;
    node1->next= node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;
    cout<<"Before Duplicate Removal: ";
    printLinkedList(head);
    removeDuplicates(head);
    cout<<"After Duplicate Removal: ";
    printLinkedList(head);
}

// Output:
// Before Duplicate Removal: 1 2 2 4 4 4 5 
// After Duplicate Removal: 1 2 4 5 