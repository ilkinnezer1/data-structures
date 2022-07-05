#include <iostream>
#include <cstdlib>
using namespace std;


struct Node
{
    int data;
    Node* next;
};
struct Node* head; // Global vaiable to be accessed from everywhere

void Insert(int *x)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = *x; // Assigning the new value
    temp->next = head;
    head = temp;
}
void Print()
{
    Node* temp = head;
    cout << "List is:  " ;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    head = NULL; // means list is empty
    cout << "How many numbers ?" << endl;
    int n; 
    cin >> n;
    for(int i; i < n ; ++i)
    {
        int x;
        cout << "Type your number: " << endl;
        cin >> x;
        //Calling insert function
        Insert(&x);
        Print();
    }
}

