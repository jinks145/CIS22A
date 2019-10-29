/*
Assignment#9
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

const int MAX = 400;
void load(ifstream &loader, int * data, int size);
int total(int numbers[], int start, int end);
int percentage(int total);
string grader(string data, int percentage);
string compute(int * data, int size);
void dump(ofstream &dumper, int * data);
int min(int * numbers, int start, int end);
int pm(int percentage);



int main(){
    ifstream loader("ass7data.txt");
    ofstream dumper("ass9output.txt");
    int data[50][20];
    
    dumper << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr\n";
    dumper << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- ß--\n";
    for(int i = 0; i < 50; i++){
        load(loader, data[i], 16);
        compute(data[i], 20);

        dump(dumper, data[i]);
    }


    loader.close();
    dumper.close();

}

void load(ifstream &loader, int * data, int size){//loads data from file
    
    if(loader.is_open()){

    for(int i = 0; i < 12; i++){
            
            loader >> data[i];
         
        }

    for(int i = 13; i < size; i++){
        loader >> data[i];
    }
    
    
    }
    data[12] = 0;
    data[16] = 0;
    
    
}

void dump(ofstream &dumper, int * data){//dumps data to the desired file
    string grade;
   if(dumper.is_open()){
       dumper << right << setw(8) << setfill('0') << data[0] << " " << setfill(' ');

       for(int i = 1; i < 15; i++){
            if( i < 12)
            dumper << " "<< setw(2) << data[i];
            else 
            dumper << "  " << setw(3) << data[i];
            
        }

        dumper << " " << setw(3) << data[15] << " " << setw(5) << data[16] << "  " << setw(3) << data[17];
        
        grade += static_cast<char>(data[18]);

        if(static_cast<char>(data[19]) == ' '){
           dumper << " " << left << setw(3) << static_cast<char>(data[18]) << endl;
        }
        else{
            grade += static_cast<char>(data[19]);
            dumper << " " << left << setw(3) << grade << endl;
        }

        
   }

}

int total(int numbers[], int start, int end){// calculates total from start index to end index
    int sum = 0;

    for(int i = start ; i <= end; i++){
        sum += numbers[i];
    }

    return sum;
}

int percentage(int total){// calculates percentage
    return floor(100 * static_cast<float>(total) / MAX + 0.5);
}

int grader(int percentage){// grader from Assignment #4
    char grade;
    

    switch(percentage /10){
        case 10 :
            grade = 'A';
            break;
        case 9:
            grade = 'A';
            break;

        case 8 :
            grade = 'B';
            break;

        case 7 :
            grade = 'C';
            break;

        case 6 :
            grade = 'D';
            break;

        default :
            grade = 'F';
    }


    return grade;
}

int pm(int percentage){
    char sign = ' ';
    if(percentage / 10 > 5 && percentage  != 100){
        if(percentage % 10 < 2 ){
            sign = '-';
        }
        else if(percentage % 10 > 7){
            sign = '+';
        }

    }
    else if(percentage == 100){
        sign = '+';
    }
    

    return sign;
}



string compute(int * data, int size){
    data[12] = total(data, 1, 11) - min(data, 1, 11);
    data[16] = total(data, 12, 15);

    data[17] = percentage(data[16]); 
    data[18] = grader(data[17]);
    data[19] = pm(data[17]);
}

int min(int * numbers, int start, int end){
    int  min = 20;
    for(int j = start; j <= end; j++){
        (numbers[j] < min) ? min = numbers[j] : min = min;
    }

    return min;
}



