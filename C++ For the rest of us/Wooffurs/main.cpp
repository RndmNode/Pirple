#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>

#include "dog.h"
#include "breeds.h"

using namespace std;

int getDogCount(){
    int retVal = 0;
    cout << "Please enter the number of dogs in your household: ";
    cin >> retVal;
    return retVal;
}

void run(){
    cout << setiosflags(ios::fixed);
    cout << setprecision(2);

    int dogCount = 0;
    float totalPremium = 0;

    dogCount = getDogCount();

    for(int i = 1; i <= dogCount; i++){
        float premium = 0;
        char breedCode = '.';
        string dogName = "";
        Dog pup;

        cout << "Enter the name of dog #" << i << ": ";
        cin.ignore();
        getline(cin, dogName);

        cout << "Enter the breed code for " << dogName << ": ";
        cin >> breedCode;
        cin.ignore();

        pup = pup.getDog(breedCode);
        pup.dogName = dogName;

        cout << pup.dogName << " is " << pup.Breed << "." << endl;

        cout << "Enter the current age for " << dogName << ": ";
        cin >> pup.age;
        cin.ignore();

        cout << "Enter the current weight for " << dogName << " (in nearest kg): ";
        cin >> pup.weight;

        premium = pup.getPremium();

        cout << pup.dogName << "'s monthly premium is " << premium << endl;
        cout << "\n";

        totalPremium += premium;
    }
    cout << "\nTotal monthly premium for all dogs is " << totalPremium;
}

int main(){
    run();
    return 0;
}