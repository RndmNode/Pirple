#include <iostream>
#include <string>

#include "TrackParser.h"

using namespace std;

string TrackParser::trim(string track){
    string retVal = track;
    const string TWO_SPACES = "  ";

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

    found = true;
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

string TrackParser::parse(string track){
    string retVal = track;
    string artist = "";
    string title = "";
    const string COLON = ":";
    const string HYPHEN = "-";
    const string BY = " by ";
    bool empty = false;
    
    int pos = retVal.find_first_of(COLON);
    if(pos != string::npos){
        artist = retVal.substr(0,pos);
        title = retVal.substr(pos + 1);
    }else{
        pos = retVal.find_first_of(HYPHEN);
        if(pos != string::npos){
            title = retVal.substr(0, pos);
            artist = retVal.substr(pos + 1);
        }else{
            pos = retVal.find(BY);
            if(pos != string::npos){
                title = retVal.substr(0, pos);
                artist = retVal.substr(pos + 3);
            }else empty = true;
        }
    }

    if(!empty){
        retVal = artist + ": " + title;
        retVal = trim(retVal);
    }else retVal = "";

    return retVal;
}

