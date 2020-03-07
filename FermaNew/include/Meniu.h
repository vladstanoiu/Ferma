#ifndef MENIU_H
#define MENIU_H
#include <sstream>
#include "Ferma.h"



class Meniu
{
public:
    Meniu(Ferma);
    Meniu();

    void MeniuPrincipal();
    void CreeazaAnimale(TipAnimal, int, TipMancare, int );
    void AfiseazaPatrupede();
    void AfiseazaPasari();
    void AdaugareAnimal();
    void ReduAnimale();
    void NrAnimaleNoi(TipAnimal);
    void CereTipMancare(TipAnimal, int);
    void CereCantitateMancare(TipAnimal, int, TipMancare );
    void CereNrAnimaleExclus(int);
    void AfiseazaPopulatieFerma();
    void AdaugaHranaAnimale();
    void CereCantitateDeAdaugat(TipMancare);
    void AfiseazaSituatieFerma();
    void ExchangeOffice();
    void ExportaAnimale();
    void ExportaMancare();
    void ExportaSold();
    void CitesteSold();
    void CitesteAnimale();
    void CitesteMancare();
    TipAnimal nrToAnimal(int);
    TipMancare nrToFood(int);
    bool GetAlearga(){return alearga;}

    virtual ~Meniu();

protected:

private:
    bool alearga;
    Ferma ferma;
};

#endif // MENIU_H
