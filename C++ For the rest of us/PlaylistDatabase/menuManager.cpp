#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "List_Base.h"
#include "ListIndex.h"
#include "PlayList.h"
#include "TrackParser.h"
#include "menuManager.h"

using namespace std;

char input = ' ';
string line;
ListIndex Index;
PlayList play;
vector<string> list;
string endMessage = "";

void menuManager::mainMenu(){
    system("cls");
    cout << "\n" + endMessage + "\n";
    endMessage = "";

    //get playlists
    list = Index.getList("index.txt");

    cout << "Title: Main Menu\n" << endl;
    cout << "c. Create a Playlist" << endl;
    cout << "x. Exit the program\n" << endl;
    
    //if list is not empty, list out the playlists in the index
    if(list.size() > 0){
        cout << "Select Playlist #\n" << endl;
        for(int i=0; i<list.size(); i++){
            cout << to_string(i+1)+ ". " + list[i] << endl;
        }
    }
    //Get user input
    cout << "\nYour choice: ";
    cin >> input;
    cout << "\n";
    int intChar = input - 48;

    //use input to either exit program or add playlist
    if(input == 'x'){
        cout << "Farewell!\n";
    }else if(input == 'c'){
        cout << "Please enter the name for your new playlist: " << endl;
        getline(cin, line);
        play.makeFile(line);
        endMessage =  Index.addPlaylist(line);
        mainMenu();
    }else {
        if(intChar > list.size()){
            endMessage = "Invalid input; please try again.";
            mainMenu();
        }else {
            string playlist = list[intChar - 1];
            playlistMenu(playlist);
        }
    }
}

void menuManager::playlistMenu(string playlist){
    system("cls");
    cout << "\n\n";
    line = "";

    string fileName = playlist + ".playlist";

    list = Index.getList(fileName);

    cout << "Playlist '" + playlist + "' Menu:\n" << endl;
    cout << "a. Add track(s) to playlist" << endl;
    cout << "d. Delete this playlist" << endl;
    cout << "x. Exit to main menu\n" << endl;

    if(list.size() > 0){
        cout << "Select Track #\n" << endl;
        for(int i=0; i < list.size(); i++){
            cout << to_string(i+1) + ". " + list[i] << endl;
        } 
    }
    //Get user input
    cout << "\nYour choice: ";
    cin >> input;
    cin.ignore();
    cout << "\n";
    int intChar = input - 48;
    
    if(input == 'x'){
        mainMenu();
    }else if(input == 'a'){
        endMessage = "";
        while(line != "x"){
            cout << endMessage << endl;
            cout << "Enter a title and artist, or 'x' to exit" << endl;
            getline(cin, line);
            endMessage = play.addTrack(fileName,line);
            cout << "\n";
        }
        playlistMenu(playlist);
    }else if(input == 'd'){
        endMessage = Index.deletePlaylist(playlist);
        mainMenu();
    }else {
        if(intChar > list.size()){
            endMessage = "Invalid input; please try again.";
            playlistMenu(playlist);
        }else {
            string track = list[intChar - 1];
            trackMenu(playlist, track);
        }
    }
}

void menuManager::trackMenu(string playlist, string track){
    system("cls");
    cout << "\n\n";
    endMessage = "";
    line = "";

    cout << "Playlist '" + playlist + "'" << endl;
    cout << "Track: '" + track + "'\n" << endl;

    cout << "d. Delete this track" << endl;
    cout << "x. Exit to playlist menu\n" << endl;

    //Get user input
    cout << "Your choice: ";
    cin >> input;
    cin.ignore();
    cout << "\n";
    int intChar = input - 48;

    if(input == 'x'){
        playlistMenu(playlist);
    }else if(input == 'd'){
        play.deleteTrack(playlist, track);
        playlistMenu(playlist);
    }

    mainMenu();
}