#ifndef TRACKPARSER_H
#define TRACKPARSER_H

#include <string>

using namespace std;

class TrackParser{
    public:
        TrackParser(){};
        static string parse(string track);
        ~TrackParser(){};
    protected:
    private:
        static string trim(string track);
};

#endif //TRACKPARSER_H