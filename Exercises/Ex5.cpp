#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
Name : Jooho Jeong
Exercise : Lab Exercise #5
Compiler used : Code::Blocks on a PC
Completed at : ATC Lab
*/

int main(){
    int dice1, dice2;
    srand(time(0));

    for(int i = 1; i <= 10; i++){
        dice1 = rand()%6 + 1;
        dice2 = rand()%6 + 1;

    cout << "Roll #" << i << ": " << dice1 << " and " << dice2 << " = " << dice1 + dice2 <<  endl;
    }

}
