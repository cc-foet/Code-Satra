#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data=0;
        this->next=NULL;

    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* deletionofduplicates(Node* head){
if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
         Node* temp=head;
         while(temp!=NULL)
       {if(temp->next!=NULL && temp->data==temp->next->data ){
Node* newnode=temp->next;
temp->next=newnode->next;
delete newnode;
        }
        else {
            temp=temp->next;
        }}
     return head;
    }
int main(){
    Node* first=new Node(1);
      Node* second=new Node(2);
    Node* third=new Node(2);
    Node* fourth=new Node(4);
    Node* fifth=new Node(4);
    Node* sixth=new Node(4);
     Node* seventh=new Node(5);
     Node* head=first;
        first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=seventh;
    seventh->next=NULL;
    printLL(head);
    cout<<endl;
    cout<<"After duplicates are removed Linked List " <<endl;
   deletionofduplicates(head);
   printLL(head);
}