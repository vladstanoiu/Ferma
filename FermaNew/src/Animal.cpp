#include "Animal.h"

using namespace std;
Animal::Animal()
{
    //ctor
}
Animal::Animal(TipAnimal animalut , TipMancare mancare, int cantitate) : specie(animalut) , haleala(mancare) , cantitateMancare(cantitate)
{

}
Animal::Animal(TipAnimal animalut) : specie(animalut)
{

}
void Animal::Export(std::ostream& out)
{
  out << specie << " " << haleala << " " << cantitateMancare;
}
Animal::~Animal()
{
    //dtor
}
