#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
const string p_date = "01/02/19",s_ticker = "WMT";
const int inv_amt = 10000, shareNum = 143;
string s_date;
double b_price, s_price, gain = 0.0;

    cout << "Enter the purchase price => ";
    cin >> b_price;

    cout << "Enter the sell date (mm/dd/yy) => ";
    cin >> s_date;

    cout << "Enter the sell price => ";
    cin >> s_price;


    cout << "\nStock Ticker: " << s_ticker << " \n" << endl;

    cout << "Purchase Date: " << p_date << endl;
    printf("Purchase Price: $%0.2f\n", b_price);
    cout << "Number of Shares Purchased: " << shareNum << "\n\n";

    cout << "Sell Date: " << s_date << endl;
    printf("Sell Price: $%0.2f\n", s_price);
    printf("Value of Shares Sold: $%0.2f\n\n", s_price * shareNum);

    gain = s_price * shareNum + (inv_amt - b_price * shareNum) - inv_amt;

    printf("Gain: $%0.2f\n", gain);
    cout << "Percent Gain: "<< gain / inv_amt << "%";
}
