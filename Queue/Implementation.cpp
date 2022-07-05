#include <iostream>
using namespace std;

int queue [100], n = 100, front = -1, rear = -1;
void Insert()
{
    int val;
    if(rear == n - 1)
    {
        cout << "Queue over flow" << endl;
    }else{
        if(front == -1)
            front = 0;
            cout << "Insert an element in queue: ";
            cin >> val;
            rear++;
            queue[rear] = val;
    }
}
void Delete()
{
    if(front  == -1 || front > rear){
        cout << "Queue under flow" << endl;
        return;
    }else{
        cout << "Removed element is: " << queue[front] << endl;
        front++;
    }
}
void Display()
{
    if(front == -1){
        cout << "Queue is empty" << endl;
    }else{
        cout << "Queue elements are: ";
        for(int i = front ; i<=rear; i++){
            cout << queue[i] << " ";
            cout << endl;
        }
    }
}
int main()
{
    int choices;
    cout << " Follow the instructions" <<endl;
    cout<<"1) Insert element to queue"<<endl;
    cout<<"2) Delete element from queue"<<endl;
    cout<<"3) Display all the elements of queue"<<endl;
    cout<<"4) Exit"<<endl;

    do{
        cout << "Enter your choice: " ;
        cin >> choices;
        switch (choices) {
            case 1: Insert();
                break;
            case 2: Delete();
                break;
            case 3: Display();
                break;
            case 4: cout << "****EXIT****" <<endl;
                break;
            default: cout << "Invalid choice" << endl;
        }
    }while(choices !=4);

}