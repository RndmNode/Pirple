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

menuManager manager;

int main(){
    manager.mainMenu();

    return 0;
}