#include <iostream>
#include "Meniu.h"


using namespace std;

int main()
{
    Ferma fermaAnimale;
    Meniu meniu(fermaAnimale);
      //cod care citeste din fisier
    while(meniu.GetAlearga())
    {
        meniu.MeniuPrincipal();
    }
        //cod care scrie in fisier situatia fermei

    return 0;
}

