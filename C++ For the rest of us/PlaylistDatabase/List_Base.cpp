#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "List_Base.h"

using namespace std;

vector<string> List_Base::getList(string fileName){
    vector<string> list;
    ifstream file (fileName.c_str());

    if(file.is_open()){
        string line;
        while(getline(file, line)){
            list.push_back(line);
        }
        file.close();
    }

    return list;
}

void List_Base::sort(string fileName){
    vector<string> list;
    list = getList(fileName);

    int count = list.size();

    for(int i = 0; i < count - 1; i++){
        for(int j = i + 1; j < count; j++){
            string outer = list[i];
            string inner = list[j];
            if(inner < outer){
                iter_swap(list.begin() + j, list.begin() + i);
            }
        }
    }

    ofstream file(fileName.c_str());

    if(file.is_open()){
        for(int i = 0; i < list.size(); i++){
            file << list[i] << endl;
        }
    }
    file.close();
}

void List_Base::clean(string fileName){
    string line = "";
    vector<string> list;

    ifstream old(fileName);
    ofstream temp("temp.txt");

    if(old.is_open()){
        while(getline(old, line)){
            if(line.size()==0){
                continue;
            }else{
                temp << line << endl;
            }
        }
    }
    old.close();
    temp.close();

    const char * p = fileName.c_str();
    remove(p);
    rename("temp.txt", p);
    List_Base::sort(p);
}