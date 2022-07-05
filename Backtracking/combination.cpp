#include <iostream>
using namespace std;

 // Initialize passwords and sizes
 // take each char of string (ASCII)
 // get a single number by substracting 0
 // if: single number 2 > single number 1 then subtract 9 and increment (rotation)
 // compare answers and update response by incrementing 
int combinationLock(string pass1, string pass2, int length)
{
    int res = 0; // result
    for(int i = 0; i < length; i++)
    {
        // getting single numbers (ASCII)
        int singleNum1 = pass1[i] - '0'; 
        int singleNum2 = pass2[i] - '0';
        // Finding absolute difference 
        int ans1 = abs(singleNum1 - singleNum2); 
        int ans2 = 0; 
        // which of them is greater subtract from 9 and incrememnt ans2 each time
        if(singleNum1 < singleNum2){
            ans2 = singleNum1;
            ans2 += 9 - singleNum2;
            ans2++;
        }else{
            ans2 = (9 - singleNum1);   
            ans2 = singleNum2;  
            ans2++;
        } 
        // Update response and output
        if(ans1 > ans2)
              res += ans2;
        else
            res += ans1;
    }
    return res;
}

int main()
{
    string pass1, pass2;
    int length, res = 0;
    cout << "Size: " <<endl;
    cin >>length;
    cout << "Enter pass 1: " << endl;
    cin >>pass1;
    cout << "Enter pass 2: " << endl;
    cin >> pass2;
    cout << "Output is : " << combinationLock(pass1, pass2, length); // DONE!
}