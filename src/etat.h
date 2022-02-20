#include "automate.h"
#include "symbole.h"

class Etat
{
public:
    virtual void transition(Automate &, Symbole *) = 0;
};

class Etat0 : public Etat
{
    void transition(Automate &, Symbole *);
};

class Etat1 : public Etat
{
    void transition(Automate &, Symbole *);
};
class Etat2 : public Etat
{
    void transition(Automate &, Symbole *);
};
class Etat3 : public Etat
{
    void transition(Automate &, Symbole *);
};
class Etat4 : public Etat
{
    void transition(Automate &, Symbole *);
};
class Etat5 : public Etat
{
    void transition(Automate &, Symbole *);
};
class Etat6 : public Etat
{
    void transition(Automate &, Symbole *);
};
class Etat7 : public Etat
{
    void transition(Automate &, Symbole *);
};
class Etat8 : public Etat
{
    void transition(Automate &, Symbole *);

};
class Etat9 : public Etat
{
    void transition(Automate &, Symbole *);

};