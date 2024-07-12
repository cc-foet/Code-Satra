/* Day 11 Problem : 
Given a sorted linked list, convert it into a binary search tree and display its preorder traversal (root-left-right).

Input: LinkedList = 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7

Output: {4, 2, 1, 3, 6, 5, 7} 
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
};

struct node *newnode(int);
struct treenode *newtreenode(int);
struct node *findMiddle(struct node *);
struct treenode *sortedTree(struct node *);
void preorder(struct treenode *);

void main() {
    struct node* head;
    head = newnode(1);
    head->next = newnode(2);
    head->next->next = newnode(3);
    head->next->next->next = newnode(4);
    head->next->next->next->next = newnode(5);
    head->next->next->next->next->next = newnode(6);
    head->next->next->next->next->next->next = newnode(7);

    struct treenode* root;
    root = sortedTree(head);

    printf("Preorder : ");
    preorder(root);
    printf("\n");
}

struct node *newnode(int key){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

struct treenode *newtreenode(int key) {
    struct treenode* temp = malloc(sizeof(struct treenode));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *findMiddle(struct node *head){
    
    int count = 0;
    struct node *ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }

    count /= 2;
    ptr = head;
    
    for(int i = 0; i < count; i++){
        ptr = ptr->next;
    }

    return ptr; 
}

struct treenode *sortedTree(struct node *head){
    
    struct node* mid = findMiddle(head);
    struct treenode* root = newtreenode(mid->data);

    if(head == mid) return root;

    struct node *lefthead, *righthead;
    
    lefthead = head;
    righthead = mid->next;

    struct node *temp = head;
    while(temp->next != mid){
        temp = temp->next;
    }
    temp->next = NULL;

    root->left = sortedTree(lefthead);
    root->right = sortedTree(righthead);

    return root;
}

void preorder(struct treenode *root){
    if(root == NULL) return;
    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

/*
Output : Preorder : 4 2 1 3 6 5 7
*/