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
float maxClose(double close[], int size);
float avgCLose(double close[], int size);
int main(){
    ifstream ifile("cat.csv");
    ofstream ofile("report.csv");
    data data[1001];
    results result[8];
    

    for(int i = 1000; i > -1; i--){
        load(ifile, &data[i]);
    }

    analysis(data, &result[0], 5);

    cout << result[0].marketDays << "  " << result[0].startDate << "  " << result[0].c_price << "  " << result[0].u_dates
    << "  " << result[0].d_dates << "  " << result[0].gain << "  " << result[0].pct_gain << "  " << result[0].m_close << "  " << result[0].Avg_close; 

}


void load(ifstream &ifile , data * d){
    
    string line, data[7];//line for 
    
    if(ifile.is_open()){
        getline(ifile, line);

        if(line == "Date,Open,High,Low,Close,Adj Close,Volume") return;// omits the line

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

    result -> pct_gain = result -> gain / d[marketDays - 1].prices[3];

    result -> m_close = maxClose(close, marketDays);
    result -> Avg_close = avgClose(close, marketDays);
}
