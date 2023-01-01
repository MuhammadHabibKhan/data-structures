#include <iostream>
using namespace std;

class tree_node{
    public:
    char ch; // take operator or operand
    tree_node* LC; // pointer to left child
    tree_node* RC; // pointer to right child
};

tree_node* stack[20]; // creating a stack to contain elements of type tree_node
int top = -1; // initializing top with -1 as we do with stack using arrays
tree_node* root = 0; // head or root initialized with 0 (null)

string infix = "AB+CD-*"; // input hard coded for the time being

void create_tree(){
    for (int i=0; i<infix.length(); i++){
        tree_node* temp = new tree_node; // creates an empty node
        temp->ch = infix[i]; // ch takes current character
        temp->LC = NULL; // left and right child set to null first
        temp->RC = NULL;
        char c = infix[i];

        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
            temp->RC = stack[top--]; // takes right child out of stack into the temp
            temp->LC = stack[top--]; // same for LC
            stack[++top] = temp; // puts the temp in stack containing LC and RC
        }
        else{
            stack[++top] = temp;
        }
    }
    root = stack[top--]; // as last one always remain unpopped so taking it out through root or head
}

void Inorder(tree_node* node){
    if(!(node->LC==NULL && node->RC==NULL)){
    cout<<"(";
    }
    if (node->LC != 0){
        Inorder(node->LC);
    }
    cout << node->ch;
    if (node->RC != 0){
        Inorder(node->RC);
    }
    if(!(node->LC==NULL && node->RC==NULL)){
    cout<<")";
    }
    // if null then return else Inorder at left then cout then inorder at right
}

void PostOrder(tree_node* node){
    if (node->LC != 0){
        PostOrder(node->LC);
    }
    if (node->RC != 0){
        PostOrder(node->RC);
    }
    cout << node->ch;
}

void PreOrder(tree_node* node){

    cout << node->ch;
    if (node->LC != 0){
        PreOrder(node->LC);
    }
    if (node->RC != 0){
        PreOrder(node->RC);
    }
}

int main(){
    create_tree();
    Inorder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    PreOrder(root);
    return 0;
}

