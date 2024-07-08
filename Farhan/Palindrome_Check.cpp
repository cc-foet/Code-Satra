#include <iostream>
#include <cstring> // For strlen

using namespace std;

#define SIZE 50

class stack {
    int top;
    char ar[SIZE];

public:
    stack();
    void push(char x);
    char pop();
    void display1();
    char check1();
};

stack::stack() {
    top = -1;
}

void stack::push(char x) {
    if (top < SIZE - 1) {
        ar[++top] = x;
    } else {
        cout << "Stack Overflow" << endl;
    }
}

char stack::pop() {
    if (top >= 0) {
        return ar[top--];
    } else {
        cout << "Stack Underflow" << endl;
        return '\0';
    }
}

void stack::display1() { // Corrected function definition
    cout << "Enter the expression: " << endl;
    cin >> ar;
    char *e;
    e = ar;
    while (*e != '\0') {
        push(*e);
        e++;
    }
    while (top != -1) {
        char d = pop();
        cout << d;
    }
    cout << endl;
}
 char stack::check1(){
   display1();
 }

class que {
private:
    stack e;
    int rear;
    int front;
    char ar[SIZE];

public:
    que();
    void push(char x);
    char pop();
    void display2(); // Changed return type to void
    char check2();
};

que::que() {
    front = rear = -1;
}

void que::push(char x) {
    if (rear < SIZE - 1) {
        ar[++rear] = x;
    } else {
        cout << "Queue Overflow" << endl;
    }
}

char que::pop() {
    if (front < rear) {
        return ar[++front];
    } else {
        cout << "Queue Underflow" << endl;
        return '\0';
    }
}

void que::display2() { // Corrected function definition
    cout << "Enter the expression: " << endl;
    cin >> ar;
    char *e;
    e = ar;
    while (*e != '\0') {
        push(*e);
        e++;
    }
    while (front < rear) {
        char d = pop();
        cout << d;
    }
    cout << endl;
}

char  que::check2() {
    display2();
}

int main() {
    que e;
    stack d;
    if(d.check1()==e.check2()){
      cout<<"Palindrome"<<endl;
    }
    else{
      cout<<"Not Palindrome"<<endl;
    }
    return 0;
}