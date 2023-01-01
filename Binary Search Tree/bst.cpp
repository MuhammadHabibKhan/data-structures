#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* RC;
    node* LC;
};

node* create_node(int element){
    node* newnode = new node;
    newnode->data = element;
    newnode->LC = NULL;
    newnode->RC = NULL;
    return newnode;
}

node* inorder_successor(node* temp){ 
    // inorder successor for finding the last element to insert the node at
    while (temp->LC != NULL){
        temp = temp->LC;
    }
    return temp;
}

node* search (node* temp, int data){
    int depth = 0;
    while (temp->data != data ){
            if (temp->data > data){
                temp = temp->LC;
                depth++;
            }
            else{
                temp = temp->RC;
                depth++;
            }
            if (temp == NULL){
                cout << "Element not found" << endl;
                return NULL;
            }
    }
    cout << data << " is found at depth: " << depth << endl;
    return temp;
}

void Inorder(node* node){ 
    // inorder traversal to check after operations as if everything printed in order
    // if(!(node->LC==NULL && node->RC==NULL)){
    //     cout<<"(";
    // }
    if (node->LC != 0){
        Inorder(node->LC);
    }
    cout << node->data << " ";
    if (node->RC != 0){
        Inorder(node->RC);
    }
    // if(!(node->LC==NULL && node->RC==NULL)){
    //     cout<<")";
    // }
}

node* insert_node(node* temp, int element){
    if (temp == NULL){
        return create_node(element);
    }
    if (element < temp->data){
        temp->LC = insert_node(temp->LC, element);
    }
    else{
        temp->RC = insert_node(temp->RC, element);
    }
    return temp;
}

node* delete_node(node* root, int element){
    // finding node to be deleted
    if (root == NULL){
        return root;
    }
    if (element < root->data){
        root->LC = delete_node(root->LC, element);
    }
    else if (element > root->data){
        root->RC = delete_node(root->RC, element);
    }
    else{
    // condition for no child
    if (root->LC==NULL && root->RC==NULL)
            return NULL;
    // for one child
    else if (root->LC == NULL){
        node* temp2 = root->RC;
        delete root;
        return temp2;
    }
    else if (root->RC == NULL){
        node* temp2 = root->LC;
        delete root;
        return temp2;
    }
    // if two child nodes
    node* temp2 = inorder_successor(root->RC);

    // inorder successor goes to position of node to be deleted
    root->data = temp2->data;
    // delete the inorder successor
    root->RC = delete_node(root->RC, temp2->data);
    //check whether deleting node came to case 1 or case 2 or else repeat case 3
    // RC here because inorder successor is the lowest number in root's right tree
    // so starts from right but then goes left
    }
    return root;
}


int main(){
    node* root = NULL;
    root = insert_node(root, 10);
    root = insert_node(root, 20);
    root = insert_node(root, 30);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);
    root = insert_node(root, 70);
    search (root, 50);
    Inorder(root);
    cout << endl;
    root = delete_node(root, 30);
    Inorder(root);
    return 0;
}