#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
const string p_date = "01/02/19",s_ticker = "WMT";
const int inv_amt = 10000, shareNum = 143;
float b_price = 0.00f, s_price = 0.00f, gain = 0.00f;
string s_date;


    cout << "Enter the purchase price => ";
    cin >> b_price;

    cout << "Enter the sell date (mm/dd/yy) => ";
    cin >> s_date;

    cout << "Enter the sell price => ";
    cin >> s_price;

    gain = s_price * shareNum + (inv_amt - b_price * shareNum) - inv_amt;


    cout << "\nStock Ticker: " << s_ticker << " \n" << endl;

    cout << "Purchase Date: " << p_date << endl;
    cout << "Purchase Price: $" << fixed << setprecision(2) << b_price << endl;
    cout << "Number of Shares Purchased: " << shareNum << "\n\n";

    cout << "Sell Date: " << s_date << endl;
    cout << "Sell Price: $" << fixed << s_price << endl;
    cout << "Value of Shares Sold: $" << fixed << setprecision(2) << s_price * shareNum << "\n\n";

    cout << "Gain: $" << gain << endl;
    cout << "Percent Gain: "<< fixed << setprecision(1) << gain / inv_amt * 100 << "%";
}
