#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define INF 1e9
#define line_length 10

using namespace std;

int dp[1000];
vector <string> words ;
vector <int> parent_pointers (1000);
/// let n be the length of the text
/// Parser will take O(n)
int argmin(int word,int index,int current, int result)
{
    if(result < current)
    {
        parent_pointers[word] = index ;
        return result ;
    }
    return current ;
}
void Parser(string text)
{
    stringstream s ;
    for(int i = 0 ; i < text.size() ; i++)
    {
        if(text[i] == ' ' && s.str() != "")
        {
            words.push_back(s.str());
            s.str("");
        }
        if(text[i] == ' ')
            continue ;
        else
            s << text[i] ;
    }
    if(s.str() != "")
        words.push_back(s.str());
}
/// get the length in order of words
/// get badness in constant
int BadnessIndex(int start_Word , int end_Word)
{
    int length = 0;
    /// for spaces
    length+=end_Word-start_Word-1;
    for(int i = start_Word ; i < end_Word ;i++)
        length += words[i].size();
    ///initialization for multiplication
    int ret = 1 ;
    /// invalid case
    if(length > line_length ) return INF ;
    /// calculating badness LateX code
    for(int i = 0 ; i < 3 ; i++)
        ret *= line_length - length ;
    return ret ;
}
/// initialize dp(n) = 0
int TextJustification(int word = 0)
{
    /// the break after last word without a cost
    if(word >= words.size())
        return 0 ;
    /// initialize this for something big as this is optimization problem
    int ret = INF;
    /// Memoization part for dynamic programming
    if(dp[word] != -1)
        return dp[word];
    /// brute force for all available choices
    for(int i = word+1 ; i <= words.size() ; i++)
    {
        ret =argmin(word,i,ret ,TextJustification(i)+ BadnessIndex(word,i));
    }
    return dp[word] = ret ;
}

#undef INF
int main()
{
    memset(dp,-1,sizeof(dp));
    string text ;
    getline(std::cin,text);
    Parser(text);
    TextJustification();
    for(int i = 0 ; i <= words.size() ;i++)
    {
        cout << dp[i] << "," ;
    }
    int it = 0 ;
    while(it < words.size())
    {
        it = parent_pointers[i];
        for(int i = 0; i < it ; i++)
        {
            cout << words[i] << " " ;
        }
        cout << endl ;
        i = it ;
    }
    return 0;
}