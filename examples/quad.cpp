#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;

int main(){
  double a, x2, b, c;
  string eq;

  cout << "Enter Equation : ";
  getline(cin,eq);
  stringstream ss(eq);

  ss >> a >> x2 >> b >> c;

  cout << setprecision(2) << a << " " << b << " " << c << endl;

  cout << "x = " << setprecision(2) <<( -b + sqrt(pow(b , 2.0) - 4 * a * c))/(2 * a) << ( -b + sqrt(pow(b , 2.0) - 4 * a * c))/(2 * a)  << '\n';
}
