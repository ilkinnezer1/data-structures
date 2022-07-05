#include <iostream>
#include <string.h>
using namespace std;

// Returning max value

int max(int a, int b)
{
    return (a > b ) ? a : b;
}

int LongestCommonSubsequence(char *str1, char *str2 , int x, int y)
{
    int dp[x+1][y+1];

    for(int i = 0; i <= x; ++i)
        for(int j = 0; j<=y; ++j){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else if(str1[i - 1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }   
        }
    return dp[x][y];    
}


int main(){
    char str1[] = "AGGTAB";
    char str2[] = "GXTXAYB";

    int x  = strlen(str1);
    int y  = strlen(str2);

    cout << "LCS is " << LongestCommonSubsequence(str1, str2, x, y);

}