#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};


struct Node* AddToEmpty(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = temp;
    return temp;
};


struct Node* atTheBeg( struct Node* tail , int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = tail->next;
    tail->next = newNode;
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
    tail = atTheBeg(tail, 53);
    Print(tail);
}