#include "Animal.h"

Animal::Animal()
{
    //ctor
}
Animal::Animal(TipAnimal animalut , TipMancare mancare, int cantitate) : specie(animalut) , haleala(mancare) , cantitateMancare(cantitate)
{

}
Animal::~Animal()
{
    //dtor
}
