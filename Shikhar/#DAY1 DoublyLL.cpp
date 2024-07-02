//In this program I am going to implement a Doubly Linked List and perform the following operations on it.

//1- Traversal
//2- Finding Length
//3- Inserting an element at head position.
//4- Inserting an element at tail position
//5- Inserting an element an element in between.
// To sum up 3, 4 and 5, I have also implemented a function to insert an element at any position

//The edge cases are also taken care of in this code.
//I have used C++ to write my code.

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

//Prints the Linked List.
void print(Node* &head){

    cout<<endl<<endl;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl<<endl;
}

//Gives the length of a Linked List.
int getLength(Node* &head){
    Node* temp = head;
    int length = 0;
    while(temp!=NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

//Insert an element at the head position
void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    if(head!=NULL){
        temp->next = head;
        head->prev = temp;
    }
        head = temp;

}

//Insert an element at the tail position
void insertAtTail(Node* &head, int data){
    if (head == NULL) {
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* temp1 = new Node(data);
    temp->next = temp1;
    temp1->prev = temp;
}

//Insert in between a Doubly LL
void insertInBetween(Node* &head, int position, int data){
    if (position == 0){
        insertAtHead(head, data);
        return;
    }
    int count = 0;
    Node* curr = head;
    while(count < position - 1 && curr!=NULL){
        curr = curr->next;
        count++;
    }
    if(curr->next == NULL || curr == NULL){
        insertAtTail(head, data);
        return;
    }
    Node* temp = new Node(data);
    temp->next = curr->next;
    temp->prev = curr;
    if(curr->next != NULL){
        curr->next->prev = temp;
    }
    curr->next = temp;
}

//Inserting at any position
void insertAtAnyPos(Node* &head, int position, int data){
    if(position==0){
        insertAtHead(head, data);
    }else{
    insertInBetween(head, position, data);
}
}

int main(){
    Node* node1 = new Node(1); 
    print(node1);
    insertAtHead(node1, 2);
    print(node1);
    insertAtTail(node1, 3);
    print(node1);
    insertInBetween(node1, 2, 4);
    print(node1);
    insertAtAnyPos(node1, 0, 5);
    print(node1);
    insertAtAnyPos(node1, 5, 6);
    print(node1);
}

//The output of the code is as follows:- 
// 1

// 2
// 1


// 2
// 1
// 3


// 2
// 1
// 4
// 3


// 5
// 2
// 1
// 4
// 3


// 5
// 2
// 1
// 4
// 3
// 6