/*
Assignment#11
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

void load(ifstream &ifile, string * arr, int size = 20000);
bool search(string arr[], string ID, int lo, int high);
void selectionSort(string a[], int size = 20000);
int lexcomp(string a, string b);
void reverse(string * arr, int size);


int main(){
    string words[2][20000];
    ifstream dict("unsorted_dictionary.txt"), keywords("keywords.txt");
    ofstream ofile("notfound.txt");
    int ne_c = 0;

    
    

    load(dict, words[0]);
    load(keywords, words[1], 84);

    selectionSort(words[0]);
    selectionSort(words[1], 84);

    for(int i = 0; i < 84; i++){
        if(!search(words[0], words[1][i], 0, 19999)){
            ofile << "keyword not found: " << words[1][i];
            ne_c++;
        }
    }

    cout << "Number of keywords not found = " << ne_c;
}

void load(ifstream &ifile, string * arr, int size){
   
    if(ifile.is_open()){
        
        for(int i = 0; i < size; i++){
         getline(ifile, arr[i]);
        }

    }
    
    
}

void dump(){

}

int lexcomp(string a, string b){

    int size = (a.length() < b.length()) ? a.length() : b.length();
    
    
    for(int i = 0; i < size; i++){
        if(a[i] < b[i]){
            return 1;
        }
        else if(a[i] > b[i]){
            return -1;// if a comes later than b
        }
    }

    
    

    return 0;
}

void selectionSort(string * a, int size){
    int lowest = 0;    
    string tmp;
    for(int i = 0; i < size; i++){
        if(lexcomp(a[lowest], a[i]) < 0){
            lowest = i;
        }
    }

    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            if(lexcomp(a[lowest], a[j]) > 0){
                lowest = j;
            }
            
        }

        tmp = a[lowest];
        a[lowest] = a[i];
        a[i] = tmp;
    }

    reverse(a, size);
}

void reverse(string * arr, int size){
    
    for(int i = 0; i < size/2; i++){
        string tmp = arr[size -1 - i];
        arr[size -1 - i] = arr[i];
        arr[i] = tmp;
    }
}

bool search(string arr[], string ID, int lo, int high){
    int pivot = (lo + high) / 2;
    if(lo <= pivot && pivot <= high){
        if(lexcomp(arr[pivot], ID) == 0){
            return true;
        }
    
        else if( lexcomp(arr[pivot], ID) > 0){
        return search(arr, ID, lo, --pivot);
        }

        else if(lexcomp(arr[pivot], ID) < 0){
        return search(arr, ID, ++pivot, high);
        }
    }
    
    return false;

    
}
