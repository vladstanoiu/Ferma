#include <iostream>
#include "Animal.h"
#include "Patruped.h"
#include "Pasare.h"
#include "Ferma.h"

using namespace std;

Ferma ferma;
int alearga = 1;

void AfiseazaPatrupede();
void AfiseazaPasari();
void AdaugareAnimal();
void NrAnimaleNoi(TipAnimal);
void CereTipMancare(TipAnimal, int);
void CereCantitateMancare(TipAnimal, int, TipMancare );
void CreeazaAnimale(TipAnimal, int, TipMancare, int );
void ReduAnimale();
void Meniu();
void ReduAnimale();
void CereNrAnimaleExclus(int);
void AfiseazaPopulatieFerma();
void AdaugaHranaAnimale();
void CereCantitateDeAdaugat(TipMancare);
void AfiseazaSituatieFerma();



void Meniu()
{
    system("CLS");
    cout << "1. Adauga animale noi" << endl;
    cout << "2. Redu numarul de animale" << endl;
    cout << "3. Afiseaza populatie ferma" << endl;
    cout << "4. Adauga hrana animale" <<endl;
    cout << "5. Afiseaza situatie ferma" << endl;
    cout << "6. Vanzare animale" << endl;
    cout << "7. Iesire" << endl;
    int numar;
    cin >> numar;
    switch (numar)
    {
    case 1:
        AdaugareAnimal();
        break;
    case 2:
        ReduAnimale();
        break;
    case 3:
        AfiseazaPopulatieFerma();
        break;
    case 4:
        AdaugaHranaAnimale();
        break;
    case 5:
        AfiseazaSituatieFerma();
        break;
    case 6:
        ferma.VanzareAnimaleFerma();
        break;
    case 7:
        alearga = 0;
        break;
    default:
        Meniu();
    }
}


void AdaugareAnimal()
{
    system("CLS");
    cout << "Doriti sa adaugati: " << endl;
    cout << "1. Patrupede" << endl;
    cout << "2. Pasari" << endl;
    cout << "0. Reveniti la ecranul anterior" << endl;
    int optiune;
    cin >> optiune;
    switch (optiune)
    {
    case 1:
        AfiseazaPatrupede();
        break;
    case 2:
        AfiseazaPasari();
        break;
    case 0:
        break;
    default :
        AdaugareAnimal();
    }

}

void AfiseazaPatrupede()
{
    system("CLS");
    cout << "1. Porci" << endl;
    cout << "2. Oi" << endl;
    cout << "3. Bovine" << endl;
    cout << "4. Cai" << endl;
    int nr;
    cin >> nr;
    switch (nr)
    {
    case 1 :
        NrAnimaleNoi(porc);
        break;
    case 2 :
        NrAnimaleNoi(oaie);
        break;
    case 3:
        NrAnimaleNoi(bovina);
        break;
    case 4 :
        NrAnimaleNoi(cal);
        break;
    default :
        AfiseazaPatrupede();
    }
}

void AfiseazaPasari()
{
    system("CLS");
    cout << "1. Gaini" << endl;
    cout << "2. Gaste" << endl;
    cout << "3. Rate" << endl;
    cout << "4. Curci" << endl;
    int nr;
    cin >> nr;
    switch (nr)
    {
    case 1 :
        NrAnimaleNoi(gaina);
        break;
    case 2 :
        NrAnimaleNoi(gasca);
        break;
    case 3:
        NrAnimaleNoi(rata);
        break;
    case 4 :
        NrAnimaleNoi(curca);
        break;
    default :
        AfiseazaPasari();
    }
}

void NrAnimaleNoi(TipAnimal tip)
{
    system("CLS");
    cout << "Introduceti numarul de animale noi: " << endl;
    int numar;
    cin >> numar;
    if (numar > 0)
    {
        CereTipMancare(tip, numar);
    }
}

void CereTipMancare(TipAnimal tip, int numarAnimale)
{
    system("CLS");
    cout << "Precizati necesarul de hrana: " <<  endl;
    cout << "1. Porumb" << "\n2. Fan" << endl;
    int nr1;
    cin >> nr1;
    switch (nr1)
    {
    case 1 :
        CereCantitateMancare(tip, numarAnimale, porumb);
        break;
    case 2 :
        CereCantitateMancare(tip, numarAnimale, fan);
        break;
    default :
        CereTipMancare(tip, numarAnimale);
    }
}

void CereCantitateMancare(TipAnimal tip, int numarAnimale, TipMancare mancare)
{
    system("CLS");
    cout << "Precizati cantitatea in kg/zi: " << endl;
    int cantitate;
    cin>>cantitate;
    if (cantitate >0)
    {
        CreeazaAnimale( tip,  numarAnimale,  mancare,  cantitate);
    }
    else
    {
        CereCantitateMancare( tip,  numarAnimale,  mancare);
    }
}

void CreeazaAnimale(TipAnimal tip, int numarAnimale, TipMancare mancare, int cantitate)
{
    for (int q = 0; q < numarAnimale; q++)
    {
        if (tip == porc || tip == bovina || tip == oaie || tip == cal)
        {
            Patruped animalNou = Patruped(tip, mancare, cantitate);
            ferma.AdaugaAnimal(animalNou);
        }
        else
        {
            Pasare animalNou = Pasare(tip, mancare, cantitate);
            ferma.AdaugaAnimal(animalNou);
        }
    }
}
void ReduAnimale()
{
    system("CLS");
    cout << "Doriti sa reduceti  " << endl;
    ferma.ListaCateg();
    int a;
    cin >> a;
    if (a >= 0 && a < 8 )
    {
        CereNrAnimaleExclus(a);
    }
    else
    {
        ReduAnimale();
    }
}

void CereNrAnimaleExclus(int a)
{
    system("CLS");
    cout << "Introduceti cu cat scade totalul: " << endl;
    int i;
    cin >>i;
    if (i >0)
    {
        ferma.EliminaAnimale(a, i );
    }
    else
    {
        CereNrAnimaleExclus(a);
    }
}

void AfiseazaPopulatieFerma()
{
    system("CLS");
    cout << "Doriti sa reduceti  " << endl;
    ferma.ListaCateg();
    system("pause");
}

void AdaugaHranaAnimale()
{
    system("CLS");
    cout <<"Doriti sa adaugati: " << endl;
    cout << "1. Fan" << endl;
    cout << "2. Porumb " << endl;
    cout << "0. Reveniti la ecranul anterior" << endl;
    int val;
    cin >> val;
    switch(val)
    {
    case 1 :
        CereCantitateDeAdaugat(fan);
        break;
    case 2 :
        CereCantitateDeAdaugat(porumb);
        break;
    case 0 :
        break;
    default :
        AdaugaHranaAnimale();
    }
}

void CereCantitateDeAdaugat(TipMancare mancare)
{
    system("CLS");
    cout << "Precizati cantitatea: "<< endl;
    int i;
    cin >> i;
    if (i >0)
    {
        if (mancare == fan )
        {
            ferma.SetFan(i);
        }
        else
        {
            ferma.SetPorumb(i);
        }
    }
    else
    {
        CereCantitateDeAdaugat(mancare);
    }
}
void AfiseazaSituatieFerma()
{
    system("CLS");
    ferma.SituatieFerma();
    system("pause");
}


int main()
{
    while(alearga)
    {
        Meniu();
    }

    return 0;
}

