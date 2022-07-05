#include <iostream>
using namespace std;
int F[1000];

int fib(int n){
    if(n <= 1){
        return n;
    }
    if(F[n] != -1){
        return F[n];
    }
    F[n] = fib(n-1) + fib(n-2);
    return F[n];
}

int main()
{
    for(int i = 0; i < 1000 ; i++){
        F[i] = -1;
    }

    int ans = fib(800);

    cout<<ans;
}