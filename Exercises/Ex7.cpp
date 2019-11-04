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

int diceRoll();

int main(){
  srand(time(0));
    
  for(int i = 0; i< 5; i++){
      cout << diceRoll() << endl;
  }
    

}

int diceRoll(){
int dice1, dice2;
    dice1 = rand()%6 + 1;
    dice2 = rand()%6 + 1;

    return dice1 + dice2;

}