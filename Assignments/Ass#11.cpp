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
void selectionSort(string  a[], int size = 20000);
void qsort(string  a[], int lo = 0, int hi = 20000 - 1);
int partition(string arr[],int lo, int hi);
int lexcomp(string a, string b);



int main(){
    string words[2][20000];
    ifstream dict("unsorted_dictionary.txt"), keywords("keywords.txt");
    ofstream ofile("notfound.txt");
    int ne_c = 0;

    
    

    load(dict, words[0]);
    load(keywords, words[1], 84);

    // qsort(words[0], 0);
    // qsort(words[1], 0, 84);
     selectionSort(words[0]);
     selectionSort(words[1], 84);

    if(ofile.is_open()){
        for(int i = 0; i < 84; i++){
            
            if(!search(words[0], words[1][i], 0, 19999)){
                ofile << "keyword not found: " << words[1][i] << endl;
                ne_c++;
            }

        }
    }
    

    cout << "Number of keywords not found = " << ne_c;
}

void load(ifstream &ifile, string * arr, int size){
   
    if(ifile.is_open()){
        
        for(int i = 0; i < size && !ifile.eof(); i++){
         getline(ifile, arr[i]);
        }

    }
    
    
}

int partition(string arr[],int lo, int hi){
    string pivot = arr[hi];
    string tmp;
    int i = lo - 1;

    for(int j = lo; j < hi; j++){
        if(lexcomp(arr[j], pivot) < 0){
            i++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
            


            tmp = arr[i+1];
            arr[i+1] = arr[hi];
            arr[hi] = tmp;

    return i+1;
}

void qsort(string arr[], int lo, int hi){
   
   if(lo < hi){
        int pi = partition(arr, lo, hi);

        qsort(arr, lo, pi - 1);
       
        qsort(arr, pi + 1, hi);
   }

}

int lexcomp(string a, string b){// a is the pivot for comparison
    
        int size = (a.length() >= b.length()) ? a.length() : b.length();

        for(int i = 0; i < size; i++){
            if(a[i] < b[i]){//if a is earlier than b
                return -1;
            }
        else if(a[i] > b[i]){// if a comes later than b
            return 1;// if a comes later than b
            }
        }
    
    if(b.length() == size){
        return 0;
    }
    else if(a.find(b)){
        return 1;
    }
    else if (b.find(a))
    {
        return -1;
    }
    
}

void selectionSort(string a[], int size){
    int lowest = 0;    
    string tmp;
    

    for(int i = 0; i < size - 1; i++){
        lowest = i;
        for(int j = i + 1; j < size; j++){
            if(lexcomp(a[j], a[lowest]) < 0){
                lowest = j;
            }
            
        }
        tmp = a[lowest];
        a[lowest] = a[i];
        a[i] = tmp;
    }

}

bool search(string arr[], string ID, int lo, int high){
    int pivot = (lo + high) / 2;
    if(lo <= pivot && pivot <= high){
        if(lexcomp(arr[pivot], ID) == 0){
            return true;
        }
    
        else if( lexcomp(ID, arr[pivot]) < 0){
        return search(arr, ID, lo, --pivot);
        }

        else if(lexcomp(ID, arr[pivot]) > 0){
        return search(arr, ID, ++pivot, high);
        }

        
    }
    else{
            return false;
    }
    
}
