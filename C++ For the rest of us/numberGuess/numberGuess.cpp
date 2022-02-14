#include <iostream>

using namespace std;

int main(){

    cout << "Think of a number between 1 and 100..." << endl;

    int highest = 100, lowest = 0, attempts = 0;
    char response;
    bool running = true;
    bool understand = false;

    while(running){
        attempts++;
        understand = false;
        int guess = lowest + ((highest - lowest)*0.5);

        cout << "I guess " << guess << "... Am I right?" << endl;
        cout << "'q' to quit, 'y' if correct, 'h' if too high, 'l' if too low" << endl;
        cin >> response;
        
        while(!understand){
            switch (response)
            {
            case 'q':
                cout << "You quit. Bye." << endl;
                running = false;
                understand = true;
                break;
            case 'y':
                cout << "I guessed it in " << attempts << " attempts!" << endl;
                running = false;
                understand = true;
                break;
            case 'h':
                highest = guess;
                understand = true;
                break;
            case 'l':
                lowest = guess;
                understand = true;
                break;
            default:
                cout << "I didn't understand that, please try again..." << endl;
                cout << "'q' to quit, 'y' if correct, 'h' if too high, 'l' if too low" << endl;
                cin >> response;
                break;
            }
        }
    }
    return 0;
}