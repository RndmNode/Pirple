#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "PlayList.h"
#include "List_Base.h"
#include "TrackParser.h"

using namespace std;

void PlayList::makeFile(string name){
    string fileName = name + ".playlist";
    ofstream file(fileName);
    file.close();
}

string PlayList::addTrack(string fileName, string track){
    string message = "";
    vector<string> list = List_Base::getList(fileName);
    track = TrackParser::parse(track);
    bool run = true;

    for(int i=0; i<list.size(); i++){
        if(list[i] == track){
            message = "That track already exists. Please try again.";
            run = false;
        }else message = "Track added";
    }

    if(run){
        ofstream file(fileName, ios_base::app);
        if(file.is_open()){
            file << track << endl;
        }
        file.close();
        List_Base::clean(fileName);
    }

    return message;
}

string PlayList::deleteTrack(string Playlist, string track){
    string message = "";
    string fileName = Playlist + ".playlist";
    vector<string> list = List_Base::getList(fileName);
    ifstream in(fileName);
    ofstream temp("temp.txt");

    if(in.is_open() && temp.is_open()){
        for(int i=0; i<list.size(); i++){
            if(list[i] == track){
                continue;
            }else{
                temp << list[i] << endl;
            }
        }
    }

    temp.close();
    in.close();

    const char * p = fileName.c_str();
    remove(p);
    rename("temp.txt", p);
    List_Base::clean(fileName);

    message = "Track Deleted";
    return message;
}