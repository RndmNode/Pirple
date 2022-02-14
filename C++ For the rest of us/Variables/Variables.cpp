#include <iostream>
#include <climits>

using namespace std;

const int MINUTES_PER_HOUR = 60;

int numHours = 5;

int main(){
    
    //MINUTES_PER_HOUR++;
    numHours++;
    cout << "There are " << numHours * MINUTES_PER_HOUR << " minutes in " << numHours << " hours.\n";

    unsigned int zeroHour = 0;
    zeroHour--;
    cout << "1 hour before zero hour is " << zeroHour << ".";

    return 0;
}