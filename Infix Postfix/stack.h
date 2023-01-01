#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* link; //previous element address
};
 // Difference between linked list & stack using LL; LL uses previous node's next to point to newnode
 // stack has newnode pointing to previous node. This is in accordance with working of stack
 // Always delete and add to stack with LL at begining to keep the time complexity O(1) 

node* top = 0;
node* newnode = 0;
node* temp = 0;

void push(int x){
    newnode = new node[sizeof(node)];
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

void display(){
    // taking another pointer as top cannot be moved
    temp = top; // starting from top
    if (top == 0){
        cout << "Stack is empty, first create one please" << endl;
    }
    else{
        cout << "-----------------------------" << endl;
        while (temp != 0){
            cout << temp->data << endl;
            temp = temp->link;
        }
        cout << "-----------------------------" << endl;
    }
}

void peek(){
    if (top == 0){
        cout << "Stack is empty, first create one please" << endl;
    }
    else{
    cout << "Top most element is: " << top->data << endl;
    }
}

void pop(){
    if (top == 0){
        cout << "Stack is empty, first create one please" << endl;
    }
    else{
    temp = top;
    cout << "Element popped is: " << top->data << endl; // can use temp -> data too as both pointing to same thing
    top = top->link; // can use temp -> link too as both pointing to same thing
    delete temp;
    }
}
