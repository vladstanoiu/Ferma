#include "Ferma.h"
#include <iostream>
using namespace std;

Ferma::Ferma()
{
    cantitateFan = 0;
    cantitatePorumb = 0;
    Pret = vector <int>{100,70,200,300,25,25,30,30};
    pretCumparare = vector<int>{80,50,150,250,20,20,25,25};
    buget = 0;
    sold = 500;
}

void Ferma::ExportSold(std::ostream& out)
{
    out << sold ;
}

void Ferma::ExportMancare(std::ostream& out)
{
    out << cantitatePorumb << " " << cantitateFan ;
}

void Ferma::Reseteaza()
{
    SetBuget(500);
    SetFan(0);
    SetPorumb(0);
    vector <Animal> vietati;
    Animalute = vietati;
}

string Ferma::NumeSpecieAnimal(int animal)
{
    string specie = "";
    switch (animal)
    {
    case 0 :
        specie = "0. Porci";
        break;
    case 1 :
        specie = "1. Oi";
        break;
    case 2 :
        specie = "2. Bovine";
        break;
    case 3 :
        specie = "3. Cai";
        break;
    case 4 :
        specie = "4. Gaini";
        break;
    case 5 :
        specie = "5. Gaste";
        break;
    case 6 :
        specie = "6. Rate";
        break;
    case 7 :
        specie = "7. Curci";
        break;
    default :
        specie =  "n/a";

    }
    return specie;
}
void Ferma::CreeazaAnimaleDeCumparat(TipAnimal tip, int numarAnimale)
{
    cout << "Precizati necesarul de hrana: " <<  endl;
    cout << "1. Porumb" << "\n2. Fan" << endl;
    TipMancare tipMancare;
    int optiuneMancare;
    cin >> optiuneMancare;
    if (optiuneMancare == 1 )
    {
        tipMancare = porumb;
    }
    if (optiuneMancare == 2)
    {
        tipMancare = fan;
    }
    system("CLS");
    cout << "Precizati cantitatea in kg/zi: " << endl;
    int cantitate;
    cin>>cantitate;

    for (int q = 0; q < numarAnimale; q++)
    {
        if (tip == porc || tip == bovina || tip == oaie || tip == cal)
        {
            Patruped animalNou = Patruped(tip, tipMancare, cantitate);
            AdaugaAnimal(animalNou);
        }
        else
        {
            Pasare animalNou = Pasare(tip, tipMancare, cantitate);
            AdaugaAnimal(animalNou);
        }
    }
    system("CLS");
}

void Ferma::AdaugaAnimal(Animal animal)
{
    Animalute.push_back(animal);
}


void Ferma::EliminaAnimale(int tipAnimal, int nr)
{
    vector <Animal> vectoras;
    if (nr > 0 && NumarAnimaleDeTip(tipAnimal) >= nr )
    {
        for (int i = 0 ; i < Animalute.size(); i++)
        {
            if (Animalute[i].GetSpecie() == tipAnimal)
            {
                if (nr > 0 )
                {
                    nr--;
                }
                else
                {
                    vectoras.push_back(Animalute[i]);
                }
            }
            else
            {
                vectoras.push_back(Animalute[i]);
            }
        }
        Animalute = vectoras;
    }
    else
    {
        system("CLS");
        cout << "Nu sunt suficiente animale de tipul ales in ferma." << endl;
        system("pause");
    }
}

int Ferma::NumarAnimaleDeTip(int tip)
{
    int nr = 0;
    for (int q = 0; q < Animalute.size(); q++)
    {
        if (Animalute[q].GetSpecie() == tip)
        {
            nr++;
        }
    }
    return nr;
}

void Ferma::ListaCateg()
{
    int nrCategorii[8] {0};
    for (int q = 0; q < Animalute.size(); q++)
    {
        nrCategorii[Animalute[q].GetSpecie()] += 1;
    }

    for (int i = 0 ; i < 8; i++)
    {
        cout << NumeSpecieAnimal(i) << " -> " << nrCategorii[i] << endl;
    }

}

