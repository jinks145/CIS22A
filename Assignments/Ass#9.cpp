/*
Assignment#9
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

const int MAX = 400;
void load(ifstream &fs, int * data, int size);
int total(int numbers[], int size);
int percentage(int total);
string grader(string data, int percentage);
string compute(string data[], int size);
void dump(string data, string destFile);





int main(){
    ifstream in("ass7data.txt");
    int data[20][15];
    

    for(int i = 0; i < 20; i++){
        load(in, data[i], 15);
    }
    in.close();


}

void load(ifstream &fs, int * data, int size){//loads data from file
    
    if(fs.is_open()){

    for(int i = 0; i < size; i++){
         
            fs >> data[i];
         
        }
    }
}

void dump(string data, string destFile){//dumps data to the desired file
    ofstream dumper;
    dumper.open(destFile.c_str());
    dumper << data;

    dumper.close();
}

int total(int numbers[],  int size){// calculates total
    int sum = 0;

    for(int i = 0 ; i < size; i++){
        sum += numbers[i];
    }

    return sum;
}

int percentage(int total){// calculates percentage
    return floor(100 * static_cast<float>(total) / MAX + 0.5);
}

string grader(int percentage){// grader from Assignment #4
    string grade = "";
    string remark = "";

    switch(percentage /10){
        case 10 :
            grade = "A";
            break;
        case 9:
            grade = "A";
            break;

        case 8 :
            grade = "B";
            break;

        case 7 :
            grade = "C";
            break;

        case 6 :
            grade = "D";
            break;

        default :
            grade = "F";
    }

    if(grade == "A"){
        remark = "Excellent work";
    }

    else if(grade == "B" || grade == "C"){
        remark = "Not bad!";
    }

    else{
        remark = "You better try again";
    }

    if(percentage / 10 > 5 && percentage  != 100){
        if(percentage % 10 < 2 ){
            grade += "-";
        }
        else if(percentage % 10 > 7){
            grade += "+";
        }

    }
    else if(percentage == 100){
        grade += "+";
    }


    return grade + "\n" + remark;
}



string compute(string data[], int size){

}



