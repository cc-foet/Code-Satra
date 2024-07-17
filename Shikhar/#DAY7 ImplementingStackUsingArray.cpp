// In this file I have implemented a stack using an array
// I have implemented the basic operations of push(), pop(), peek() and isEmpty().
// All within a "Stack" Class.
// The time complexity of all the operations is O(1).

#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top >= 1){
            top++;
            arr[top] = element;
        }else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }else{
            cout<<"Stack Empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
};

void printStack(Stack s, int size){
    int n = size;
    for(int i=0; i<n; i++){
        cout<<s.peek()<<" ";
        s.pop();
    }
    cout<<endl;
}


