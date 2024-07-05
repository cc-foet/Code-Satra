#include <iostream>
#include <unordered_map>
using namespace std;

 struct Node {
        int data;
        struct Node* next;
    };
    bool has_cycle(Node* head) {
    if(!head){
        return false;
    }
    unordered_map <Node*, int>m;
    while(head!=NULL){
        if(!m[head]){
            m[head]=1;
            head=head->next;
        }
        else{
            return true;
        }
    }
    return false;
}