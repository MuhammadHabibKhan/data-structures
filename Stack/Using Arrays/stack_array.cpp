#include <iostream>
using namespace std;

int s, top = -1;
int* stack = new int[s];

void push(){
    int x;
    cout << "Enter Data: ";
    cin >> x;
    if (top == s-1){
        cout << "Stack Overflow! " << endl;
    }
    else{
        top++;
        stack[top] = x;
    }
}

void pop(){
    int element;
    if (top == -1){
        cout << "Stack Underflow! " << endl;
    }
    else{
        element = stack[top];
        top--; //leave the value which will be overridden when memory is used next time
        cout << "Popped element was: " << element << endl;
    }
}

void peek(){
    //same as top function
    if (top == -1){
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "Top element is: " << stack[top] << endl;
    }
}

void display(){
    cout << "________________" << endl;
    for (int i=top; i>=0; i--){
        cout << "---------------" << endl;
        cout << stack[i] << endl;
    }
    cout << "________________" << endl;
}

int main(){
    cout << "Enter size of stack: ";
    cin >> s;
    int op;
    do{
        cout << "Enter operation to perform" << endl;
        cout << "1. Push  2. Pop  3. Peek  4. Display  0. Exit" << endl;
        cin >> op;
        switch(op){
            case 1: 
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            default:
            cout << "Invalid Operation" << endl;
        }
    } while(op!=0);

    delete[] stack;
}


