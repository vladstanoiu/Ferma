#ifndef FERMA_H
#define FERMA_H
#include <vector>
#include "Animal.h"
#include <string>

class Ferma
{
    public:
        Ferma();
        virtual ~Ferma();
        std::vector<Animal> GetAnimalute (){return Animalute;}
        void AdaugaAnimal(Animal);
        std::string NumeSpecieAnimal(int);
        void EliminaAnimale(int , int);
        void ListaCateg();
        void SetFan(int fan){cantitateFan += fan;}
        void SetPorumb (int porumb) {cantitatePorumb += porumb;}
        int GetFan (){return cantitateFan;}
        int GetPorumb(){return cantitatePorumb;}
        void SituatieFerma();
        void VanzareAnimaleFerma();



    protected:

    private:
        std::vector<Animal> Animalute;
        std::vector<int> Pret;
        int cantitateFan;
        int cantitatePorumb;
        int buget;
};

#endif // FERMA_H
