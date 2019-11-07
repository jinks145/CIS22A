/*
Assignment#8
Compiler : CodeBlocks
Operating System : Win32
Name: Brad
*/

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <locale> 
using namespace std;

struct data{
    string date;
    double prices[5];
    int volume;
};

struct results{
    string startDate;
    float c_price,gain, pct_gain, m_close, Avg_close; 
    int marketDays, u_dates, d_dates;
};

void load(ifstream &ifile, data * d);
void analysis(data data[], results * result, int d_size);
string toUpperStr(string str);
void dump(ofstream &ofile, data current , results * result, int r_size, string ticker);
float maxClose(double close[], int size);
float avgCLose(double close[], int size);
int main(){
    
    string filename , ticker, r_file;
    data data[1001];
    results result[8];
    const int marketDays[8] = { 5, 10, 20, 50, 100, 200, 500, 1000};


    cout << "~~~Dow Jones Analyzer~~~~\nDJIA Record Please: ";
    getline(cin, filename);

    ifstream ifile(filename.c_str());
    
    
    int lastdot = filename.find_last_of(".");
    ticker = filename.substr(0, lastdot);
    r_file = ticker + ".txt";
    ofstream ofile(r_file.c_str());
    if(filename.length() == 0){
        cout << "Thank You for using Dow Jones Analyzer";
        exit(1);
    }

    else if (!ifile){
        cout << "Error 404: Cannot open File";
        exit(1);
    }
    
    else{
        for(int i = 1000; i > -1; i--){
        load(ifile, &data[i]);
        }

        for(int i = 0; i < 8; i++){
        analysis(data, &result[i], marketDays[i]);
        }

        

        dump(ofile, data[0], result, 8, toUpperStr(ticker));

        
    }
    ifile.close();
    ofile.close();

    cout << "finished analyzing";
    
    
}

string toUpperStr(string str){
    string upped = " ";
    for(int i = 0; i < str.length(); i++){
        upped += toupper(str.at(i));
    }

    return upped;
}

void load(ifstream &ifile , data * d){
    
    string line, data[7];//line for 
    
    if(ifile.is_open()){
        getline(ifile, line);

        if(line == "Date,Open,High,Low,Close,Adj Close,Volume" || ifile.eof()) return;// omits the line

        stringstream ss(line);

            

            for(int i = 0; i < 7; i++){
                getline(ss , data[i], ',');
            }

        d-> date = data[0];

        for(int i = 1; i <= sizeof(d-> prices)/sizeof(double); i++){
            
            d -> prices[i - 1] = atof(data[i].c_str());

        }

        d->volume = atoi(data[6].c_str());

    }
    else{
        cout << "file open failure" << endl;
        exit(1);
    }
}

float maxClose(double close[], int size){
    float max = 0.0;
    for(int i = 0; i < size; i++){
        if(close[i] > max)
        max = close[i];
    }

    return max;
}

float avgClose(double close[], int size){
    float avg = 0.0;

    for(int i = 0; i < size; i++){
        avg += close[i];
    }

    return avg / size;
}


void analysis(data d[], results * result, int marketDays){
    double close[marketDays];
    int down = 0, up = 0;
    data current = d[0];
    result->marketDays = marketDays;
    
    for(int i = 0; i < marketDays; i++){
        if(d[i].prices[0] > d[i].prices[3]){
            down++;
        }

        else if(d[i].prices[0] < d[i].prices[3]){
            up++;
        }
        close[i] = d[i].prices[3];
    }
    result ->u_dates = up;
    result ->d_dates = down;
    result -> c_price = d[marketDays - 1].prices[3];
    result -> startDate = d[marketDays - 1].date;
    result -> gain = current.prices[3] - d[marketDays - 1].prices[3];

    result -> pct_gain = result -> gain / d[marketDays - 1].prices[3] * 100.00f;

    result -> m_close = maxClose(close, marketDays);
    result -> Avg_close = avgClose(close, marketDays);
}

void dump(ofstream &ofile, data current , results * result, int r_size, string ticker){
    if(ofile.is_open()){
    
    ofile << "Stock:  " << ticker << endl;
    ofile << "Current Date: "  << current.date << endl;
    ofile << "Current Close:  " << showpoint << fixed  << setprecision(2)<< current.prices[3] << endl;
    ofile << "Market Days  Start Date  Close Price  Up Days  Down Days   Gain  Pct Gain  Max Close  Avg Close" << endl;
    ofile << "-----------  ----------  -----------  -------  ---------   ----  --------  ---------  ---------" << endl;

        for(int i = 0; i < r_size; i++){
            ofile << setw(11) << result[i].marketDays << "  ";
            ofile << result[i].startDate << setw(4) << "  ";
            ofile << setw(6) <<showpoint << fixed  << setprecision(2) << result[i].c_price << setw(4) << "  ";
            ofile << setw(5) << result[i].u_dates << setw(3) << "  ";
            ofile << setw(6) << result[i].d_dates << setw(7);
            
            ofile << setw(12) << showpoint << fixed  << setprecision(2) << result[i].gain;
            ofile << setw(9) << result[i].pct_gain << "%  ";
            
            ofile << setw(9) << result[i].m_close << "  ";
            ofile << setw(9) << result[i].Avg_close << endl;
        }

    }
    else{
        cerr << "file open failure";
        exit(1);
    }
}
