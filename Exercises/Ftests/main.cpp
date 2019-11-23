/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

char grader(int percentage) { // grader from Assignment #4
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

int main(){
    
        cout << static_cast<char>(grader(58)) << endl;
        cout << static_cast<char>(grader(64)) << endl;
        cout << static_cast<char>(grader(75)) << endl;
        cout << static_cast<char>(grader(85)) << endl;
        cout << static_cast<char>(grader(95)) << endl;
        cout << static_cast<char>(grader(100)) << endl;
    
}

