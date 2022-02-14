#include <iostream>
#include <math.h>

using namespace std;

int main(){

    float a, b, c = 0.0F;
    float x1, x2 = 0.0F;

    cout << "Enter the value for a" << endl;
    cin >> a;
    cout << "Enter the value for b" << endl;
    cin >> b;
    cout << "Enter the value for c" << endl;
    cin >> c;

    x1 = (-b - (sqrt(pow(b,2)-(4*(a)*(c)))))/(2*a);
    x2 = (-b + (sqrt(pow(b,2)-(4*(a)*(c)))))/(2*a);

    cout << "The first value of x is " << x1 << endl;
    cout << "The second value of x is " << x2 << endl;

    return 0;
}