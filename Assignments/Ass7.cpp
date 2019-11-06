#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

/*
Assignment#7
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
Note: Please note that load, dump and report functions perform file open checks.
*/

//implemented functions
void load(ifstream &ifile , int * arr, int start, int end);// loads file
void dump(int ID, ofstream &ofile, int * arr, int * scores , int size);//dumps data that was calculated from the loaded data
void report(ofstream &ofile, float * stats, int * ID);// writes them to the file
int percentage(int total);// finds percentage from the total calculated
string grader(int percentage);// grade based on percentage
int total(int * arr, int start, int end);// calculates the sum of elements in an array
int max(int * arr, int size);// finds the largest number in the array
int min(int * arr, int size);// finds the smallest number in the array
const int MAX = 400;// the highest score possible as a constant

int main () {
    
    int ID[3] = {},  assignments[11] = {}, scores[6]= {};//ID[] stores ids
    // scores[0] == Ass, scores[1] = Mid, scores[2] = Fin, scores[3] = LEx, scores[4] = total, scores[5] = PCT;
    float stats[7] ={0,0,0,0,0,400.0,100.0};
    // stats[0]= student number, stats[1]=  avg points, stats[2] = avg total, stats[3]=  h_points, stats[4]=  h_pct , stats[5]=  l_points, stats[6]=  l_pct}
    string grade;//actual grade
    ifstream ifile("ass7data.txt");//data source
    ofstream ofile("ass7out.txt");// stored in ass6out.txt
    

    
   
    if(ifile.bad() || ofile.bad()){//file open failure exits the program
        cerr <<  "file open failure!";
        exit(1);
    }else{
        ofile << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr" << endl;
        ofile << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- --" << endl;

        while(!ifile.eof()){
            ifile >> ID[0];
            if(ifile.eof()) break;


        load(ifile, assignments, 0 , 10);

        scores[0] = total(assignments, 0 ,10) - min(assignments, 11);
        load(ifile, scores, 1, 3);
        scores[4] = total(scores, 0, 3);        
        scores[5] = percentage(scores[4]);

        dump(ID[0], ofile, assignments, scores, 11);

        if(stats[3] < scores[4]){
                ID[1] = ID[0];
                stats[3] = scores[4];
                stats[4] = scores[5];
        }

        if(stats[5] > scores[4]){
                ID[2] = ID[0];
                stats[5] = scores[4];
                stats[6] = scores[5];
        }

        


        stats[1] += scores[4];
        stats[2] += scores[5];
        stats[0]++;
        
        }

        report(ofile, stats, ID);

        
        ifile.close();
        ofile.close();
    }

}



int total(int * arr, int start, int end){
    int total = 0;

    for(int i = start; i <= end; i++){
        total += arr[i];
    }

    return total;
}

void load(ifstream &ifile , int * arr, int start, int end){
    if(ifile.is_open()){
        for(int i = start; i <= end; i++){
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

void dump(int ID, ofstream &ofile, int * arr, int * scores , int size){
    
    
    if(ofile.is_open()){
        

        ofile << setfill('0') << right << setw(8)  << ID << setfill(' ') << " ";// pads 8 digit id with leading 0s && resets them when finished


        for(int i = 0; i  < size; i++){
            ofile << setw(3) << arr[i];
        }
        
        

        for(int j = 0; j < 3; j++){
            ofile << setw(5) << scores[j];
        }

        ofile << setw(4) << scores[3];

        ofile << setw(6) << scores[4] << setw(5) << scores[5] << left << setw(3) <<" " + grader(scores[5]) << endl;

    }
    else{
        cout << "file open failure" << endl;
        exit(1);
    }

}
void report(ofstream &ofile, float * stats, int * ID){
    
    if(ofile.is_open()){

            ofile <<  "\n\nNumber of students = " << stats[0] << endl;
            ofile <<  "The average total points = " << fixed << setprecision(1) << stats[1] / stats[0] << endl;
            ofile <<  "The average percent total = " << fixed << setprecision(1) << stats[2] / stats[0] << "%" << endl;
            ofile <<  "Highest Grade: " <<" Id=" << setw(8) << ID[1] <<"  Points="<< static_cast<int>(stats[3]) <<"  Percent=" << stats[4] << "%" << endl;
            ofile << "Lowest Grade: " << " Id=" << setw(8) << ID[2] << "  Points=" << static_cast<int>(stats[5]) << "  Percent=" << stats[6] <<"%" << endl;
    }
    else{
        cerr << "file open failure" << endl;
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
