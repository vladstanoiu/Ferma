#ifndef PATRUPED_H
#define PATRUPED_H
#include "Animal.h"


class Patruped : public Animal
{
    public:
        Patruped();
        Patruped(TipAnimal , TipMancare , int);
        Patruped(TipAnimal);
        virtual ~Patruped();

    protected:

    private:
};

#endif // PATRUPED_H
