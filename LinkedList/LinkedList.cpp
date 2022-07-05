#include <iostream>
using namespace std;


// CODE IMPLEMENTATION OF LINKED LIST

// create a node
class Node 
{
    public:
    int data; // Data in the linked list
    Node* link; // Link to the next address
};

int main()
{   
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;
    Node* four = NULL;

    // Allocating three nodes in the heap (memory block)
    one = new Node();
    two = new Node();
    three = new Node();
    four = new Node();

    //Assigning the data
    one->data = 5;
    two->data = 9;
    three->data = 24;
    four->data  = 100;

    //Connecting nodes;
    one->link = two;
    two->link = three;
    three->link = four;
    four->link = NULL;

    //Printing the linked list
    head = one;
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->link;
    }

}
