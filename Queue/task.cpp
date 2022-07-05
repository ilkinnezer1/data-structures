#include <iostream>
#include <queue>
using namespace std;

queue<string> myTask;

void addTask(const string& task){
    myTask.push(task);
}

void DeleteTask(){
    if(myTask.empty()){
        cout << "Your task list is empty!"<<endl;
    }
    myTask.pop();
    cout << "Task is removed" <<endl;
}
void NumberOfTasks(){
    cout << "You have " << myTask.size() << " tasks "<<endl;
}
void seeAllTasks(){
   while(!myTask.empty()){
       cout << "Your tasks:" <<endl;
       cout << myTask.front() << endl;
       myTask.pop();
   }
}
void DisplayRecentTask()
{
    if(myTask.empty()){
        cout << "Your task list is empty" <<endl;
    }
    cout << "You newly added " << myTask.front() << " task" <<endl;
}


int main()
{
   int choices;
   string task;
   cout<< "Welcome to the to do list " << endl;
   cout << " Follow the instructions" <<endl;
   cout << "Press 1 to add your task" <<endl;
   cout << "Press 2 to delete your task" <<endl;
   cout << "Press 3 to see your all tasks" <<endl;
   cout << "Press 4 to see your recent task" <<endl;
   cout << "Press 5 to see the number of your task" <<endl;
   cout << "Press 6 to exit app" <<endl;

   do{
       cout << "Enter your choice: ";
       cin >> choices;
       switch (choices) {
           case 1:
               cout << "Please write your task: ";
               cin >> task;
               addTask(task);
               break;
           case 2: DeleteTask();
               break;
           case 3: seeAllTasks();
               break;
           case 4: DisplayRecentTask();
               break;
           case 5: NumberOfTasks();
               break;
           case 6: cout << "See you!" <<endl;
           default: cout << "Invalid choice" <<endl;
           break;
       }
   }while(choices != 6);

}