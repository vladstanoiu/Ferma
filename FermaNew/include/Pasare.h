#ifndef PASARE_H
#define PASARE_H
#include <Animal.h>


class Pasare : public Animal
{
    public:
        Pasare();
        Pasare(TipAnimal , TipMancare , int);
        Pasare(TipAnimal);
        virtual ~Pasare();

    protected:

    private:
};

#endif // PASARE_H
