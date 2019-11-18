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

using namespace std;

struct player{
    const string name;
    int total;
};// represents a player

int * diceRoll();// spits out a pair of dice rolls
void turn(player &p);//playing 
int total(int * arr, int size = 2);//sum
bool skunk(int & t_total, int & sum, int & total, int * pair);//determines if it's a skunk or a valid turn 


int main(){
    player players[3] = {{"Larry", 0}, {"Curly", 0}, {"Moe", 0}};// init 3 players
    int index = 0;
    

    srand(time(NULL));
        while(players[0].total < 100 && players[1].total < 100 && players[2].total < 100){


        for(int i =0 ; i < 3; i++){
         turn(players[i]);

            if(players[index].total < players[i].total){
                index = i;//sets the index to the highest scoring player's index
            }

            if(!(players[0].total < 100 && players[1].total < 100 && players[2].total < 100)){
            break;
            }

        }

        if(!(players[0].total < 100 && players[1].total < 100 && players[2].total < 100)){
            break;
        }//

    }
    
    cout << players[index].name << " won the game with " << players[index].total << " points.";
    // prints the highest players
}

int * diceRoll(){
   static int  pairs[2];
    

   pairs[0] = rand() % 6  + 1;
   pairs[1] = rand() % 6  + 1;


    return pairs;
}

bool skunk(int & t_total, int & sum, int &total, int * outcome){

    
    if(outcome[0] == 1 && outcome[1] == 1){

        t_total = 0;
        sum = 0; 
        total = 0;

        cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's SKUNK" << endl;
        return true;
    }

    else if(outcome[0] == 1 || outcome[1] == 1){

        t_total = 0;
        sum = 0;
        cout << "    You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   sum << endl;

        return true;
    }

    else{
        t_total += sum;        
        cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   sum << endl;
        return false;
    }

}

void turn(player &p){

    int sum = 0, t_total = 0,* outcome;
    bool flag = false;
    
    cout << endl << p.name +", its your turn" << endl;

    if(p.name == "Larry"){
        outcome = diceRoll();
        sum = total(outcome);
        
        skunk(t_total, sum, p.total, outcome);

        }

    else if(p.name == "Curly"){
        for(int i = 0; i < 3; i++){
            if(flag) break;

            outcome = diceRoll();
            sum = total(outcome);
        
            flag = skunk(t_total, sum, p.total, outcome);

        }        
    }

    else{
        while(!flag){
            outcome = diceRoll();
            
            sum = total(outcome);

            flag = skunk(t_total, sum, p.total, outcome);
        
        }
        
        
    }
    p.total += t_total;

    cout << "  That's " << t_total << " points for your turn" << endl;

    if(p.total >= 100){
        return;
    } 

    cout << "Total points = " << p.total << endl;
    
}

int  total(int * arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
    sum += arr[i];
    }
    return sum;
}



