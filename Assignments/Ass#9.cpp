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
int grader(int percentage);//grader
void compute(int  data[], int size);//compute data in a array
void dump(ifstream &loader, ofstream &dumper, int  data[], bool &first);// dumps into a file && checks for loader's eof at the end 
int min(int numbers[], int start, int end);// finds the smallest element of the arr
int pm(int percentage);// determine the suffix


int main(){
    ifstream loader("ass7data.txt");
    ofstream dumper("ass9output.txt");
    bool first = true;
    int data[20] ={};
    
    dumper << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr\n";// headings
    dumper << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- --\n";
    while(!loader.eof()){//one student record at a time
        
       

        load(loader, data, 16);// loads them into array

         if(loader.eof()){// eof check
            break;
        }

        compute(data, 20);// calculates the fa

        dump(loader, dumper, data, first);//dumps them to ass9output.txt   
    }
    
    loader.close();
    dumper.close();
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


void dump(ifstream &loader, ofstream & dumper, int data[], bool &first) { //dumps data to the desired file
  string grade;
  if (dumper.is_open()) {
    if(!first) dumper << endl;
    else{
      first = false;
    }

    dumper << right << setw(8) << setfill('0') << data[0] << " " << setfill(' '); // print id

    for (int i = 1; i < 15; i++) {
      if (i < 12)
        dumper << " " << setw(2) << data[i]; // print assignment scores
      else
        dumper << "  " << setw(3) << data[i]; // print assignment total and midterms, finals, lab ex 

    }

    dumper << " " << setw(3) << data[15] << " " << setw(5) << data[16] << "  " << setw(3) << data[17];
    //print total and percentage
    dumper << ' ' << static_cast < char > (data[18]) << static_cast < char > (data[19]); // set grade


      

      

   
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
  char grade[] = {'A' , 'B', 'C', 'D', 'F'};
  int index;
  
  if(percentage / 10 >= 9){
      index = 0;
  }
  else if(percentage /10 > 5){

      index = 10 - percentage /10 - 1;
      
  }
  else {
    index = 4;
  }


  return grade[index];
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