#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <ostream>

enum TipMancare {porumb , fan};
enum TipAnimal {porc , oaie , bovina , cal , gaina , gasca , rata , curca};

class Animal
{
    public:
        Animal();
        Animal(TipAnimal , TipMancare , int);
        Animal(TipAnimal);

        TipAnimal GetSpecie(){return specie;}
        TipMancare GetTipMancare(){return haleala;}
        int GetCantitateMancare(){return cantitateMancare;}
        void Export(std::ostream&);
        virtual ~Animal();

    protected:

    private:
        int cantitateMancare;
        TipMancare haleala;
        TipAnimal specie;
};

#endif // ANIMAL_H
