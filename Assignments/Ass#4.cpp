/*
Compiler : CodeBlocks
Assignment #4
Operating System : Win32
Name: Brad
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

string grader(int total);


int main(){
    unsigned short  assignments[11], lab, midterm, final, total = 0 ,a_total = 0, percentage = 0, max = 0, min = 0;
    const short MAX = 400;                      /* - Arrays : arrays are a continuous series of memory allocation. accessed and stored us
    //maximum points available                     - Since the syntax of c arrays and c++ are the same, we can borrow the syntax
                                                    Ex) C++: char str[3];, C: char str[3];
                                                   */

    for(int i = 0; i < 11; i++){
        cout << "Enter assignment " << i + 1 << " points ";
        cin >> assignments[i];
        a_total += assignments[i];

        if(assignments[i] >= max)
        max = assignments[i];
    }//  for loop: a procedure to repeat a task for set amount of number. In this case, the task is input of assignment of scores and total

    min = max;

    for(int i = 0; i < 11; i++){
        if(min >= assignments[i]){
            min = assignments[i];
        }
    }
    a_total -= min;

    cout << "Enter lab exercise points ";
    cin >> lab;

    cout << "Enter midterm points ";
    cin >> midterm;

    cout <<"Enter final points ";
    cin >> final;



    cout << endl << "Assignment Grades:";
    for(int i = 0; i < 11; i++){

        cout << right << setw(4) << assignments[i];

    }

    total = a_total + lab + midterm + final;

    percentage = floor(100 * static_cast<float>(total) / MAX + 0.5);

    cout << endl << "Assignment Points: " << left << setw(2) << a_total;

    cout << endl << "Lab Exercise: " << right << setw(8) << lab;

    cout << endl << "Midterm: " << setw(13) << midterm;

    cout << endl << "Final: " << setw(15) << final;

    cout << endl << "Total Points:" << setw(9) << total;

    cout << endl << "Percent of total:" << right << setw(5) << percentage << "%"<<endl;

    cout << "Grade: " << grader(percentage);
}

string grader(int percentage){
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


