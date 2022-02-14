#include <iostream>
#include <string>

using namespace std;

string fullName;
string title = "";
string artist = "";
const string COLON = ":";
const string HYPHEN = "-";
const string BY = " by ";

string getUserInput(){
    string input;

    cout << "Enter a track or 'q' to quit" << endl;
    getline(cin, input);

    return input;
}

string singleSpace(string in){
    string retVal = in;
    const string TWO_SPACES = "  ";

    bool found = true;

    while(found){
        int pos = retVal.find(TWO_SPACES);
        if(pos == string::npos){
            found = false;
        }else{
            retVal.erase(pos, 1);
        }
    }

    return retVal;
}

string trim(string in){
    string retVal = in;
    int lastPos = retVal.length() - 1;

    bool found = true;

    while(found && lastPos >= 0){
        if(retVal.substr(lastPos, 1) == " "){
            retVal = retVal.erase(lastPos, 1);
        }else if(retVal.substr(0, 1) == " "){
            retVal = retVal.erase(0, 1);
        }else found = false;

        lastPos = retVal.length()-1;
    }

    retVal = singleSpace(retVal);

    return retVal;
}

void printTrack(){
    cout << "TITLE: " << title << endl;
    cout << "ARTIST: " << artist << endl;
}

void run(){
    bool running = true;

    while(running){
        fullName = getUserInput();
        if(fullName == "q"){
            break;
        }else if(fullName.length() < 5){
            cout << "Please enter a track with more than 5 characters.\n" << endl;
            running = false;
            break;
        }else{
            int pos = fullName.find_first_of(COLON);
            if(pos != string::npos){
                artist = fullName.substr(0,pos);
                title = fullName.substr(pos + 1);
            }else{
                pos = fullName.find_first_of(HYPHEN);
                if(pos != string::npos){
                    title = fullName.substr(0, pos);
                    artist = fullName.substr(pos + 1);
                }else{
                    pos = fullName.find(BY);
                    if(pos != string::npos){
                        title = fullName.substr(0, pos);
                        artist = fullName.substr(pos + 3);
                    }
                }
            }

            title = trim(title);
            artist = trim(artist);

            printTrack();
        }
    }
    if(!running) run();
}

int main(){
    run();
    return 0;
}