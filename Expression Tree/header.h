#include <iostream>
using namespace std;

class tree_node{
    public:
    char ch;
    class tree_node* LC;
    class tree_node* RC;
};

int s, top = -1;
tree_node* stack = new tree_node[s];

void push(tree_node& x){
    //tree_node x;
    //cout << "Enter Data: ";
    //cin >> x;
    if (top == s-1){
        cout << "Stack Overflow! " << endl;
    }
    else{
        top++;
        stack[top] = x;
    }
}

void pop(){
    tree_node element;
    if (top == -1){
        cout << "Stack Underflow! " << endl;
    }
    else{
        element = stack[top];
        top--; //leave the value which will be overridden when memory is used next time
        cout << "Popped element was: " << element.ch << endl;
    }
}

void peek(){
    //same as top function
    if (top == -1){
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "Top element is: " << stack[top].ch << endl;
    }
}

void display(){
    cout << "________________" << endl;
    for (int i=top; i>=0; i--){
        cout << "---------------" << endl;
        cout << stack[i].ch << endl;
    }
    cout << "________________" << endl;
}
