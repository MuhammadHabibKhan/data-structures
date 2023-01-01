#include <iostream>
using namespace std;

// COUNTER NOT UPDATED WHEN LIST UPDATED add c++ line 

class node{
    public:
    int data;
    node* next; // next pointer must point to the next node hence type node
};
// user-defined datatype for creating a node with data and next pointer

node* head = 0;
node* newnode = 0;
node* temp = 0;
// since to maintain prev links, head must remain unchanged after 1st iteration 
// so introduction of temp pointer to deal with this issue. Used diff. for other functions
// (declaring 3 pointers of type 'node'. Head -> starting point with 0 initially)

int c = 0; // count variable

void create_list(){
    head = 0;
    int input_continue = 1;
    // int input _continue declared to keep creating new nodes as per user
    while(input_continue){
        c++;
        newnode = new node[sizeof(node)]; // for storing new nodes 
        // newnode, pointer of type class node holds an array of size node
        // size node as data int -> 4 bytes & pointer 4/8 bytes for x86/x64
        cout << "Enter Data: " << endl;
        cin >> newnode->data;
        // data entered goes to data var of new node
        newnode->next = 0; 
        // next pointer set to 0 for last node
        if (head == 0){
            head = temp = newnode;
            // first condition when head is 0. Newnode goes to head.
            // temp is also maintained so link prev with newnode remains intact.
        }
        else{
            temp->next = newnode;
            // the next of prev node pointed through temp now points at our newly 
            // created node [ x | address] 
            temp = newnode;
            // temp is now updated to keep address of the new new node so in the 
            // next iteration, the new new new node takes address of new new node 
            // in its next through temp
        }
        
        cout << " Do you wish to continue? (0/1) " << endl;
        cin >> input_continue;
    }
}

void print_list(){
        // traversing the list to print values
        temp = head; // making temp go to start
        cout << " ----------------------------------------------" << endl;
        cout << "Linked List ==> " ;
        cout << "[ " ;
        while (temp!= 0){ // not (temp->next != 0) as it will stop before the last 
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "]";
        cout << endl;
        cout << "Total elements: " << c << endl;
}

void insert_front(){
    // when adding a new node, link with right one always maintained first
    if (head == 0){
        cout << "Please create a list first" << endl;
    }
    else{
    newnode = new node[sizeof(node)];
    cout << "Enter Data: " << endl;
    cin >> newnode->data;

    newnode->next = head; // head is just a pointer containing address of 1st element of list
    head = newnode; // first element updated through head after previous was stored in next of newnode
    }
}

void insert_end(){
    newnode = new node[sizeof(node)];
    cout << "Enter Data: " << endl;
    cin >> newnode->data;

    newnode->next = 0; // as last node has next = 0
    // traversing the list till the previous last member to access it
    // and put address of newnode there instead of 0, traversing using temp 3rd pointer

    temp = head;
    while (temp->next != 0){ // here not (temp ! = 0) as we need the last node to access and put next
    // if done, then temp becomes zero at the end and statement out of the loop won't work
        temp = temp->next;
    }
    temp->next = newnode;
}

void insert_after(int &pos){
    if (pos > c){
        cout << "Invalid Position" << endl;
    }
    else{
        newnode = new node[sizeof(node)];
        // first traverse till required position to insert after
        temp = head; // starting point
        int i = 1; // check variable
        while (i < pos){ // check less than req position, stops one before as next has one further address
            temp = temp->next; // temp takes the next address
            i++; 
        }
        cout << "Enter Data: " << endl;
        cin >> newnode->data; // data entered goes to new node
        newnode->next = temp->next; // the right link; the prev next is put into newnode's next 
        temp->next = newnode; // temp (after which we insert) has address of newnode instead of prev next
        // always right link established first so that link is not lost as address is retrieved from
        // left of the next to point to and then previous next is replaced with new node's address
    }
}

void delete_front(){
    if (head == 0){
        cout << "Please create list first" << endl;
    }
    else{
    temp = head; // temp maintains link to delete later as change in head will result in loss of it
    head = head->next; // head takes the next of where it was initially pointing(the one to be deleted)
    delete temp; // deleting whose's next was taken
    }
}

void delete_end(){
    class node* prevnode; // need to maintain another temporary pointer as temp will traverse 
    // till end and prevnode will hold address one node before that to put 0 in its next 
    // and temp will be deleted. Not the only way to do this, can traverse till second last
    // and then free the node in its next and place 0 over there.
    temp = head;
    while (temp->next != 0){
        prevnode = temp;
        temp = temp->next;
    }
    if (temp == head){
        // if only one element in list then simply set head to null
        head = 0;
    }
    else{
        prevnode->next = 0;
    }
    delete temp;
}

void delete_at(int &pos){
    if (pos > c){
        cout << "Invalid position" << endl;
    }
    else{
        if (pos == 1){
            delete_front(); // corner case check as first node cannot be deleted with this algorithm
        }
        class node* nextnode; // extra pointer to delete the otherwise lost link
        temp = head;
        int i = 1;
        while (i < pos-1){ // stops 2 before as it'll have address of second last in its next so temp
        // takes the address of second last node in its last iteration
            temp = temp->next;
            i++;
        }
    nextnode = temp->next; // temp's next will have address of the node to be deleted (now stored in nextnode)
    temp->next = nextnode->next; // newnode (prev temp->next) is the address of the node to be deleted 
    // so its next will have the conitnued link of list which we store in temp's next to remove the old link
    delete nextnode; // deleting the old link by accessing through our 2nd pointer
    }
}

void delete_all(){
    for (int i=0; i<c; i++){
        delete_at(i);
    }
}

int main(){
    create_list();
    print_list();
    delete_all();
    //print_list();
    insert_front();
    //print_list();
    //insert_end();
    //print_list();
    //int pos = 1;
    //insert_after(pos);
    //print_list();
    return 0;
}