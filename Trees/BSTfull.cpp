#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node //Structure of BST
{
    int data;
    struct node *left, *right;
};
struct node *newNode(int data) // Creating new node
{
    auto *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}
struct node* insert(struct node* node, int data)
{
    if (node == nullptr) return newNode(data);
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}
int minValue(struct node* node)
{
    struct node* current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return(current->data);
}
int maxValue(struct node* node)
{
    struct node* current = node;

    while (current->right != nullptr)
    {
        current = current->right;
    }
    return(current->data);
}

struct node* Delete(node* root, int data){
    //For the empty tree
    if(root == nullptr) return root;
    // Conditions
    if(data < root->data){ // left subtree
        root->left = Delete(root->left,  data);
    }else if(data > root->data){ // right subtree
        root->right = Delete(root->right,  data);
        // After finding the data to remove
    }else{
        // Case 1: no child - leaf
        if(root->left ==  nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
            // Case 2: one child
        }else if(root->left == nullptr){
            struct node *temp = root;
            root = root->right;
            delete temp;
        }else if(root->right == nullptr){
            struct node* temp = root;
            root = root->left;
            delete temp;
            // Case 3: 2 children
        }else{
            // To find min value in right subtree
            struct node* minVal;
            minVal = reinterpret_cast<node *>(minValue(root->right));
            root->data = minVal->data;
            root->right = Delete(root->right, minVal->data);
        }
    }
    return root;
}
struct node* FindValue(node* root, int data){
    if(root == nullptr) return nullptr;
    if(root->data == data) return root;
    else if(root->data > data) return FindValue(root->left, data);
    else return FindValue(root->right , data);
}
//Find minimum
struct node* findMin (node* root){
    if(root == nullptr) return root;
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}
//Find successor
struct node* findSuccessor(node* root, int data){
    // Searching node
    node* currentNode = FindValue( root, data);
    if(currentNode == nullptr) return nullptr;
    else{
        // Case 1: has right subtree
        if(currentNode->right != nullptr) return findMin(currentNode->right);
        // Case 2: no right subtree
        else{
            node* successor = nullptr;
            node* ancestor = root;
            while(ancestor != currentNode){
                if(ancestor->data > currentNode->data){
                    successor = ancestor;
                    ancestor = ancestor->left;
                }else{
                    ancestor = ancestor->right;
                }
            }
            return successor;
        }
    }
}

bool isBST(struct node* root){
    if(minValue(root) < root->data && maxValue(root) > root->data){
        return true;
    }else return false;
}
// Breadth-first search
void LevelOrder(struct node* root){ // Orders each element according to their levels
    if(root == nullptr){
        return;
    }
        queue<node*> Q;
        Q.push(root); // Insert root on queue
        while(!Q.empty()){
            struct node* temp = Q.front();
            cout << temp->data << " ";
            if(temp->left != nullptr) Q.push(temp->left);
            if(temp->right != nullptr) Q.push(temp->right);
            Q.pop(); // To remove element from the front on queue
    }
}

//Depth-first Search
void PreOrderSequence(struct node* root){
    if(root == nullptr) return;
    cout <<  root->data << " " <<endl;
    // Recursively defined structure
    PreOrderSequence(root->left);
    PreOrderSequence(root->right);
}
void InOrderSequence( struct node* root){
    if(root == nullptr) return;
    // Recursively defined structure
    InOrderSequence(root->left);
    cout << root->data << " "<<endl;
    InOrderSequence(root->right);
}
void PostOrderSequence(struct node* root){
    if(root == nullptr) return;
    // Recursively defined structure
    PostOrderSequence(root->left);
    PostOrderSequence(root->right);
    cout << root->data << " " <<endl;
}

//Find max depth of tree
int FindHeightOrDepth(struct node* node){
    struct node* root = node;
    if(root == nullptr){
        return -1;
    }else{
        // Calculate the height for root
        return max(FindHeightOrDepth(root->left), FindHeightOrDepth(root->right)) + 1 ;
    }
}
int main()
{
    int maxValue(struct node* );
    struct node* insert(struct node* , int );
    int minValue(struct node* );
    struct node *root = nullptr;
    root = insert(root, 8);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    insert(root, 8);
    insert(root, 9);
    insert(root, 0);
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
 

//    LevelOrder(root);

    // Depth-first search
    cout << "Preorder Traversal: " <<endl;
    PreOrderSequence(root);
    cout << "Postorder Traversal: " <<endl;
    PostOrderSequence(root);
    cout << "Inorder Traversal: " <<endl;
    InOrderSequence(root);
    cout << " Minimum value in BST is " << minValue(root)<<endl;
    cout << " Maximum value in BST is " << maxValue(root) <<endl;
    cout << "The height of the tree is: "<< FindHeightOrDepth(root) <<endl;
    if(isBST(root)){
        cout << "That is BST" <<endl;
    }else{
        cout << "That is not BST" <<endl;
    }

    struct node* successorValue = findSuccessor(root, 10);
    if( successorValue == nullptr){
        cout << "Successor can't be found " <<endl;
    }else{
        cout << "Successor is: "<<  successorValue->data<<endl;
    };
}
b