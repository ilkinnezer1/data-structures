#include <iostream>
using namespace std;

struct Node{
    int data; // Data of BT
    Node* left; // Left-child
    Node* right ; // Right-child
};
struct Node* root; // Tree is empty

//Search Node
bool Search(Node* rootPrnt, int data) {
    if(rootPrnt == nullptr) return false ;
    if(rootPrnt->data == data) return true;
    else if(data <= rootPrnt->data){
        return Search(rootPrnt->left, data);
    }else{
        return Search(rootPrnt->right, data);
    }
}
// Insert nodes
Node* InsertNode(Node* rootPtr, int data){
    //Getting new node address
    Node* temp = new Node();
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;

    if(rootPtr == nullptr){
        rootPtr = temp;
    }else if(data <= temp->data){
        temp->left = InsertNode(temp->left, data);
    }else{
        temp->right = InsertNode(temp->right,  data);
    }
    return rootPtr; // Sending address of root from heap
}

int main()
{   root = nullptr;
    root = InsertNode(root, 5);
    root = InsertNode(root, 15);
    root = InsertNode(root, 25);
    int number;
    cout<<"Enter number be searched: " << endl;
    cin>>number;
    if (Search(root, number))
        cout << "Found\n";
    else cout << "Not Found\n";
}