#ifndef LIST_BASE_H
#define LIST_BASE_H

#include <string>
#include <vector>

using namespace std;

class List_Base{
    public:
        List_Base(){};
        vector<string> getList(string fileName);
        void sort(string fileName);
        void clean(string fileName);
        ~List_Base(){};
    protected:
    private:
};

#endif //LIST_BASE_H