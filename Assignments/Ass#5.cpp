/*
Assignment#9
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
int dice1, dice2, diceSum ,total = 0, turnScore = 0 , turnNum = 1;

    srand(time(0));

    while(total <= 100){
    cout << "This is your turn #" << turnNum++ << endl;

    for(int i = 1; i <= 3; i++){
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        diceSum = dice1 + dice2;
        
        


    
        if(diceSum == 7){
        cout << "* You rolled " << dice1 << " and " << dice2 << ".  That's " << 0 <<  endl;
        break;
        }
        else{
            turnScore += diceSum;
            

        cout << "* You rolled " << dice1 << " and " << dice2 << ".  That's " << diceSum <<  endl;
        }

    }
    total += turnScore;
    cout << "** You scored " << turnScore << " points for this turn" << endl;
    cout << "*** Your total is now " << total << "\n\n";
    turnScore = 0;

    }


}
