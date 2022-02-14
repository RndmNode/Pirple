#include <iostream>
#include <string.h>
#include <string>

using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

char lastPlayer;
char currentPlayer;

char Board[3][3];

char response;
string winnerBy = "";

int charToInt(char i){
    int x = i - '0';
    return x;
}

char intToChar(int i){
    char x = i + '0';
    return x;
}

void drawBoard(){
    cout << "\nCurrent Board State:\n" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j == 2){
                cout << " | ";
                cout << Board[i][j] << endl;
            }else if (j == 0){
                cout << "    " << Board[i][j];
            }else{
                cout << " | ";
                cout << Board[i][j];
            }
        }
        if(i < 2){
            cout << "   ---+---+---" << endl;
        }
    }
}

void setup(){
    //set up players so X goes first
    currentPlayer = PLAYER_X;
    lastPlayer = PLAYER_O;

    //Board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            Board[i][j] = intToChar((1+(i*3))+j);
        }
    }
}

bool updateBoard(int pos){
    int i = (pos / 3);
    int j = (pos % 3) - 1;

    if(Board[i][j] == 'X' || Board[i][j] == 'O'){
        return false;
    }else{
        Board[i][j] = currentPlayer;
        return true;
    }
}

string checkForEndGame(){
    //9 different checks for end possibilities
    if(Board[0][0] == Board[0][1] && Board[0][1] == Board[0][2]){
        winnerBy = "Top Row";
    }else if(Board[1][0] == Board[1][1] && Board[1][1] == Board[1][2]){
        winnerBy = "Middle Row";
    }else if(Board[2][0] == Board[2][1] && Board[2][1] == Board[2][2]){
        winnerBy = "Bottom Row";
    }else if(Board[0][0] == Board[1][0] && Board[1][0] == Board[2][0]){
        winnerBy = "Left Column";
    }else if(Board[0][1] == Board[1][1] && Board[0][1] == Board[2][1]){
        winnerBy = "Middle Column";
    }else if(Board[0][2] == Board[1][2] && Board[0][2] == Board[2][2]){
        winnerBy = "Right Column";
    }else if(Board[2][0] == Board[1][1] && Board[2][0] == Board[0][2]){
        winnerBy = "Upward Diagonal";
    }else if(Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2]){
        winnerBy = "Downward Diagonal";
    }else winnerBy = "null";

    return winnerBy;
}

void getPlayerChoice(){
    while (charToInt(response) > 9 || charToInt(response) < 1){
        cout << "Player "<< currentPlayer<<", enter a number between 1 and 9 or 'q' to quit: ";
        cin >> response;
        cout << "\n";
        if(charToInt(response) < 1){
            cout << "Not a valid choice. Try Again." << endl;
        }else if(response == 'q'){
            cout << "You quit. Thanks for playing!" << endl;
            break;
        }else if(charToInt(response) > 9 || charToInt(response) < 1){
            cout << "Not a valid choice. Try Again." << endl;
        }else if(!updateBoard(charToInt(response))){
            cout << "That square is not available. Try again." << endl;
            response = 'a';
        }
    }
}

void play(){
    //loop 9 times in total for the number of turns there are in one game
    for(int i = 1; i < 10; i++){
        drawBoard();
        getPlayerChoice();
        //repeat to check for player quitting to break out of the for loop
        if(response == 'q'){
            break;
        }

        if(i > 4){
            winnerBy = checkForEndGame();
            if(winnerBy != "null"){
                drawBoard();
                cout << "Player " << currentPlayer << " won on " << winnerBy <<"!!!" << endl;
                break;
            }else if (i == 9){
                drawBoard();
                cout << "Draw. Nobody Wins." << endl;
            }
        }
        response = 0;
        std::swap(currentPlayer, lastPlayer);
    }
    cout << "\n\n";
}

int main(){
    setup();
    play();

    while (response != 'n' && response != 'y' && response != 'q'){
        cout << "Play again? (y/n): ";
        cin >> response;
        if(response == 'y') main();
        else if(response == 'n') cout << "Have a good day!" << endl;
        else cout << "Not a valid response, try again..." << endl;
    }
    
    return 0;
}