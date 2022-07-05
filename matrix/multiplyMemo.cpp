#include <iostream>
using namespace std;

int dp[100][100];

// counting operations using memoization

int countWithMemo(int *p, int i, int j){
    if(i == j ) return  0;

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;

    for(int k = i ; k<j; k++){
        dp[i][j] = min(dp[i][j], countWithMemo(p, i , k) + countWithMemo(p , k+1 , j) + p[i-1]*p[k]*p[j]);
    }

    return dp[i][j];

};

int chainOrder(int *p , int n ) { 
    int i = 1, j = n-1; // length

    return countWithMemo(p , i , j );

}

int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof(dp));
 
    cout << "Minimum number of multiplications is "
         << chainOrder(arr, n);
}