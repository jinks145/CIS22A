#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int a_points, e_points, m_points, f_points, c_points, total = 0;
    string f_name, l_name;
    double percent = 0.0;

    cout << "Enter your first name => ";
    cin >> f_name;

    cout << "Enter your last name => ";
    cin >> l_name;

    cout << "Enter the total assignment points => ";
    cin >> a_points;

    cout << "Enter the total exercise points => ";
    cin >> e_points;

    cout << "Enter the midterm points => ";
    cin >> m_points;

    cout << "Enter the final points => ";
    cin >> f_points;

    cout << "Enter the CodeLab points => ";
    cin >> c_points;

    cout << "\n" << f_name << " " << l_name << " 's grade points\n";

    cout << "Assignments: " << a_points <<endl;
    cout << "Exercises:   " << e_points <<endl;
    cout << "Midterm:     " << m_points <<endl;
    cout << "Final:       " << f_points <<endl;
    cout << "CodeLab:     " << c_points <<endl;

    cout << "             ---" <<endl;

    total = a_points + e_points + m_points + f_points + c_points;
    cout << "Total:       "<< total <<endl;
    percent = (double) total / 400;
    printf("Percent:     %0.2f", percent);
}
