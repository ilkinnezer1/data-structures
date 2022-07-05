#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};
struct Node* head; // head as a global variable to pointer to head node
void InsertAtHead(int n){
    // storing on heap
    Node *newNode = new Node();
    newNode->data = n;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if(head == nullptr)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;

}

void Print()
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data <<endl;
        temp = temp->next;
    }
}

int main()
{
    head = nullptr; // empty list
    InsertAtHead(2);
    InsertAtHead(5);
    Print();
    InsertAtHead(10);
    Print();

}



