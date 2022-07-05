#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int data; // Data of BT
    Node* left; // Left-child
    Node* right ; // Right-child
};

// Creating new node
struct Node* newNode(int data){
    Node* node  = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return (node);
}

// Traversing Preorder
void TraversePreOrder(Node* temp){
    if(temp != nullptr){
        cout << " " << temp->data ;
        //Recursively defined procedure
        TraversePreOrder(temp->left);
        TraversePreOrder(temp->right);
    }
}
// Traverse Inorder
void TraverseInOrder(Node* temp){
    if(temp != nullptr){
        TraverseInOrder(temp->left);
        cout << " " << temp->data;
        TraverseInOrder(temp->right);
    }
}
//Traverse Postorder

void TraversePostOrder(Node* temp){
    if(temp != nullptr){
        TraversePostOrder(temp->left);
        TraversePostOrder(temp->right);
        cout << " " << temp->data;
    }
}


int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->left->right = newNode(6);

    cout << "Preorder Traversal: "<< endl;
    TraversePreOrder(root);
    cout << " Inorder Traversal: " << endl;
    TraverseInOrder(root);
    cout << " Postorder traversal: " <<endl;
    TraversePostOrder(root);

}