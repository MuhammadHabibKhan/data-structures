#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

node* front = 0; // (head) deletion will be done here
node* rear = 0; // (tail) insertion will be done here
// rear is maintained so that to insert at the end, O(1) is maintained and we dont have to traverse
// till end using front which will result in O(n) time complexity
node* newnode = 0;
node* temp = 0;
int c = 0; // count

void enqueue(){
    c++;
    int x;
    cout << "Enter Data: ";
    cin >> x;
    newnode = new node[sizeof(node)];
    newnode->data = x; 
    newnode->next = 0; // node added at the end pointing to nothing

    if (front == 0 && rear == 0){
        front = rear = newnode; // 1st iteration. Only 1 element hence front = rear.
    }
    else{
        rear->next = newnode; // second pointer rear maintained and in its next is added our newnode
        rear = newnode; // rear now points to our newnode so next time we access rear->next we access
        // current newnode's next and place the next newnode there.
    }
}

void display(){
    if (front == 0 && rear == 0){
        cout << "Queue is Empty!" << endl;
    }
    else{
        temp = front; // can't change head so traverse using temp
        cout << "----------------" << endl;
        while (temp != 0){ // temp here is the address of 1st node i.e is in head
            cout << temp->data << endl; // access data of 1st node
            temp = temp->next; // take your own next to become the next node and 
            // then take its data in 2nd iteration and take 2nd's next to point at 3rd and so on
        }
        cout << "----------------" << endl;
    }
}

void dequeue(){ // deletion takes place at front in queue
    temp = front;
    if (front == 0 && rear == 0){
        cout << "Queue is Empty!" << endl;
    }
    else{
        cout << "ELement Dequeued is: " << front->data << endl;
        front = front->next; // front jumps to its next breaking link with prev front
        delete temp; // using temp to access and delete it
    }
}

void dequeue_all(){
    for (int i=0; i<c; i++){
        dequeue();
    }
}

void peek(){
    if (front == 0 && rear == 0){
        cout << "Queue is Empty!" << endl;
    }
    else{
        cout << "Element at top is: " << front->data << endl;
    }
}

int main(){


    return 0;
}