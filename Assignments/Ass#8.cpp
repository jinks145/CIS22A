/*
Assignment#8
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

struct player{
    const string name;
    int total;
};

int * diceRoll();
void turn(player &p);
int total(int * arr, int size = 2);



int main(){
    player players[3] = {{"larry", 0}, {"curly", 0}, {"Moe", 0}};

    int totals[3] ={0,0,0};
    srand(time(NULL));
        while(players[0].total < 100 && players[1].total < 100 && players[2].total < 100){

        for(int i =0 ; i < 3; i++){
         turn(players[i]);
        }
    }
    
}

int * diceRoll(){
   static int  pairs[2];
    

   pairs[0] = rand() % 6  + 1;
   pairs[1] = rand() % 6  + 1;


    return pairs;
}

void turn(player &p){// need to tweak the sum

    int sum = 0, all = 0;
    int * outcome;
    std::cout << p.name +", its your turn" << endl << "    ";

    if(p.name == "larry"){
        outcome = diceRoll();
        sum = total(outcome);
        if(!(outcome[0] == 1 || outcome[1] == 1)){
            std::cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   sum << endl;
            p.total += sum;
         }
            else
            {
                std::cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   "skunk" << endl;
            }

        }


    else if(p.name == "curly"){
        for(int i = 0; i < 3; i++){
        int * outcome = diceRoll();
        sum = total(outcome);
         if(!(outcome[0] == 1 || outcome[1] == 1)){
            cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   sum << endl;
            p.total += sum;
         }
            else
            {
            cout << "          " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   "skunk" << endl;
            break;
            }

        }
    }

    else{
        do{
             outcome = diceRoll();
            sum = total(outcome);
            if(!(outcome[0] == 1 || outcome[1] == 1))
            cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   sum << endl;
            else
            {
                cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   "skunk" << endl;
            }

            p.total += sum;
        }while( outcome[0] != 1 && outcome[1] != 1);
    }

    cout << "That's " << all << " points for your turn" << endl;
    cout << "Total points = " << p.total << endl;
    
}

int  total(int * arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
    sum += arr[i];
    }
    return sum;
}



