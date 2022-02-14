#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include "List_Base.h"

using namespace std;

class PlayList : public List_Base{
    public:
        PlayList(){};
        void makeFile(string name);
        string addTrack(string PlayList, string track);
        string deleteTrack(string Playlist, string track);
        ~PlayList(){};
    protected:
    private:
};

#endif //PLAYLIST_H