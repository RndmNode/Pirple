#ifndef LISTINDEX_H
#define LISTINDEX_H

#include <string>
#include "List_Base.h"

using namespace std;

class ListIndex : public List_Base{
    public:
        ListIndex(){};
        string addPlaylist(string name);
        string deletePlaylist(string name);
        ~ListIndex(){};
    protected:
    private:
};

#endif //LISTINDEX_H