#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main () {
  ofstream randNumList;
  randNumList.open("ex6output.txt");
  string line = "";
  char ch = ' ';



  for(int i = 0; i < 25; i++){
    ch = (char)(rand() % 100 + 50);
    randNumList << ch << endl;
  }

  randNumList.close();


  ifstream filelines("ex6output.txt");

  while(getline(filelines,line)){

    cout << line << endl;
  }

}
