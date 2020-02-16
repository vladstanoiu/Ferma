#include <iostream>
#include "Meniu.h"


using namespace std;

int main()
{
    Ferma fermaAnimale;
    Meniu meniu(fermaAnimale);

    while(meniu.GetAlearga())
    {
        meniu.MeniuPrincipal();
    }

    return 0;
}

