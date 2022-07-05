#include <iostream>
using namespace std;


// void Increment (int *p) 
// {
//     *p= (*p) + 1;
// };




int main()
{
//ARRAYS
int Arr[5] = {1,2,3,4,5};
int *p = &Arr[2];
cout << *(p+1) << endl;

    // int a  = 10;
    // Increment(&a);
    // cout << a<< endl;
    
} 