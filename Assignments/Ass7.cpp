#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

string read(void);
void Outpu(string data);
string grade(double percentage);
int total(string data);
string least(string data, int * max);
string highest(string data, int * maxscore);


int main(){
    string data = read(), line , output, id;
    double percentage = 0.00;
    stringstream ss(data);
    double totalP = 0.00;
    int stdNum = 0, maxScore =0, totalscores = 0;

  while(getline(ss,line,'\n')) {
      stringstream sn;
      int to = total(line);
      double percentage = 100 * static_cast<double>(to) / 400;
      totalscores += to;
      totalP += percentage;




      sn << line <<"   " << to << " " << percentage << " " + grade(percentage) + "\n";

      output.append(sn.str());

      stdNum++;
  }


    Outpu(output);

    cout << "The average total points = "<<  static_cast<double>(totalscores) / stdNum << endl;

    cout << "The average percent total = "<< totalP / stdNum << "%" << endl;

    cout << highest(output, &maxScore)<< endl;
    cout << least(output, &maxScore) << endl;
}

string read(void){
    ifstream file("ass7data.txt");
    string line, data;

    stringstream buffer;

    buffer << file.rdbuf();

    data = buffer.str();

    file.close();

    return data;
}
void Outpu(string data){
  ofstream outputlines;
  outputlines.open("ass7output.txt");

    outputlines << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total  Pct Gr\n";
    outputlines << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- -----  --- ß--\n";
    outputlines << data;
    outputlines.close();
}
string grade(double percentage){
  string grade;

  if(90 <= percentage & percentage <= 100){
            grade = "A";

            if(98 <= percentage){
                grade += "+";
            }

            else if(percentage <= 91){
                grade += "-";
            }

        }

        else if(80 <= percentage & percentage <= 89){

            grade = "B";

            if(88 <= percentage){
                grade += "+";
            }

            else if(percentage <= 81){
                grade += "-";
            }

        }

        else if(70 <= percentage & percentage <= 79){

            grade = "C";

            if(78 <= percentage){
                grade += "+";
            }

            else if(percentage <= 71){
                grade += "-";
            }

        }
        else if(60 <= percentage & percentage <= 69){
            grade = "D";

            if(68 <= percentage){
                grade += "+";
            }

            else if(percentage <= 61){
                grade += "-";
            }

        }

        else if(percentage < 60){
            grade = "F";

        }


  return grade;
}
int total(string data){
  int num, col = 0, total = 0;
  stringstream datastream(data);


  while(datastream >> num){
      if(col > 1)
        total += num;

       col++;
  }

  return total;
}


string least(string data, int * maxscore){
  int low = *maxscore, col =0;
  stringstream ss(data) ,result;
  string line, id;

  while(getline(ss,line,'\n')) {
    stringstream sl(line);
    int num;

    while(sl >> num){
        col++;

        if(col == 16 && num < low){
                low = num;
                ss >> id;
        }

    }
    col = 0;
  }
  result << "ID="<< id << "  Points=" << low << "  Percent=" << 100 * static_cast<double>(low) / 400;

  return result.str();
}

string highest(string data, int * maxscore){
  int max = 0, col = 0;
  stringstream ss(data) ,result;
  string line, id;

  while(getline(ss,line,'\n')) {
    stringstream sl(line);
    int num;

    while(sl >> num){
        col++;

        if(col == 16 && num > max){
                max = num;
                ss >> id;
        }

    }
    col = 0;
  }
  result << "ID="<< id << "  Points=" << max << "  Percent=" << 100 * static_cast<double>(max) / 400;

  *maxscore = max;//to be replaced with something better

  return result.str();





}
