#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* linked;
};
struct Node* head;


void Insert(int data, int position)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->linked = NULL;
    //Special case when position is 1th
    if(position == 1)
    {
        temp1->linked = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;

    for(int i = 0; i < position - 2; ++i) // For adding we have to go back 2 steps
    {
        temp2 = temp2->linked;

    }
    temp1->linked = temp2->linked;
    temp2->linked = temp1;

};

void Print()
{
    Node* temp = head;
    cout << "Your list is: " << endl;
    while(temp != NULL){
        cout << temp->data <<endl;
        temp = temp->linked;
    }
}
int main()
{
    head = NULL;
    Insert(3,1);
    Insert(5,2);
    Insert(9,3);
    Print();
}