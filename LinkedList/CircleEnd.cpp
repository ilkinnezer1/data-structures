#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
struct Node* AddToEmpty(int data)
{
    Node* temp = new Node();
    temp->data = data; // Declaring data
    temp->next = temp; // Circulation
    return temp;
};
struct Node* atTheEnd( struct Node* tail , int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr; // cos it will be at the end
    // Making circle
    newNode->next = tail->next;
    tail->next = newNode;
    tail = tail->next;
    return tail;
}
struct Node* inAnyPosition(Node* tail, int data, int position)
{
    Node* p = tail->next; // points to the next address of tail
    Node* newPointer = new Node(); // Making new node
    newPointer->data = data; // Declaring data on heap
    newPointer->next = nullptr;
    while(position > 1) // while Position is bigger than 1
    {
        p = p->next; // Pointer to the next of tail
        position--;
    }
    newPointer->next  = p->next;
    p->next = newPointer;
    if(p == tail)
    {
        tail = tail->next;
    }
    return tail;
}

void Print(struct Node* tail)
{
    Node* temp = tail->next;
    do {
        cout << temp->data<<endl;
        temp = temp->next;
    }while(temp != tail->next);
}
int main()
{
    struct Node* tail;
    tail = AddToEmpty(45);
    tail = atTheEnd(tail, 53);
    tail = atTheEnd(tail, 6);
    Print(tail);
    tail = inAnyPosition(tail, 8, 2);
    Print(tail);
}