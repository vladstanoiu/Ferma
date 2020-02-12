#include "Ferma.h"
#include <iostream>
using namespace std;
Ferma::Ferma()
{
    Pret = std::vector<int>(8);
    Pret[0] = 100;
    Pret[1] = 70;
    Pret[2] = 200;
    Pret[3] = 300;
    Pret[4] = 25;
    Pret[5] = 25;
    Pret[6] = 30;
    Pret[7] = 30;

    buget = 0;
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
void Ferma::AdaugaAnimal(Animal animal)
{
    Animalute.push_back(animal);
}

void Ferma::EliminaAnimale(int tipAnimal, int nr)
{
    vector <Animal> vectoras;
    for (int i = 0 ; i < Animalute.size(); i++)
    {
        if (Animalute[i].GetSpecie() == tipAnimal)
        {
            if (nr > 0)
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
        cout << "8. Preturi animale" << endl;
        cout << "9. Sumar vanzari" << endl;
        cout << "10. Revenire la meniul principal" << endl;
        short optiune;
        short numar;
        unsigned int bugetPorc =0, bugetOi = 0, bugetBovine = 0, bugetCai =0, bugetGaini =0, bugetGaste =0, bugetRate=0, bugetCurci=0;
        cin >> optiune;
        switch (optiune)
        {
        case 0 :
            cout << "Ati selectat optiunea - Porci (100 euro / bucata)"  << "\nCati porci doriti sa vindeti?" <<endl;
            cin >> numar;
            if ((numar > 0) && (nrCategorii[0] >= numar))
            {
                EliminaAnimale(0, numar);
                bugetPorc+=Pret[0] * numar;
                buget +=bugetPorc;
                cout << "Ati vandut " << numar << " porci" << endl;
                cout << "Sumar porci: " << bugetPorc << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 1 :
            cout << "Ati selectat optiunea - Oi (70 euro / bucata)"  << "\nCate oi doriti sa vindeti?" <<endl;
            cin >> numar;
            if ((numar > 0) && (nrCategorii[1] >= numar))
            {
                EliminaAnimale(1, numar);
                bugetOi+=Pret[1] * numar;
                buget += bugetOi;
                cout << "Ati vandut " << numar << " oi" << endl;
                cout << "Sumar oi: " << bugetOi << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 2 :
            cout << "Ati selectat optiunea - Bovine (200 euro / bucata)"  << "\nCate bovine doriti sa vindeti?" <<endl;
            cin >> numar;
            if ((numar > 0) && (nrCategorii[2] >= numar))
            {
                EliminaAnimale(0, numar);
                bugetBovine+=Pret[2] * numar;
                buget += bugetBovine;
                cout << "Ati vandut " << numar << " bovine" << endl;
                cout << "Sumar bovine: " << bugetBovine <<" euro" <<  endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 3 :
            cout << "Ati selectat optiunea - Cai (300 euro / bucata)"  << "\nCati cai doriti sa vindeti?" <<endl;
            cin >> numar;
            if ((numar > 0) && (nrCategorii[3] >= numar))
            {
                EliminaAnimale(3, numar);
                bugetCai+=Pret[3] * numar;
                buget += bugetCai;
                cout << "Ati vandut " << numar << " cai" << endl;
                cout << "Sumar cai: " << bugetCai << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 4 :
            cout << "Ati selectat optiunea - Gaini (25 euro / bucata)"  << "\nCate gaini doriti sa vindeti?" <<endl;
            cin >> numar;
            if ((numar > 0) && (nrCategorii[4] >= numar))
            {
                EliminaAnimale(4, numar);
                bugetGaini+=Pret[4] * numar;
                buget += bugetGaini;
                cout << "Ati vandut " << numar << " gaini" << endl;
                cout << "Sumar gaini: " << bugetGaini << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 5 :
            cout << "Ati selectat optiunea - Gaste (25 euro / bucata)"  << "\nCate gaste doriti sa vindeti?" <<endl;
            cin >> numar;
            if ((numar > 0) && (nrCategorii[5] >= numar))
            {
                EliminaAnimale(5, numar);
                bugetGaste+=Pret[5] * numar;
                buget += bugetGaste;
                cout << "Ati vandut " << numar << " gaste" << endl;
                cout << "Sumar gaste: " << bugetGaste << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 6 :
            cout << "Ati selectat optiunea - Rate (30 euro / bucata)"  << "\nCate rate doriti sa vindeti?" <<endl;
            cin >> numar;
            if ((numar > 0) && (nrCategorii[6] >= numar))
            {
                EliminaAnimale(6, numar);
                bugetRate+=Pret[6] * numar;
                buget += bugetRate;
                cout << "Ati vandut " << numar << " rate" << endl;
                cout << "Sumar rate: " << bugetRate << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 7 :
            cout << "Ati selectat optiunea - Curci (30 euro / bucata)"  << "\nCate curci doriti sa vindeti?" <<endl;
            cin >> numar;
            if ((numar > 0) && (nrCategorii[7] >= numar))
            {
                EliminaAnimale(7, numar);
                bugetCurci+=Pret[7] * numar;
                buget +=bugetCurci;
                cout << "Ati vandut " << numar << " curci" << endl;
                cout << "Sumar curci: " << bugetCurci << " euro" << endl;
                system ("pause");
                VanzareAnimaleFerma();
            }
            else
            {
                cout << "Optiune invalida!!!" << endl;
                system("pause");
                VanzareAnimaleFerma();
            }
            break;
        case 8 :
            system ("CLS");
            cout << "Preturile animalelor sunt: " << "\n\nPorci - 100 euro / bucata \nOi - 70 euro / bucata \nBovine - 200 euro / bucata \nCai - 300 euro / bucata \nGaini - 25 euro / bucata \nGaste - 25 euro / bucata \nRate - 30 euro / bucata \nCurci - 30 euro / bucata "<<endl<<endl;
            system("pause");
            break;
        case 9 :

            cout << "Sumarul total este: " << buget <<endl;
            system("pause");
            break;
        case 10 :
            break;
        default :
            break;
        }
    }
}
void Ferma::SituatieFerma()
{
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


}

Ferma::~Ferma()
{
    //dtor
}
