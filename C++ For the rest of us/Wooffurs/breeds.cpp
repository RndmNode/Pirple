#include <iostream>
#include <string>

#include "dog.h"
#include "breeds.h"

using namespace std;

//---constructors---//
Pitbull::Pitbull(){
    this->Breed = "a Pitbull";
    this->basePremium = 30.20f;
    this->riskPremium = 35.15f;
    this->riskWeight = 20;
    this->subjectToDiscount = false;
}

Doberman::Doberman(){
    this->Breed = "a Doberman";
    this->basePremium = 28.16f;
    this->riskPremium = 30.00f;
    this->riskWeight = 35;
    this->subjectToDiscount = true;
}

Rottweiler::Rottweiler(){
    this->Breed = "a Rottweiler";
    this->basePremium = 28.00f;
    this->riskPremium = 29.75f;
    this->riskWeight = 45;
    this->subjectToDiscount = false;
}

GermanShepherd::GermanShepherd(){
    this->Breed = "a German Shepherd";
    this->basePremium = 27.50f;
    this->riskPremium = 29.75f;
    this->riskWeight = 30;
    this->subjectToDiscount = true;
}

ChowChow::ChowChow(){
    this->Breed = "a Chow Chow";
    this->basePremium = 25.10f;
    this->riskPremium = 27.50f;
    this->riskWeight = 24;
    this->subjectToDiscount = true;
}

GreatDane::GreatDane(){
    this->Breed = "a Great Dane";
    this->basePremium = 25.10f;
    this->riskPremium = 25.20f;
    this->riskWeight = 55;
    this->subjectToDiscount = true;
}

PresaCanario::PresaCanario(){
    this->Breed = "a Presa Canario";
    this->basePremium = 20.01f;
    this->riskPremium = 20.55f;
    this->riskWeight = 45;
    this->subjectToDiscount = false;
}

Akita::Akita(){
    this->Breed = "an Akita";
    this->basePremium = 19.75f;
    this->riskPremium = 0;
    this->riskWeight = 0;
    this->subjectToDiscount = false;
}

AlaskanMalamute::AlaskanMalamute(){
    this->Breed = "an Alaskan Malamute";
    this->basePremium = 15.50f;
    this->riskPremium = 18.15f;
    this->riskWeight = 38;
    this->subjectToDiscount = true;
}

Husky::Husky(){
    this->Breed = "a Husky";
    this->basePremium = 9.95f;
    this->riskPremium = 12.00f;
    this->riskWeight = 20;
    this->subjectToDiscount = true;
}

OtherBreed::OtherBreed(){
    this->Breed = "Other Breed";
    this->basePremium = 4.95f;
    this->riskPremium = 8.95f;
    this->riskWeight = 35;
    this->subjectToDiscount = true;
}