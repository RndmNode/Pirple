#ifndef BREEDS_H
#define BREEDS_H

#include "dog.h"
#include <string>

using namespace std;

class Pitbull : public Dog{
    public:
        Pitbull();
        ~Pitbull(){};
    protected:
    private:
};

class Doberman : public Dog{
    public:
        Doberman();
        ~Doberman(){};
    protected:
    private:
};

class Rottweiler : public Dog{
    public:
        Rottweiler();
        ~Rottweiler(){};
    protected:
    private:
};

class GermanShepherd : public Dog{
    public:
        GermanShepherd();
        ~GermanShepherd(){};
    protected:
    private:
};

class ChowChow : public Dog{
    public:
        ChowChow();
        ~ChowChow(){};
    protected:
    private:
};

class GreatDane : public Dog{
    public:
        GreatDane();
        ~GreatDane(){};
    protected:
    private:
};

class PresaCanario : public Dog{
    public:
        PresaCanario();
        ~PresaCanario(){};
    protected:
    private:
};

class Akita : public Dog{
    public:
        Akita();
        ~Akita(){};
    protected:
    private:
};

class AlaskanMalamute : public Dog{
    public:
        AlaskanMalamute();
        ~AlaskanMalamute(){};
    protected:
    private:
};

class Husky : public Dog{
    public:
        Husky();
        ~Husky(){};
    protected:
    private:
};

class OtherBreed : public Dog{
    public:
        OtherBreed();
        ~OtherBreed(){};
    protected:
    private:
};

#endif //BREEDS_H