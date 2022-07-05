#include <iostream>
using namespace std;

// DELETING N-TH POSITION NODE 
// 1) Fix the links
// 2) Free the memory (heap)

struct Node
{
    int data;
    Node* next;
};
struct Node* head;
//Inserting procedure

void Insert(int x){
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
};

//Print

void Print()
{
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<endl;
        temp = temp->next;
    };
}
//Deleting procedure

void Delete(int x) {
    Node* temp1 = head;
    if(x == 1)
    {
        head = temp1->next; // points to second node
        cout << temp1->data << " is deleted" <<endl;
        delete temp1;
        return;
    }
    for(int i = 0; i < x-2; ++i){
        temp1 = temp1->next;
        // temp1 points to n-1 node
    }
    Node* temp2 = temp1->next; // nth node
    //Fixing the links
    temp1->next = temp2->next; // nth+1 node
    cout << temp2->data << " is deleted " << endl;
    delete temp2; // delete node
}

int main()
{
    head = NULL; // empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    Print();
    int n; // Position
    cout << "Enter your position: " << endl;
    cin >> n;
    Delete(n);
    Print();
}