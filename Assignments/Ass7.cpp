#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

/*
Assignment#
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
*/

//implemented functions
void load(ifstream &ifile , int * arr, int size);
void dump(ofstream &ofile, int * arr, int * scores , int size, int size2);
void report(ofstream &ofile, int * arr, int size);
int percentage(int total);// finds percentage from the total calculated
string grader(int percentage);// grade based on percentage
int total(int * arr, int size);// calculates the sum of elements in an array
int max(int * arr, int size);// finds the largest number in the array
int min(int * arr, int size);// finds the smallest number in the array
const int MAX = 400;// the highest score possible as a constant

int main () {
    
    int ID, assignments[11] = {}, scores[6]= {}; // scores[0] == Ass, scores[1] = Mid, scores[2] = Fin, scores[3] = LEx, scores[4] = total, scores[5] = PCT;
    
    string grade;//actual grade
    ifstream ifile("ass7data.txt");//data source
    ofstream ofile("ass7out.txt");// stored in ass6out.txt
    

    
    if(ifile.is_open() && ofile.is_open()){// file open check for both files
        while(!ifile.eof()){//iterates 50 lines of code for 
        ifile >> ID;

        if(ifile.eof()) break;



        scores[0] = 0;


        for(int j = 0; j < 11; j++){
        ifile >> assignments[j];
        ofile  << right << setw(3) << assignments[j];
        }

        scores[0] = total(assignments, 11) - min(assignments, 11);

        for(int j = 1 ; j <= 3; j++){
        ifile >> scores[j];
        }

        scores[4] = total(scores, 4);
        scores[5] = percentage(scores[4]);
        grade = grader(scores[5]);

        ofile << "  " << setw(3) << scores[0] << "  " << setw(3) << scores[1] <<
         "  " << setw(3) << scores[2] << " " << setw(3) << scores[3] << " " <<
             setw(5) << scores[4] << "  " << setw(3) << scores[5];





        ofile << " " << grade << endl;




        }

        ifile.close();
        ofile.close();

        
   

        
    }
    else{//file open failure exits the program
        cout <<  "file open failure!";
        exit(1);
    }

}



int total(int * arr, int size){
    int total = 0;

    for(int i = 0; i < size; i++){
        total += arr[i];
    }

    return total;
}

void load(ifstream &ifile , int * arr, int size){
    if(ifile.is_open()){
        for(int i = 0; i < size; i++){
            ifile >> arr[i];

            if(ifile.eof()){
                return;
            }

        }
    }
    else{
        cout << "file open failure" << endl;
        exit(1);
    }
}

void dump(ofstream &ofile, int * arr, int * scores , int size, int size2){
    
    
    if(ofile.is_open()){
        ofile << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr" << endl;
        ofile << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- --" << endl;

        ofile << setfill('0') << setw(8)  << arr[0] << setfill(' ') << " ";// pads 8 digit id with leading 0s && resets them when finished


    }
    else{
        cout << "file open failure" << endl;
        exit(1);
    }

}
void report(ofstream &ofile, string * data){
    
    
            
            ofile <<  "Number of students = " << data[0] << endl;
            ofile <<  "The average total points = " << data[1] << endl;
            ofile <<  "The average percent total = " << data[2] << endl;
            ofile <<  "Highest Grade: " << data[3] << endl;
            ofile << "Lowest Grade: " << data[4] << endl;
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
