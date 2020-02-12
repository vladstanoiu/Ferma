#include "Pasare.h"

Pasare::Pasare()
{
    //ctor
}
Pasare::Pasare(TipAnimal animalut , TipMancare mancare, int cantitate) : Animal::Animal (animalut , mancare ,cantitate)
{
}
Pasare::~Pasare()
{
    //dtor
}
