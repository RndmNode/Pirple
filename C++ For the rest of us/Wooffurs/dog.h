#ifndef DOG_H
#define DOG_H

#include <string>

using namespace std;

class Dog{
    public:
        Dog();
        ~Dog(){};
        string dogName = "";
        string Breed = "";
        int age = 0;
        int weight = 0;
        bool subjectToDiscount = false;
        int riskWeight = 0;
        float riskPremium = 0;
        float basePremium = 0;
        virtual float getPremium();
        virtual Dog getDog(char b);
    protected:
        virtual float getBasePremium();
    private:
};

#endif //DOG_H