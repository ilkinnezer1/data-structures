#include <iostream>
#include <algorithm>
using namespace std;


struct node
{
    int data;
    struct node *left, *right;
};
struct node *newNode(int data)
{
    auto *temp =  (struct node *)malloc(sizeof(struct node));
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
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 4);
    insert(root, 7);
    insert(root, 5);
    insert(root, 10);
    insert(root, 9);
    insert(root, 13);
    insert(root, 11);
    insert(root, 14);
    insert(root, 12);
    insert(root, 2);
Val
    cout << " Minimum value in BST is " << minValue(root)<<endl;
    cout << " Maximum value in BST is " << maxValue(root) <<endl;
    cout << "The height of the tree is: "<< FindHeightOrDepth(root);
}
