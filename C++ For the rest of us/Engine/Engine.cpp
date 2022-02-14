#include <iostream>
#include <string>
#include <bitset>

using namespace std;

//ASCII representation of a 4 cylinder engine firing in 1,3,2,4 order

string d1 = "    1       2       3       4   ";
string d2 = "   ___     ___     ___     ___  ";
string d3 = " x|   |x x|   |x x|   |x x|   |x";
string d4 = "  |   |   |   |   |   |   |   | ";
string d5 = "   ---     ---     ---     ---  ";
string d6 = "    ?       ?       ?       ?   ";

const int offset = 8;
int positionMask =      0b1000;
int rightShift = 0;
                                //  1     3       2       4
int inValvesOpen =      0b0010; //0010  1000    0001    0100
int outValvesOpen =     0b0100; //0100  0001    0010    1000
int pistonUp =          0b1010; //1010  1010    0101    0101
int cylinderFire =      0b1000; //1000  0010    0100    0001

char stateLabel = 'C';
char inValve = 'x';
char outValve = 'x';
char upPiston = ' ';
char downPiston = 'T';
char chamber = ' ';

void display(){
    string pistons[6] = {d1, d2, d3, d4, d5, d6};
    for(int i = 0; i < 6; i++){
        cout << pistons[i] << endl;  
    }
    cout << "\n\n";
}

int rotateLeft (int value, int amount)
{
    //four bit rotate left

    const int OVERFLOW = 0b10000;
        while (amount > 0)
        {
            value = value << 1;
            if (((value & OVERFLOW) == OVERFLOW))
            {
           value = value & 0b1111;  //remove overflow bit
                value = value | 0b0001;  //set the rightmost bit
    }
    amount--;
    }
    return value;
}

void setRightShift(){
    switch (positionMask)
    {
    case 0b1000:
        rightShift = 3;
        break;
    case 0b0100:
        rightShift = 2;
        break;
    case 0b0010:
        rightShift = 1;
        break;
    default:
        rightShift = 0;
        break;
    }
}

void nextFireOrder(){
    int shift = 0;

    switch (cylinderFire)
    {
    case 0b0010:
        shift = 1;
        cylinderFire = rotateLeft(cylinderFire, shift);
        pistonUp = rotateLeft(pistonUp, shift);
        inValvesOpen = rotateLeft(inValvesOpen, shift);
        outValvesOpen = rotateLeft(outValvesOpen, shift);
        break;
    case 0b0001:
        shift = 3;
        cylinderFire = rotateLeft(cylinderFire, shift);
        pistonUp = rotateLeft(pistonUp, shift);
        inValvesOpen = rotateLeft(inValvesOpen, shift);
        outValvesOpen = rotateLeft(outValvesOpen, shift);
        break;
    default:
        shift = 2;
        cylinderFire = rotateLeft(cylinderFire, shift);
        pistonUp = rotateLeft(pistonUp, shift);
        inValvesOpen = rotateLeft(inValvesOpen, shift);
        outValvesOpen = rotateLeft(outValvesOpen, shift);
        break;
    }
}

void updatePiston(int piston){
    d3[1 + (offset * (piston - 1))] = inValve;
    d3[3 + (offset * (piston - 1))] = chamber;
    d3[4 + (offset * (piston - 1))] = upPiston;
    d3[5 + (offset * (piston - 1))] = chamber;
    d3[7 + (offset * (piston - 1))] = outValve;
    d4[4 + (offset * (piston - 1))] = downPiston;
    d6[4 + (offset * (piston - 1))] = stateLabel;
}

void run(){
    for(int i = 0; i < 5; i++){
        for(int c = 1; c < 5; c++){
            setRightShift();

            if(((positionMask & inValvesOpen) >> rightShift) == 1){
                inValve = 'o';
                stateLabel = 'I';
            }else inValve = 'x';

            if(((positionMask & pistonUp) >> rightShift) == 1){
                upPiston = 'T';
                downPiston = ' ';
                if(((positionMask & cylinderFire) >> rightShift) == 1){
                    chamber = '*';
                    stateLabel = 'P';
                }else chamber = ' ';
            }else {
                downPiston = 'T';
                upPiston = ' ';
            }

            if(((positionMask & outValvesOpen) >> rightShift) == 1){
                outValve = 'o';
                stateLabel = 'E';
                chamber = ' ';
            }else outValve = 'x';

            if(inValve == 'x' && outValve == 'x' && downPiston == 'T'){
                stateLabel = 'C';
                chamber = ' ';
            }
            updatePiston(c);
            positionMask >>= 1;
        }
        display();
        nextFireOrder();
        positionMask = 0b1000;
    }
}

int main(){
    run();
    return 0;
}