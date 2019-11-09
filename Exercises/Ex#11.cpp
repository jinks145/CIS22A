/*
Name: Jooho Jeong
Exercise: Lab Exercise #11
Compiler used : Code::Blocks on a PC
Completed at : ATC Lab
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

const int s_size = 50;

int load(ifstream &ifile, int * arr, int size);//load
int sort(int * arr, int lo, int high);//quicksort
bool search(int * arr, string ID, int lo, int high);//performs a binary search
void print(int * arr, int size);//prints the first 5 and the last 5 elements 

int main(){

    ifstream ifile("ass6data.txt");
    string ID;
    int IDs[50];

    if(ifile.is_open()){
        load(ifile, IDs, s_size);
    }
    sort(IDs, 0, 7);

    print(IDs, s_size);

    while(true){
        cout << "Enter a student ID to search for. (0 to exit) ";
        getline(cin,ID);
        if(ID == "0"){
            break;
        }
        cout << search(IDs, ID, 0 , s_size - 1);
    }
}

int load(ifstream &ifile, int * arr, int size){
   
    for(int i = 0; i < size; i++){
         ifile >> arr[i];
         ifile.ignore(44, '\n');
    }
}

int sort(int * arr, int lo, int high){

}

bool search(int  arr[], string ID, int lo, int high){
    int pivot = (lo + high) / 2;
    if(lo <= pivot && pivot <= high){
        if(arr[pivot] == atoi(ID.c_str())){
            return true;
        }
    
        else if( atoi(ID.c_str()) < arr[pivot]){
        return search(arr, ID, lo, --pivot);
        }

        else if(atoi(ID.c_str()) > arr[pivot]){
        return search(arr, ID, ++pivot, high);
        }
    }
    
    return false;

    
}

void print(int * arr, int size){
    
    for(int i = 0; i < 5; i++){
        cout << arr[i] <<endl;
    }

    for(int i = size - 5; i < size; i++){
        cout << arr[i] <<endl;
    }
}