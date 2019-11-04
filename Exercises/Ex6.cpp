#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

/*
Name : Brad
Exercise : Lab Exercise #6
Compiler used : Code::Blocks on a PC
Completed at : ATC Lab
*/

int main () {
  ofstream randNumList;
  randNumList.open("ex6output.txt");
  char ch = ' ';

  srand(time(0));


  for(int i = 0; i < 25; i++){
    ch = static_cast<char>(rand() % 51 + 50);
    randNumList << ch << endl;
  }

  randNumList.close();


  ifstream filelines("ex6output.txt");

  while(filelines.get(ch)){

    cout << ch ;
  }

}
