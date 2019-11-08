/*
Assignment#7
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
Note: Please note that load, dump and report functions perform file open checks.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct student{
    int a_points[11], scores[3],  a_total, total;
    float pct;
    string grade;
    int id;
};

struct stats{
    student highest, lowest;
    float avg;
    int students;
};

//implemented functions
void load(ifstream &ifile, student * students, int size);// loads file
void dump(ofstream &ofile, student students[], int size); //dumps data that was calculated from the loaded data
void report(ofstream &ofile, stats report, int * ID);// writes them to the file
int percentage(int total);// finds percentage from the total calculated
string grader(int percentage);// grade based on percentage
int total(int * arr, int start, int end);// calculates the sum of elements in an array
int max(int * arr, int size);// finds the largest number in the array
int min(int * arr, int size);// finds the smallest number in the array
const int MAX = 400;// the highest score possible as a constant

int main () {
    
    
    ifstream ifile("ass7data.txt");//data source
    ofstream ofile("ass7out.txt");// stored in ass6out.txt
    

    
   
    

}



int total(int * arr, int start, int end){
    int total = 0;

    for(int i = start; i <= end; i++){
        total += arr[i];
    }

    return total;
}

void load(ifstream &ifile, student * students, int size){
    
    if(ifile.is_open()){

        for(int i = 0; i < size; i++){
            ifile >> students[i].id;
            
            for(int j = 0; j < sizeof(students[0].a_points)/ sizeof(int); j++){
                ifile >> students[i].a_points[j];
            }

            for(int j = 0; sizeof(students[0].scores)/ sizeof(int); j++){
                ifile >> students[i].scores[j];
            }
            
        }
        ifile.close();
    }
    else{
        cerr <<  "file open failure!";
        exit(1);
    }

    

}

void dump(ofstream &ofile, student students[], int size){
        if(ofile.is_open){
            ofile << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr" << endl;
        ofile << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- --" << endl;

            for(int i = 0; i < size; i++){
                ofile << setw(8) << students[i].id << "  ";

            for(int j = 0; j < 11; j++){
                ofile << setw(2) << students[i].a_points[j] << " ";
                }

            ofile << ' ' << setw(3) << students[i].a_total << "  ";

            for(int j = 0 ; j < 3; j++){
                ofile << setw(3) << students[i].scores[j] << ' ';
            }

            ofile << setw(5) << students[i].total << "  ";
            ofile << setw(3) << percentage(students[i].total) << ' ';
            ofile << students[i].grade << endl; 
            }
            ofile.close();
        }
        
        else{
        cerr <<  "file open failure!";
        exit(1);
    }

}

int percentage(int total){
    return floor(100 * static_cast<float>(total) / MAX + 0.5);
}


string grader(int percentage){
    string grade = "";

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


    return grade;
}

int min(int * arr, int size){
    int  min = 20;
    for(int j = 0; j < size; j++){
        (arr[j] < min) ? min = arr[j] : min = min;
    }

    return min;
}
