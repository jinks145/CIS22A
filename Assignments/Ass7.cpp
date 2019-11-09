/*
Assignment#7
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
Note: Load, dump and report functions perform file open checks && for end of file.
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
};//for storing student information

struct stats{
    student highest, lowest;
    float avg, avg_pct;
    int students;
};//for storing final report stats

//implemented functions
void load(ifstream &ifile, student * students, int size);// loads file
void dump(ofstream &ofile, student students[], int size); //dumps data that was calculated from the loaded data
void reported(ofstream &ofile, stats report);// writes them to the file
float percentage(int total);// finds percentage from the total calculated
string grader(int percentage);// grade based on percentage
int total(int * arr, int start, int end);// calculates the sum of elements from star to end inclusively in an array
void analysis(student * students, stats &report, int size);// calculates stats
int min(int * arr, int size);// finds the smallest number in the array
const int MAX = 400;// the highest score possible as a constant

int main () {
    
    student students[53];// 53 students
    stats report = {{}, {{}, {}, 0, MAX, 100, "" , 0}, 0.0, 0.0, 0};// report initialization
    ifstream ifile("ass7data.txt");//data source
    ofstream ofile("ass7out.txt");// stored in ass7out.txt
    

    load(ifile, students , 53);
    analysis(students, report, 53);// where
    dump(ofile, students, 53);
    reported(ofile, report);
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

            if(ifile.eof()) break;

            for(int j = 0; j < sizeof(students[0].a_points)/ sizeof(int); j++){
                ifile >> students[i].a_points[j];
            }

            for(int j = 0; j < sizeof(students[0].scores)/ sizeof(int); j++){
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

void analysis(student * students, stats  &report, int size){
    for(int i = 0; i < size; i ++){
        students[i].a_total = total(students[i].a_points, 0, 10) - min(students[i].a_points, 11);
        students[i].total = total(students[i].scores, 0,2) + students[i].a_total;
        students[i].pct = percentage(students[i].total);
        students[i].grade = grader(static_cast<int>(students[i].pct +0.5));

        if(report.highest.total < students[i].total){
            report.highest = students[i];
        }
        else if(report.lowest.total > students[i].total){
            report.lowest = students[i];
        }
            report.avg += students[i].total;
            report.avg_pct += students[i].pct;
            report.students++;//student count goes up
    }       // student's avg point && report points
            (report.avg) /= (report.students);
            (report.avg_pct) /= (report.students);

}

void dump(ofstream &ofile, student students[], int size){
        if(ofile.is_open()){
            ofile << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr" << endl;
        ofile << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- --" << endl;

            for(int i = 0; i < size; i++){
                ofile << setfill('0') << setw(8) << students[i].id << setfill(' ') << "  ";

            for(int j = 0; j < 11; j++){
                ofile << setw(2) << students[i].a_points[j] << " ";
                }

            ofile << ' ' << setw(3) << students[i].a_total << "  ";

            
                ofile << setw(3) << students[i].scores[0] << "  ";
            
                ofile << setw(3) << students[i].scores[1] << " ";
                ofile << setw(3) << students[i].scores[2] << " ";

            ofile << setw(5) << students[i].total << "  ";
            ofile << setw(3) <<static_cast<int>(percentage(students[i].total) + 0.5) << ' ';
            ofile << students[i].grade << endl; 
            }
            
        }
        
        else{
        cerr <<  "file open failure!";
        exit(1);
    }

}

void reported(ofstream &ofile, stats report){
    
    if(ofile.is_open()){
       ofile << "\n\nNumber of students = " << report.students << endl;
       ofile << "The average total points = " << fixed << setprecision(1) << report.avg << endl;
       ofile << "The average percent total = " << fixed << setprecision(1) << report.avg_pct << "%" << endl;
       ofile << "Highest grade: Id=" << report.highest.id << "  Points=" << report.highest.total << "  Percent="<< fixed << setprecision(1)  << report.highest.pct << "%" << endl;
       ofile << "Lowest grade: Id=" << report.lowest.id << "  Points=" << report.lowest.total << "  Percent=" << fixed << setprecision(1) << report.lowest.pct << "%" << endl; 
        ofile.close();
    }
    else{
        cerr << "file open failure";
        exit(1);
    }
}

float percentage(int total){
    return 100 * static_cast<float>(total) / MAX;
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

