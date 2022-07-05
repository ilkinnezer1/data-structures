#include <iostream>
#include <stack>
using namespace std;

bool isParenthesisBalanced(string exp)
{
    stack<char> myStc;
    char pr;
    for( int i = 0; i <exp.length() ; ++i ){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            myStc.push(exp[i]);
        }
         if(myStc.empty())
             return false;
        switch (exp[i]) {
            case ')':
                pr = myStc.top();
                myStc.pop();
                if(pr == '{' || pr == '[')
                    return false;
                break;
            case '}':
                pr = myStc.top();
                myStc.pop();
                if(pr == '(' || pr == '[')
                    return false;
                break;
            case ']':
                pr = myStc.top();
                myStc.pop();
                if(pr == '(' || pr == '{')
                    return false;
                break;
        }
    }
    return (myStc.empty());
}
int main()
{
    string expr = "[{}(){()}]";
    if(isParenthesisBalanced(expr))
    {
        cout << "Parenthesis is balanced!" << endl;
    }else{
        cout << "Parenthesis is not balanced" <<  endl;
    }
}