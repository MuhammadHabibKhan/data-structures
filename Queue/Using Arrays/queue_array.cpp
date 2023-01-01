#include <iostream>
using namespace std;

int s;
int* queue = new int[s];

int front = -1; // deletion from begining (dequeue)
int rear = -1; // insertion from the end (enqueue)

void enqueue(){
    int x;
    cout << "Enter Data to insert: ";
    cin >> x;
    if (rear == s-1){ // if at end
        cout << "Queue is full" << endl;
    }
    else if(front == -1 && rear == -1){ // if not created
        front = rear = 0; // front also set to 0 (begin) as being created 1st time
        queue[rear] = x; // putting element at 0
    }
    else{ 
        rear++; // normal condition increase rear 
        queue[rear] = x; // and place value
    }
}

void dequeue(){
    if (front == -1 && rear == -1){
        cout << "Queue is empty" << endl;
    }
    else if(front == rear){
        cout << "Element dequeued is: " << queue[front] << endl;
        front = rear = -1; // if rear and front equal then means end has reached so simply reset by
        // putting original value in the queue
    }
    else{
        cout << "Element dequeued is: " << queue[front] << endl;
        front++; // normal condition deletes from front then makes front point to next element
    }
}

void display(){
    if (front == -1 && rear == -1){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "------------------" << endl;
        for(int i=front; i<=rear; i++){
            cout << queue[i] << endl;
        }
        cout << "------------------" << endl;
    }
}

void peek(){
    if (front == -1 && rear == -1){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Element at top is: " << queue[front] << endl;
    }
}

int main(){
    cout << "Enter size of queue: ";
    cin >> s;
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    peek();
    display();
    delete[] queue;
    return 0;
}