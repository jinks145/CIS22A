/*
Assignment#8
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
*/
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
using namespace std;

const string name[] = {"Larry", "Curly", "Moe"};
string diceRoll();
string  print();
int  total();


int main(){


}

string diceRoll(){
    stringstream ss;
    int a, b;
    a = rand() % 6  + 1;
    b = rand() % 6  + 1;

    

    ss << "You rolled " << a << " and " << b << ". That's " << ((a == 1 || b == 1 )? 0 : a + b ) << "\n";
    

    return ss.str();
}

string print(string name){
    string result = name + ", its your turn";
    stringstream ss;
    if(name == "larry"){
        result += diceRoll();
    }
    else if(name == "curly"){
        for(int i = 0; i < 2; i++)
        result += diceRoll();
    }
    else{
         

    }

}

int  total(int * arr, int size){
    int total = 0;
    for(int i = 0; i < size; ){
           total += *(arr + i);
    }

    return total;
}



