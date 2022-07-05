#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
struct Node* head;

// Defining head globally

struct Node* Insert(Node* head, int n)
{
    Node *temp = new Node();
// Putting data
    temp->data = n;
    temp->next = nullptr;
    if(head  == nullptr) {
        head = temp;
    }else{
        Node* temp1 = head;
        while(temp1->next != nullptr) temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;

}

void RecursiveReverse(Node* headPointer)
{
    if(headPointer->next == nullptr){
        head = headPointer;
        return; // break function
    }
    RecursiveReverse(headPointer->next);

    Node* headP = headPointer->next;
    headP->next = headPointer;
    headPointer->next = nullptr;
}

void ReversePrint(Node* head)
{
    if (head == nullptr)return;;
    ReversePrint(head->next);
    cout << head->data << endl;

}
int main()
{

    head = nullptr; // empty set
    head = Insert(head,4);
    head =  Insert(head, 5);
    head = Insert(head,6);
    head = Insert(head, 7);
    ReversePrint(head);
    RecursiveReverse(head);
    ReversePrint(head);

}

