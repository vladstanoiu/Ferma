#ifndef UTILAJ_H
#define UTILAJ_H

enum TipUtilaj {tractor , combina};

class Utilaj
{
    public:
        Utilaj();
        Utilaj(TipUtilaj);
        TipUtilaj GetUtilaj() {return utilaj;}
        virtual ~Utilaj();

    protected:

    private:
        TipUtilaj utilaj;
};

#endif // UTILAJ_H
