#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
struct Node* top = nullptr;

void PushLinkedList(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = top;
    top = temp;
}
void Pop(){
    Node* temp;
    if(top == nullptr) return; // checks that head is empty
    temp = top;
    top = top->next; // fixed the next node's address
    delete temp; // Delete
}
void Print()
{
    Node *temp = top;
    while(temp != nullptr){
        cout << temp -> data << endl;
        temp = temp->next;
    }
}
int main()
{
    PushLinkedList(5);
    Pop();
    PushLinkedList(10);
    PushLinkedList(20);
    Print();
}
