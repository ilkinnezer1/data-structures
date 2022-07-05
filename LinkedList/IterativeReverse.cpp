#include <iostream>
using namespace std;

struct  Node
{
    int data;
    Node* next;
};

// Defining head globally

struct Node* Insert(Node* head, int n)
{
    Node *temp = new Node();
// Putting data
    temp->data = n;
    temp->next = NULL;
    if(head  == NULL) {
        head = temp;
    }else{
        Node* temp1 = head;
        while(temp1->next != NULL) temp1 = temp1->next;
         temp1->next = temp;
    }
 return head;
  
}
struct Node* ReverseIteratively(Node* head)
{   
    struct Node *prev ,*current, *next; // Store the value
    current = head;
    prev = NULL; // Inital value
    while(current != NULL)
    {
        // Points to the node from current
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    return head;
}

void Print(Node* head)
{
    while(head != NULL)
    {
        cout <<head->data << " ";
        head = head->next;
    }
}
int main()
{
    struct Node* head;
    head = NULL; // empty set
    head = Insert(head,4);
    head =  Insert(head, 5);
    head = Insert(head,6);
    head = Insert(head, 7);
    Print(head);

}

