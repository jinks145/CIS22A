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
void load(string filename, int ** data);
int total(int numbers[], int size);
int percentage(int total);
string grader(string data, int percentage);
string compute(string data[], int size);
void convert(string  data, int * split, int size);
void dump(string data, string destFile);





int main(){
    int * data[20];
    load("ass7data.txt", data);

    for(int i = 0; i < 20; i++){
        for(int j =0 ; j < 15; j++){
        cout << setw(4) << data[i][j];
        }
        cout << endl;
    }

}

void load(string filename, int ** data){//loads data from file
    fstream fs("ass7data.txt", fstream::in);
    string lines[20];



    for(int i = 0; i < 20; i++){
         for(int j = 0; j < 15; j++){
            fs >> data[i][j];
         }
           
    }



    fs.close();


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
void convert(string  data, int * split, int size){
    stringstream ss(data);

    for(int i = 0; i < size; i++){
        ss >> split[i];
    }

}
