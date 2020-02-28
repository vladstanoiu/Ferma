#include <iostream>
#include "Meniu.h"
#include <fstream>

using namespace std;


int main()
{
    Ferma fermaAnimale;
    Meniu meniu(fermaAnimale);
    meniu.CitesteAnimale();
    meniu.CitesteSold();
    meniu.CitesteMancare();

    while(meniu.GetAlearga())
    {
        meniu.MeniuPrincipal();
    }
    return 0;
}

