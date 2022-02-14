#include <iostream>
#include <string>

#include "dog.h"
#include "breeds.h"

using namespace std;

//---default constructor---//
Dog::Dog(){
};

//---methods---//
float Dog::getBasePremium(){
    float val = 0;
    //calculate base premium based on weight
    return val;
};

float Dog::getPremium(){
    float val = 0;
    //calculate actual premium for the dog in question
    if(this->riskWeight == 0){
        val = this->basePremium;
    }else if(this->weight >= this-> riskWeight){
        val = this->riskPremium;
    }else val = this->basePremium;

    //add discount if applicable
    if(this->subjectToDiscount && this->age > 13) val *= 0.80;

    //add 25% if over 50kg
    if(this->weight >= 50) val *= 1.25;

    return val;
};

Dog Dog::getDog(char b){
    bool recognized = false;
    Dog *pup; 
    char x = b;

    while(!recognized){
        switch (x)
        {
        case 'p':
            pup = new Pitbull();
            recognized = true;
            break;
        case 'd':
            pup = new Doberman();
            recognized = true;
            break;
        case 'r':
            pup = new Rottweiler();
            recognized = true;
            break;
        case 'g':
            pup = new GermanShepherd();
            recognized = true;
            break;
        case 'c':
            pup = new ChowChow();
            recognized = true;
            break;
        case 't':
            pup = new GreatDane();
            recognized = true;
            break;
        case 's':
            pup = new PresaCanario();
            recognized = true;
            break;
        case 'k':
            pup = new Akita();
            recognized = true;
            break;
        case 'm':
            pup = new AlaskanMalamute();
            recognized = true;
            break;
        case 'h':
            pup = new Husky();
            recognized = true;
            break;
        case 'b':
            pup = new OtherBreed();
            recognized = true;
            break;
        default:
            cout << "Breed code not recognized, please try again...\n";
            cin >> x;
            break;
        }
    }
    return *pup;
}