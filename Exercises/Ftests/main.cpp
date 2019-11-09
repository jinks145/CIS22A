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


int load(ifstream &ifile, int * arr, int size){
   
    for(int i = 0; i < size; i++){
         ifile >> arr[i];
         ifile.ignore(44, '\n');
    }
}


int main()
{
    ifstream ifile("ass6data.txt");
    int IDs[50];

    load( ifile,IDs, 50);

    for(int i = 0; i < 50; i++){
        cout << IDs[i] << endl; 
    }
}

