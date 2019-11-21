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


bool isPrime(int n){
    for(int i = 2; i < n ; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int findPrime(int num){
    int half = num /2;
    for(int i = half ; i > 1; i--){
        if(isPrime(i)){
            return i;
        }
    }
    return 0;
}

int main(){
    cout << "for 13: "<< boolalpha << (findPrime(13) == 5) << endl;
    cout << "for 25: "<< boolalpha <<  (findPrime(25) == 11) << endl;
    cout << "for 55: "<< boolalpha <<  (findPrime(55) == 23) << endl;
}

