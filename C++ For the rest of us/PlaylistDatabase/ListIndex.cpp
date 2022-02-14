#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "ListIndex.h"
#include "List_Base.h"

using namespace std;

string ListIndex::addPlaylist(string name){
    string message = "";
    vector<string> list;
    list = List_Base::getList("index.txt");
    bool run = true;

    if(list.size() > 0){
        for(int i=0; i<list.size(); i++){
            if(list[i] == name){
                message = "Sorry that playlist already exists";
                run = false;
                break;
            }else{
                message = "Playlist Successfully Added";
                run = true;
            }
        }
    }

    if(run){
        ofstream file;
        file.open("index.txt", ios_base::app);
        if(file.is_open()){
            file << name << endl;
        }else cout << "unable to open file...";
        file.close();
    }

    List_Base::clean("index.txt");

    return message;
}

string ListIndex::deletePlaylist(string name){
    string message = "";
    vector<string> list = List_Base::getList("index.txt");
    ifstream index("index.txt");
    ofstream temp("temp.txt");

    if(index.is_open() && temp.is_open()){
        for(int i=0; i<list.size(); i++){
            if(list[i] == name){
                continue;
            }else{
                temp << list[i] << endl;
            }
        }
    }

    temp.close();
    index.close();

    remove("index.txt");
    rename("temp.txt", "index.txt");
    List_Base::clean("index.txt");

    message = "Playlist Deleted";
    return message;
}