/*
Name: Jooho Jeong
Exercise: Lab Exercise #1
Compiler used : Code::Blocks on a PC
Completed at : ATC Lab
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
int r();

int main(){
    int arr[10] ={};
    srand(time(0));

    for(int i = 0; i < 1000000; i++){
        int n = r() - 1;
        arr[n - 1]++;
    }

    for(int i = 0; i < 10; i++){
         cout << setw(2) << i + 1 << "    " << setw(6) << arr[i] << endl;
    }
}

int r(){
    return rand() % 10 + 1;
}