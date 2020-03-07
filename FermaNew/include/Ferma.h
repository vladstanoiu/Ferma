#ifndef FERMA_H
#define FERMA_H

#include "Patruped.h"
#include "Pasare.h"

#include <vector>
#include <string>

class Ferma
{
    public:
        Ferma();
        std::vector<Animal> GetAnimalute(){return Animalute;}
        std::string NumeSpecieAnimal(int);
        void AdaugaAnimal(Animal);
        void EliminaAnimale(int , int);
        void ListaCateg();
        void SetFan(int fan){cantitateFan = fan;}
        void SetPorumb (int porumb) {cantitatePorumb = porumb;}
        void SetBuget(int bugetFerma) {sold = bugetFerma;}
        int GetFan(){return cantitateFan;}
        int GetPorumb(){return cantitatePorumb;}
        int GetBuget(){return sold;}
        int NumarAnimaleDeTip(int);
        void ExportSold(std::ostream&);
        void ExportMancare(std::ostream&);
        void SituatieFerma();
        void VanzareAnimaleFerma();
        void VizualizeazaBugetFerma();
        void CumparaAnimale();
        void CreeazaAnimaleDeCumparat(TipAnimal , int);
        void Reseteaza();
        virtual ~Ferma();

    protected:

    private:
        std::vector<Animal> Animalute;
        std::vector<int> Pret;
        std::vector<int>pretCumparare;
        int cantitateFan;
        int cantitatePorumb;
        int buget;
        int sold;

};

#endif // FERMA_H
