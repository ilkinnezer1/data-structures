#include <iostream>
#include <string>
using namespace std;
// Ladies and gentlemen, dynamic programming sucks! 

// Defining the min comparison
int min(int x, int y, int z) 
{
    return min(min(x,y),z);
}
// 2 strings and their lengths
int calculateDistance(string str1, string str2, int x, int y)
{
    int dp[x+1][y+1]; // Creating a table

    for(int i = 0 ; i <= x; ++i){
        for(int j = 0; j<=y; ++j){
            // When first string is empty
            if(i == 0){ 
                dp[i][j] = j;
                // When second string is empty
            }else if (j==0)
            {
                dp[i][j]= i; 
            }else if (str1[i-1] == str2[j-1]) // if last chars are the same
            {   
                   dp[i][j] = dp[i-1][j-1]; 
            }else // last chars are different
            {
                // Insertion = dp[i][j-1]; 
                // deletion = dp[i-1][j]; 
                // replacement = dp[i-1][j-1]
              dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }     
        }
    }
    return dp[x][y];
}
int main()
{
    string str1 = "sunday";
    string str2 = "saturday";
    cout << calculateDistance(str1, str2, str1.length(), str2.length());
}