#include "Patruped.h"

Patruped::Patruped()
{
    //ctor
}
Patruped::Patruped(TipAnimal animalut , TipMancare mancare, int cantitate) : Animal::Animal(animalut , mancare , cantitate)
{
}
Patruped::Patruped(TipAnimal animalut) : Animal::Animal(animalut)
{

}
Patruped::~Patruped()
{
    //dtor
}
