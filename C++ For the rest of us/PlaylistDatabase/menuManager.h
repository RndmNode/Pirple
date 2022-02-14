#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <string>
#include <vector>

using namespace std;

class menuManager{
    public:
        menuManager(){};
        void mainMenu();
        void playlistMenu(string playlist);
        void trackMenu(string playlist, string track);
        ~menuManager(){};
    protected:
    private:
};

#endif //MENUMANAGER_H