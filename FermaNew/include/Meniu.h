#ifndef MENIU_H
#define MENIU_H
//#include "Animal.h"
#include "Ferma.h"
#include <iostream>


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
    bool GetAlearga (){return alearga;}

    virtual ~Meniu();

protected:

private:
    bool alearga;
    Ferma ferma;
};

#endif // MENIU_H
