#ifndef FERMA_H
#define FERMA_H
#include <vector>
#include "Animal.h"
#include <string>
#include "Patruped.h"
#include "Pasare.h"
#include "Utilaj.h"


class Ferma
{
    public:
        Ferma();
        virtual ~Ferma();
        std::vector<Animal> GetAnimalute (){return Animalute;}
        void AdaugaAnimal(Animal);
        void AdaugaUtilaj(Utilaj);
        std::string NumeSpecieAnimal(int);
        void EliminaAnimale(int , int);
        void EliminaUtilaje(TipUtilaj , int);
        void ListaCateg();
        void SetFan(int fan){cantitateFan += fan;}
        void SetPorumb (int porumb) {cantitatePorumb += porumb;}
        void SetBuget(int bugetFerma) {sold += bugetFerma;}
        int GetFan (){return cantitateFan;}
        int GetPorumb(){return cantitatePorumb;}
        int GetBuget(){return sold;}
        void SituatieFerma();
        void VanzareAnimaleFerma();
        void VizualizeazaBugetFerma();
        void CumparaAnimale();
        void CreeazaAnimaleDeCumparat(TipAnimal , int);

    protected:

    private:
        std::vector<Animal> Animalute;
        std::vector<int> Pret;
        std::vector<Utilaj> Masinute;
        std::vector<int>pretCumparare;
        int cantitateFan;
        int cantitatePorumb;
        int buget;
        int sold;
};

#endif // FERMA_H
