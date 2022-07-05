#include <iostream>
using namespace std;

// Define the elements of linked list
struct Node{
    int data;
    Node* next;
};
// Define front and rear(tail) in queue
struct Node* front = nullptr;
struct Node* rear = nullptr;

// Enqueue or Inserting
void Enqueue(int x){
    // Memory allocation
    Node *temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    if(front == nullptr && rear == nullptr){
       front = rear = temp;
       return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue(){
    Node* temp = front;
    // Empty queue
    if(front == nullptr){
        cout << "Linked list is empty" <<endl;
        return;
    }
    if(front == rear){
        front = rear = nullptr;
    }else{
        front = front->next; // Pointers to the next element
    }
    delete temp;
}

void PrintFront()
{
    if(front == nullptr){
        cout << "List is empty" << endl;
    }
    cout << front->data << " " ;
}

void Print(){
    Node* temp = front;

    while(temp!= nullptr){
        cout <<temp->data << endl;
            temp= temp->next;
    }
}
int main()
{
    Enqueue(5);
    Enqueue(10);
    Print();
}