#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
Lab Exercise#7
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
*/

int diceRollSum();// function to calculate the sum of two random numbers

int main(){
  srand(time(0));
    
  for(int i = 0; i< 5; i++){
      cout << diceRollSum() << endl;//five function calls 
  }
    

}

int diceRollSum(){
int dice1, dice2;

    dice1 = rand()%6 + 1;
    dice2 = rand()%6 + 1;

    return dice1 + dice2;

}