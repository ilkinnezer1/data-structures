#include <iostream>
#include <string.h>
using namespace std;



// LCS(string 1, string 2, length 1, length 2 ) 
int max(int a, int b)
{
    return (a > b) ? a : b;
}

 // Recursion
int LongestCommonSubsequence(char *str1, char *str2, int i , int j)
{
    // BaseCase
    if( i==0 || j==0 ) return 0;
    if(str1[i] == str2[j])
        return 1 + LongestCommonSubsequence(str1, str2, i-1, j-1 );
    else{
        return max(LongestCommonSubsequence(str1, str2, i-1,j), LongestCommonSubsequence(str1, str2, i , j-1));
    }
}

int main()
{

    char str1[] = "AGGTAB";
    char str2[] = "GXTXAYB";

    int i = strlen(str1);
    int j  = strlen(str2);


    cout << "LCS is " << LongestCommonSubsequence(str1,str2,i,j);



}