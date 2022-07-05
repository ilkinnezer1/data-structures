#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int cash = 1000;
void Play(int bet)
{
    char C[3] = {'J','Q', 'K'};

    cout << "Shuffling.." <<endl;
    srand(time(NULL));
    for(int i=0; i < 10; ++i)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp;
        temp = C[x];
        C[x]= C[y];
        C[y]=temp;  //Swapping characters;

    };

    int GuessPosition;
    cout << "Guess the position of Queen: "<< endl;
    cin >> GuessPosition ;

    if(C[GuessPosition -1] == 'Q')
    {
        cash += 3*bet; 
        cout << "You are the winner!!!" << "Your cash now is: " <<cash << endl;
    }else{
        cash -= bet;
        cout << "You lost. Try again!" << "Your cash now is: " << cash << endl;
    }

};


int main()
{
    int bet;
    while(cash > 0){
        cout << "Hello User!" << endl;
        cout << "What is your bet? :"<< endl;
        cin >> bet;

        if(bet <= 0 || bet > cash )
            break;
        
        Play(bet);
    }
}