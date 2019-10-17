/*
Lab Exercise 4
Name: Brad
Compiler : Code::Blocks
Operating System: Windows32
*/

#include <iostream>
using namespace std;
int main(){
    int num;

    cout << "Enter an odd number => ";
    cin >> num;

    if(num % 2 != 0){
        cout << "Thank you very much";

    }
    else{
        cout << "Enter an odd number => ";
        cin >> num;

        if(num % 2 != 0){
        cout << "Thanks";

    } else if(num % 2) {
        cout << "You dummy!";
     }

    }
}