void Ferma::VanzareAnimaleFerma()
{
    system("CLS");
    cout << "Selectati animalele pe care doriti sa le vindeti:" << endl;
    cout << endl;
    {
        int nrCategorii[8] {0};
        for (int q = 0; q < Animalute.size(); q++)
        {
            nrCategorii[Animalute[q].GetSpecie()] += 1;
        }

        for (int i = 0 ; i < 8; i++)
        {
            cout << NumeSpecieAnimal(i) << " -> " << nrCategorii[i] << endl;
        }
        cout << endl;
        cout << "8. Preturi animale" << endl;
        cout << "9. Sumar vanzari" << endl;
        cout << "10. Revenire la meniul principal" << endl;
        short optiune;
        short numar;
        unsigned int bugetPorc =0, bugetOi = 0, bugetBovine = 0, bugetCai =0, bugetGaini =0, bugetGaste =0, bugetRate=0, bugetCurci=0;
        cin >> optiune;
        system("CLS");
        int sumar = 0;
        switch (optiune)
        {
        case 0 :
            cout << "Ati selectat optiunea - Porci (100 euro / bucata)"  << "\nCati porci doriti sa vindeti?" <<endl;
            cin >> numar;
            system("CLS");
            if ((numar > 0) && (nrCategorii[0] >= numar))
            {
                EliminaAnimale(0, numar);
                bugetPorc=Pret[0] * numar;
                buget +=bugetPorc;
                sold += bugetPorc;
                cout << "Ati vandut " << numar << " porci" << endl;
                cout << "Sumar porci: " << bugetPorc << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                system("CLS");
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 1 :
            cout << "Ati selectat optiunea - Oi (70 euro / bucata)"  << "\nCate oi doriti sa vindeti?" <<endl;
            cin >> numar;
            system("CLS");
            if ((numar > 0) && (nrCategorii[1] >= numar))
            {
                EliminaAnimale(1, numar);
                bugetOi+=Pret[1] * numar;
                buget += bugetOi;
                sold += bugetOi;
                cout << "Ati vandut " << numar << " oi" << endl;
                cout << "Sumar oi: " << bugetOi << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                system("CLS");
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 2 :
            cout << "Ati selectat optiunea - Bovine (200 euro / bucata)"  << "\nCate bovine doriti sa vindeti?" <<endl;
            cin >> numar;
            system("CLS");
            if ((numar > 0) && (nrCategorii[2] >= numar))
            {
                EliminaAnimale(2, numar);
                bugetBovine+=Pret[2] * numar;
                buget += bugetBovine;
                sold += bugetBovine;
                cout << "Ati vandut " << numar << " bovine" << endl;
                cout << "Sumar bovine: " << bugetBovine <<" euro" <<  endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                system("CLS");
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 3 :
            cout << "Ati selectat optiunea - Cai (300 euro / bucata)"  << "\nCati cai doriti sa vindeti?" <<endl;
            cin >> numar;
            system("CLS");
            if ((numar > 0) && (nrCategorii[3] >= numar))
            {
                EliminaAnimale(3, numar);
                bugetCai+=Pret[3] * numar;
                buget += bugetCai;
                sold += bugetCai;
                cout << "Ati vandut " << numar << " cai" << endl;
                cout << "Sumar cai: " << bugetCai << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                system("CLS");
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 4 :
            cout << "Ati selectat optiunea - Gaini (25 euro / bucata)"  << "\nCate gaini doriti sa vindeti?" <<endl;
            cin >> numar;
            system("CLS");
            if ((numar > 0) && (nrCategorii[4] >= numar))
            {
                EliminaAnimale(4, numar);
                bugetGaini+=Pret[4] * numar;
                buget += bugetGaini;
                sold += bugetGaini;
                cout << "Ati vandut " << numar << " gaini" << endl;
                cout << "Sumar gaini: " << bugetGaini << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                system("CLS");
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 5 :
            cout << "Ati selectat optiunea - Gaste (25 euro / bucata)"  << "\nCate gaste doriti sa vindeti?" <<endl;
            cin >> numar;
            system("CLS");
            if ((numar > 0) && (nrCategorii[5] >= numar))
            {
                EliminaAnimale(5, numar);
                bugetGaste+=Pret[5] * numar;
                buget += bugetGaste;
                sold += bugetGaste;
                cout << "Ati vandut " << numar << " gaste" << endl;
                cout << "Sumar gaste: " << bugetGaste << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                system("CLS");
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 6 :
            cout << "Ati selectat optiunea - Rate (30 euro / bucata)"  << "\nCate rate doriti sa vindeti?" <<endl;
            cin >> numar;
            system("CLS");
            if ((numar > 0) && (nrCategorii[6] >= numar))
            {
                EliminaAnimale(6, numar);
                bugetRate+=Pret[6] * numar;
                buget += bugetRate;
                sold += bugetRate;
                cout << "Ati vandut " << numar << " rate" << endl;
                cout << "Sumar rate: " << bugetRate << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                system("CLS");
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 7 :
            cout << "Ati selectat optiunea - Curci (30 euro / bucata)"  << "\nCate curci doriti sa vindeti?" <<endl;
            cin >> numar;
            system("CLS");
            if ((numar > 0) && (nrCategorii[7] >= numar))
            {
                EliminaAnimale(7, numar);
                bugetCurci+=Pret[7] * numar;
                buget +=bugetCurci;
                sold += bugetCurci;
                cout << "Ati vandut " << numar << " curci" << endl;
                cout << "Sumar curci: " << bugetCurci << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                system("CLS");
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 8 :
            system ("CLS");
            cout << "Preturile animalelor sunt: " << "\n\nPorci - 100 euro / bucata \nOi - 70 euro / bucata \nBovine - 200 euro / bucata \nCai - 300 euro / bucata \nGaini - 25 euro / bucata \nGaste - 25 euro / bucata \nRate - 30 euro / bucata \nCurci - 30 euro / bucata "<<endl<<endl;
            system("pause");
            VanzareAnimaleFerma();
            break;
        case 9 :
            cout << "Sumarul total este: " << buget <<endl;
            system("pause");
            VanzareAnimaleFerma();
            break;
        case 10 :
            break;
        default :
            VanzareAnimaleFerma();
            break;
        }
    }
}
void Ferma::CumparaAnimale()
{
    system ("CLS");
    int nrCategorii[8];
    for (int q = 0; q < Animalute.size(); q++)
    {
        nrCategorii[Animalute[q].GetSpecie()] += 1;
    }
    cout << "Alegeti ce animal doriti sa cumparati:" << endl;
    cout << endl;
    cout << NumeSpecieAnimal(0) << " -> " << "80 euro / bucata" << endl;
    cout << NumeSpecieAnimal(1) << " -> " << "50 euro / bucata" << endl;
    cout << NumeSpecieAnimal(2) << " -> " << "150 euro / bucata" << endl;
    cout << NumeSpecieAnimal(3) << " -> " << "250 euro / bucata" << endl;
    cout << NumeSpecieAnimal(4) << " -> " << "20 euro / bucata" << endl;
    cout << NumeSpecieAnimal(5) << " -> " << "20 euro / bucata" << endl;
    cout << NumeSpecieAnimal(6) << " -> " << "25 euro / bucata" << endl;
    cout << NumeSpecieAnimal(7) << " -> " << "25 euro / bucata" << endl;
    cout << endl;
    cout << "8. Sold disponibil" << endl;
    cout << "9. Revenire la meniul principal" << endl;
    short optiune;
    short numar;
    cin >> optiune;
    switch (optiune)
    {
    case 0 :
        system ("CLS");
        cout << "Ati selectat optiunea - Porci (80 euro / bucata)"  << "\nCati porci doriti sa cumparati?" <<endl;
        cin >> numar;
        if (numar > 0)
        {
            system("CLS");
            CreeazaAnimaleDeCumparat(porc, numar);
            sold -= pretCumparare[0] * numar;
            cout << "Ati cumparat " << numar << " porci" << endl;
            cout << "Sold disponibil: " << sold << " euro" << endl;
            cout << endl;
            system("pause");
            CumparaAnimale();
        }
        else
        {
            cout << "Optiune invalida!!!" << endl;
            system("pause");
            CumparaAnimale();
        }
        break;
    case 1 :
        system ("CLS");
        cout << "Ati selectat optiunea - Oi (50 euro / bucata)"  << "\nCate oi doriti sa cumparati?" <<endl;
        cin >> numar;
        if (numar > 0)
        {
            system("CLS");
            CreeazaAnimaleDeCumparat(oaie, numar);
            sold -= pretCumparare[1] * numar;
            cout << "Ati cumparat " << numar << " oi" << endl;
            cout << "Sold disponibil: " << sold << " euro" << endl;
            cout << endl;
            system("pause");
            CumparaAnimale();
        }
        else
        {
            cout << "Optiune invalida!!!" << endl;
            system("pause");
            CumparaAnimale();
        }
        break;
    case 2 :
        system ("CLS");
        cout << "Ati selectat optiunea - Bovine (150 euro / bucata)"  << "\nCate bovine doriti sa cumparati?" <<endl;
        cin >> numar;
        if (numar > 0)
        {
            system("CLS");
            CreeazaAnimaleDeCumparat(bovina, numar);
            sold -= pretCumparare[2] * numar;
            cout << "Ati cumparat " << numar << " bovine" << endl;
            cout << "Sold disponibil: " << sold << " euro" << endl;
            cout << endl;
            system("pause");
            CumparaAnimale();
        }
        else
        {
            cout << "Optiune invalida!!!" << endl;
            system("pause");
            CumparaAnimale();
        }
        break;
    case 3 :
        system ("CLS");
        cout << "Ati selectat optiunea - Cai (250 euro / bucata)"  << "\nCati cai doriti sa cumparati?" <<endl;
        cin >> numar;
        if (numar > 0)
        {
            system("CLS");
            CreeazaAnimaleDeCumparat(cal, numar);
            sold -= pretCumparare[3] * numar;
            cout << "Ati cumparat " << numar << " cai" << endl;
            cout << "Sold disponibil: " << sold << " euro" << endl;
            cout << endl;
            system("pause");
            CumparaAnimale();
        }
        else
        {
            cout << "Optiune invalida!!!" << endl;
            system("pause");
            CumparaAnimale();
        }
        break;
    case 4 :
        system ("CLS");
        cout << "Ati selectat optiunea - Gaini (20 euro / bucata)"  << "\nCate gaini doriti sa cumparati?" <<endl;
        cin >> numar;
        if (numar > 0)
        {
            system("CLS");
            CreeazaAnimaleDeCumparat(gaina, numar);
            sold -= pretCumparare[4] * numar;
            cout << "Ati cumparat " << numar << " gaini" << endl;
            cout << "Sold disponibil: " << sold << " euro" << endl;
            cout << endl;
            system("pause");
            CumparaAnimale();
        }
        else
        {
            cout << "Optiune invalida!!!" << endl;
            system("pause");
            CumparaAnimale();
        }
        break;
    case 5 :
        system ("CLS");
        cout << "Ati selectat optiunea - Gaste (20 euro / bucata)"  << "\nCate gaste doriti sa cumparati?" <<endl;
        cin >> numar;
        if (numar > 0)
        {
            system("CLS");
            CreeazaAnimaleDeCumparat(gasca, numar);
            sold -= pretCumparare[5] * numar;
            cout << "Ati cumparat " << numar << " gaste" << endl;
            cout << "Sold disponibil: " << sold << " euro" << endl;
            cout << endl;
            system("pause");
            CumparaAnimale();
        }
        else
        {
            cout << "Optiune invalida!!!" << endl;
            system("pause");
            CumparaAnimale();
        }
        break;
    case 6 :
        system ("CLS");
        cout << "Ati selectat optiunea - Rate (25 euro / bucata)"  << "\nCate rate doriti sa cumparati?" <<endl;
        cin >> numar;
        if (numar > 0)
        {
            system("CLS");
            CreeazaAnimaleDeCumparat(rata, numar);
            sold -= pretCumparare[6] * numar;
            cout << "Ati cumparat " << numar << " rate" << endl;
            cout << "Sold disponibil: " << sold << " euro" << endl;
            cout << endl;
            system("pause");
            CumparaAnimale();
        }
        else
        {
            cout << "Optiune invalida!!!" << endl;
            system("pause");
            CumparaAnimale();
        }
        break;
    case 7 :
        system ("CLS");
        cout << "Ati selectat optiunea - Curci (25 euro / bucata)"  << "\nCate curci doriti sa cumparati?" <<endl;
        cin >> numar;
        if (numar > 0)
        {
            system("CLS");
            CreeazaAnimaleDeCumparat(curca, numar);
            sold -= pretCumparare[7] * numar;
            cout << "Ati cumparat " << numar << " curci" << endl;
            cout << "Sold disponibil: " << sold << " euro" << endl;
            cout << endl;
            system("pause");
            CumparaAnimale();
        }
        else
        {
            cout << "Optiune invalida!!!" << endl;
            system("pause");
            CumparaAnimale();
        }
        break;
    case 8 :
        system("CLS");
        cout << "Soldul disponibil este " << sold << " euro" <<endl;
        system("pause");
        CumparaAnimale();
        break;
    case 9 :
        break;
    default :
        CumparaAnimale();

    }

}
void Ferma::VizualizeazaBugetFerma()
{
    system("CLS");
    cout << "Bugetul fermei este "<< GetBuget() <<" euro." << endl;
    system("pause");
}
void Ferma::SituatieFerma()
{
    cout << "Situatia fermei:" << endl;
    cout <<endl;
    int nrCategorii[8] {0};
    int necesarFan = 0;
    int necesarPorumb = 0;
    for (int q = 0; q < Animalute.size(); q++)
    {
        nrCategorii[Animalute[q].GetSpecie()] += 1;
        if (Animalute[q].GetTipMancare()==fan)
        {
            necesarFan += Animalute[q].GetCantitateMancare();
        }
        else
        {
            necesarPorumb+=Animalute[q].GetCantitateMancare();
        }
    }

    for (int i = 0 ; i < 8; i++)
    {
        cout << NumeSpecieAnimal(i) << " -> " << nrCategorii[i] << endl;
    }
    cout << endl;
    if (necesarFan > 0)
    {
        cout << "Fan suficient pentru " << cantitateFan / necesarFan << " zile " << endl;
    }
    else
    {
        cout << "Nu este nevoie de fan." << endl;
    }
    if (necesarPorumb > 0)
    {
        cout << "Porumb suficient pentru " << cantitatePorumb / necesarPorumb << " zile " << endl;
    }
    else
    {
        cout << "Nu este nevoie de porumb." << endl;
    }
    cout << endl;


}

Ferma::~Ferma()
{
    //dtor
}
