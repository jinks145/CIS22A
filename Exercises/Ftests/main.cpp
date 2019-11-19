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

int partition(int arr[],int lo, int hi){
    int pivot = arr[hi];
    int tmp;
    int i = lo - 1;

    for(int j = lo; j <= hi - 1; j++){
        if(arr[j] < pivot){
            i++;
            tmp = arr[j];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

            tmp = arr[i+1];
            arr[i+1] = arr[hi];
            arr[hi] = tmp;

    return i+1;
}

void qsort(int arr[], int lo, int hi){
   
   if(lo < hi){
        int pi = partition(arr, lo, hi);

        qsort(arr, lo, pi - 1);
       
        qsort(arr, pi + 1, hi);
   }

}



int main()
{
    //ifstream ifile("ass6data.txt");
    int IDs[7] = {10, 80, 30, 90, 40, 50, 70};

    qsort(IDs, 0, 6);

    for(int i = 0; i < 7; i++){
        cout << IDs[i] << ", ";
    }
}

