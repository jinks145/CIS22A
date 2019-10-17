#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
Name : Jooho Jeong
Exercise : Lab Exercise #1
Compiler used : Code::Blocks on a PC
Completed at : ATC Lab
*/

int bingo(char ch){
    srand(time(0));
    switch(ch){
        case 'B':
        return rand() % 15 + 1;
        
        
        case 'I':
        return rand() % 15 + 16;

        case 'N':
        return rand() % 15 + 31;
        
        case 'G':
        return rand() % 15 + 46;

        case 'O':
        return rand() % 15 + 61;

        default :
         return 0;
    }
}

int main() {

   cout << bingo('B') << endl;
   cout << bingo('I') << endl;
   cout << bingo('N') << endl;
   cout << bingo('G') << endl;
   cout << bingo('O') << endl;
   cout << bingo('Z') << endl;

}