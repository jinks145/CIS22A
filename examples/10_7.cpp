#include <iostream>
using namespace std;

int main(){
float i_sum = 0.00;
int mean = 0;
i_sum = 1/static_cast<float>(2) + 1/static_cast<float>(3) + 1/static_cast<float>(5) + 1/static_cast<float>(7) + 1/static_cast<float>(11);
mean = static_cast<int>(1/i_sum) /5 ;

cout << i_sum;

}
