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

const string name[] = {"larry", "curly", "Moe"};
vector<int> diceRoll();
int  turn(string name);
int total(vector<int> arr);


int main(){
    int totals[3] ={0,0,0};
    srand(time(NULL));
        while(totals[0] < 100 && totals[1] < 100 && totals[2] < 100){

        for(int i =0 ; i < 3; i++){
        totals[i] += turn(name[i]);
        }
    }
    
}

vector<int> diceRoll(){
    vector<int>  pairs;
    

   pairs.push_back(rand() % 6  + 1);
   pairs.push_back(rand() % 6  + 1);


    return pairs;
}

int turn(string name){// need to tweak the sum

    int sum = 0, all = 0;
    vector<int> outcome;
    std::cout << name +", its your turn" << endl << "    ";

    if(name == "larry"){
        vector<int> outcome = diceRoll();
        sum = total(outcome);
        if(!(outcome[0] == 1 || outcome[1] == 1)){
            std::cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   sum << endl;
            all += sum;
         }
            else
            {
                std::cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   "skunk" << endl;
            }

        }


    else if(name == "curly"){
        for(int i = 0; i < 3; i++){
        vector<int> outcome = diceRoll();
        sum = total(outcome);
         if(!(outcome[0] == 1 || outcome[1] == 1)){
            cout << "    " << "You rolled " << outcome[0] << " and " << outcome[1] << ".  That's " <<   sum << endl;
            all += sum;
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

            all += sum;
        }while( outcome[0] != 1 && outcome[1] != 1);
    }

    cout << "That's " << all << " points for your turn" << endl;
    cout << "Total points = " << all << endl;
    return all;
}

int  total(vector<int> arr){
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
    sum += arr[i];
    }
    return sum;
}



