#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int dice1, dice2;
    dice1 = rand()%6 + 1;
    dice2 = rand()%6 + 1;

    for(int i = 1; i <= 10; i++){
    cout << "Roll #" << i << ": " << dice1 << " and " << dice2 << " = " << dice1 + dice2 <<  endl;
    }

}
