/*
Lab Exercise #9
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

int reven();// churns out a even number

int main(){
    int numbers[10];

    srand(time(0));

    for(int i = 0; i < 10; i++){
        numbers[i] = reven();
    }

    for(int i = 0; i < 10; i++){
        cout << right << setw(8) << i << setw(8) << numbers[i] << setw(8) << setprecision(4) << sqrt(numbers[i]) << endl;
    }
}

int reven(){
    int num = -1;

    while(num % 2 != 0){
        num = rand() % 99 + 2;
    }

    return num;
}


