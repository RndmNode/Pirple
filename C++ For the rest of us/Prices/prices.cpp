#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){

    cout << setiosflags(ios::fixed);
    cout << setprecision(2);

    float price1 = 0.0F;
    float price2 = 0.0F;
    float price3 = 0.0F;
    float total = 0.0F;

    cout << "Enter a Price" << endl;
    cin >> price1;
    cout << "Enter a Price" << endl;
    cin >> price2;
    cout << "Enter a Price" << endl;
    cin >> price3;

    total = price1 + price2 + price3;

    cout << setw(13) << "Price 1 is " << setw(10) << price1 << "\n"
         << setw(13) << "Price 2 is " << setw(10) << price2 << "\n"
         << setw(13) << "Price 3 is " << setw(10) << price3 << "\n"
         << setw(13) << "Total price: " << setw(10) << total << endl;

    return 0;
}