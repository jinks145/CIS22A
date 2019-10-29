#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int percentage(int total);
string grader(int percentage);
int total(int arr[], int size);
int min(int arr[], int size);
const int MAX = 400;

int main () {
    
    ifstream ifile("ass6data.txt");
    ofstream ofile;
    ofile.open("ass6out.txt");// stored in ass6out.txt
    int  grades[5] = {};
    string grade;

    ofile << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr\n";
    ofile << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- ß--\n";
    if(ifile.is_open()){
        for(int i = 0; i < 50; i++){
        int ID, assignments[11] = {}, scores[6]= {}; // scores[0] == Ass, scores[1] = Mid, scores[2] = Fin, scores[3] = LEx, scores[4] = total, scores[5] = PCT;
    
        ifile >> ID;

        ofile << setfill('0') << setw(8)  << ID << setfill(' ') << " ";// pads 8 digit id && rests them when finished

        scores[0] = 0;
        

        for(int j = 0; j < 11; j++){
        ifile >> assignments[j];
        scores[0] += assignments[j];
        ofile  << right << setw(3) << assignments[j];
        }

        scores[0] -= min(assignments, 11);

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
        grades[static_cast<int>(grade.at(0)) - 65]++;

        ifile.ignore();
        }
        ifile.close();
    
        for(int i = 0; i < 4; i++){
            cout <<  "number of " << static_cast<char>(65 + i) << "'s " << grades[i] << endl; 
        }
    cout <<  "number of " << static_cast<char>(65 + 5) << "'s " << grades[4] << endl;
    }
    else{
        cout <<  "file open failure!";
    }

}

int total(int arr[], int size){
    int total;

    for(int i = 0; i < size; i++){
        total += arr[i];
    }

    return total;
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

int min(int arr[], int size){
    int  min = 20;
    for(int j = 0; j < size; j++){
        (arr[j] < min) ? min = arr[j] : min = min;
    }

    return min;
}