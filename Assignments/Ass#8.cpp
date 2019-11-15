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
int skunk(int & t_total, int & sum, int & total, int * pair);


int main(){
    player players[3] = {{"larry", 0}, {"curly", 0}, {"Moe", 0}}, winner;
    

    srand(time(NULL));
        while(players[0].total < 100 && players[1].total < 100 && players[2].total < 100){

        for(int i =0 ; i < 3; i++){
         turn(players[i]);

            if(players[i].total > 100){
                cout << players[i].name << " won the game with " << players[i].total << " points";
                break;
            }
            
        }

    }
    
}

int * diceRoll(){
   static int  pairs[2];
    

   pairs[0] = rand() % 6  + 1;
   pairs[1] = rand() % 6  + 1;


    return pairs;
}

int skunk(int & t_total, int & sum, int &total, int * outcome){

    if(outcome[0] == 1 || outcome[1] == 1){
         t_total = 0; 
         cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   sum << endl;
        return 2;
    }
    else if(outcome[0] == 1 && outcome[1] == 1){
        t_total = 0;
        sum = 0; 
        total = 0;
        cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's SKUNK" << endl;
        return 1;
    }
    else{
        t_total += sum;
        total += t_total;
        cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   sum << endl;
        return 0;
    }

}

void turn(player &p){// need to tweak the sum

    int sum = 0, t_total = 0, flag;
    int * outcome;
    std::cout << p.name +", its your turn" << endl << "    ";

    if(p.name == "larry"){
        outcome = diceRoll();
        sum = total(outcome);
        
        skunk(t_total, sum, p.total, outcome);

        }


    else if(p.name == "curly"){
        for(int i = 0; i < 3; i++){

            outcome = diceRoll();
            sum = total(outcome);
        
            flag = skunk(t_total, sum, p.total, outcome);

            if(!flag) break;
        }
    }

    else{
        while(!flag){
            outcome = diceRoll();
            
            sum = total(outcome);

            flag = skunk(t_total, sum, p.total, outcome);

            
        }
    }

    cout << "That's " << t_total << " points for your turn" << endl;
    cout << "Total points = " << p.total << endl;
    
}

int  total(int * arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
    sum += arr[i];
    }
    return sum;
}



