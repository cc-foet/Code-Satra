//Program to merge nodes between two consecutive zeroes (the beginning and end of the linked list will have val = 0)

// For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's

#include<iostream>
using namespace std;

typedef struct ListNode {
      int val;
      ListNode *next;
  } S;

static S* head = nullptr;
static S* temp = nullptr;
void insert(int new_val) {
   S* new_node = (S*) malloc(sizeof(S));
   new_node->val = new_val;
   new_node->next = nullptr;
   if(head == nullptr){
      head = new_node;
      temp = head;
      }
    else{
      temp->next =new_node ;
      temp = new_node;
    }
   
}


S* mergeNodes(S* head) {
        S* newlist = head->next;
        S* addValue = newlist;

        while (newlist != nullptr) {
            int sum = 0;
            while (addValue->val != 0) {
                sum += addValue->val;
                addValue = addValue->next;
            }

            newlist->val = sum;
            addValue = addValue->next;

            newlist->next = addValue;
            newlist = newlist->next;
        }
        return head->next;
};

void display() {
   S* ptr;
   ptr = head;
   while (ptr != nullptr) {
      cout<< ptr->val <<" ";
      ptr = ptr->next;
   }
}

int main(){
  insert(0);
  insert(3);
  insert(1);
  insert(0);
  insert(4);
  insert(5);
  insert(2);
  insert(0);
  head = mergeNodes(head);
  display();

}