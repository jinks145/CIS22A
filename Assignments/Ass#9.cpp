/*

Assignment#9
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
*/
#include <iostream>

#include <cstdlib>

#include <iomanip>

#include <fstream>

#include <cmath>

#include <string>

using namespace std;

const int MAX = 400;// max points
void load(ifstream &loader, int data[], const int size);// loads a student record
int total(int numbers[], int start, int end);// total of array's section
int percentage(int total);//percentage
int grader(string data, int percentage);//grader
void compute(int  data[], int size);//compute data in a array
void dump(ifstream &loader, ofstream &dumper, int  data[]);// dumps into a file && checks for loader's eof at the end 
int min(int numbers[], int start, int end);// finds the smallest element of the arr
int pm(int percentage);// determine the suffix


int main(){
    ifstream loader("ass7data.txt");
    ofstream dumper("ass9output.txt");
    
    
    dumper << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr\n";// headings
    dumper << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- --\n";
    while(!loader.eof()){//one student record at a time
        int data[20] ={};
        
        load(loader, data, 16);// loads them into array

        

        compute(data, 20);// calculates the fa

        dump(loader, dumper, data);//dumps them to ass9output.txt

      
    }

}

void load(ifstream &loader, int data[], const int size){//loads data from file
    
    if(loader.is_open()){

    for(int i = 0; i < 12; i++){// from id to 11 assignments
            
            loader >> data[i];
         
        }

    for(int i = 13; i < size; i++){
        loader >> data[i];// load array with data in the order of midterm, finals, lab exercise
        }

    data[12] = 0;//set assignment total to 0
    data[16] = 0;//set total to 0;
    
    }

    else{
        cerr << "file open failure!!";
        exit(1);
    }
    
    
}


void dump(ifstream &loader, ofstream & dumper, int data[]) { //dumps data to the desired file
  string grade;
  if (dumper.is_open()) {
    dumper << right << setw(8) << setfill('0') << data[0] << " " << setfill(' '); // print id

    for (int i = 1; i < 15; i++) {
      if (i < 12)
        dumper << " " << setw(2) << data[i]; // print assignment scores
      else
        dumper << "  " << setw(3) << data[i]; // print assignment total and midterms, finals, lab ex 

    }

    dumper << " " << setw(3) << data[15] << " " << setw(5) << data[16] << "  " << setw(3) << data[17];
    //print total and percentage
    grade += static_cast < char > (data[18]); // set grade

    if (static_cast < char > (data[19]) == ' ') {
      dumper << " " << left << setw(3) << static_cast < char > (data[18]);
    } else {
      grade += static_cast < char > (data[19]); // add suffix
      dumper << " " << left << setw(3) << grade; // print grade
    }
  


        if(loader.eof() || data[0] == '\n'){// eof check
            return;
        }
        else{
          dumper << endl;
        }
   

   
  }
   else {
    cerr << "file open failure!!";
    exit(1);
    }

  }



int total(int numbers[], int start, int end) { // calculates total from start index to end index
  int sum = 0;

  for (int i = start; i <= end; i++) {
    sum += numbers[i];
  }

  return sum;
}

int percentage(int total) { // calculates percentage
  return floor(100 * static_cast < float > (total) / MAX + 0.5);
}

int grader(int percentage) { // grader from Assignment #4
  char grade;

  switch (percentage / 10) {
    case 10:
      grade = 'A';
      break;
    case 9:
      grade = 'A';
      break;

    case 8:
      grade = 'B';
      break;

    case 7:
      grade = 'C';
      break;

    case 6:
      grade = 'D';
      break;

    default:
      grade = 'F';
  }

  return grade;
}

int pm(int percentage) {
  char sign = ' ';
  if (percentage / 10 > 5 && percentage != 100) {
    if (percentage % 10 < 2) {
      sign = '-';
    } else if (percentage % 10 > 7) {
      sign = '+';
    }

  } else if (percentage == 100) {
    sign = '+';
  }

  return sign;
}

void compute(int data[], int size) {
  data[12] = total(data, 1, 11) - min(data, 1, 11);
  data[16] = total(data, 12, 15);

  data[17] = percentage(data[16]);
  data[18] = grader(data[17]);
  data[19] = pm(data[17]);
}

int min(int numbers[], int start, int end) {
  int min = 20;
  for (int j = start; j <= end; j++) {
    (numbers[j] < min) ? min = numbers[j]: min = min;
  }

  return min;
}