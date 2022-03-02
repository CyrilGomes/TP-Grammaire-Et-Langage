#include "etat.h"

void Etat0::transition(Automate &automate, Symbole *symbole)
{
    ////cout << "ETAT0" << endl;
    switch (*symbole)
    {
    case INT:
        automate.Decaler(symbole, new Etat3);
        return;
    case OPENPAR:
        automate.Decaler(symbole, new Etat2);
        return;
    case EXP:
        automate.Empiler(symbole, new Etat1);
        return;
    }
    automate.Erreur();
}

void Etat1::transition(Automate &automate, Symbole *symbole)
{
    ////cout << "ETAT1" << endl;
    switch (*symbole)
    {
    case PLUS:
        automate.Decaler(symbole, new Etat4);
        return;
    case MULT:
        automate.Decaler(symbole, new Etat5);
        return;
    case FIN:
        cout << "TERMINE " << ((Expression *)automate.pileSymboles.top())->GetValue() << endl;
        return;
    }
    automate.Erreur();
}

void Etat2::transition(Automate &automate, Symbole *symbole)
{
    ////cout << "ETAT2" << endl;
    switch (*symbole)
    {
    case INT:
        automate.Decaler(symbole, new Etat3);
        return;
    case OPENPAR:
        automate.Decaler(symbole, new Etat2);
        return;
    case EXP:
        automate.Empiler(symbole, new Etat6);
        return;
    }
    automate.Erreur();
}

void Etat3::transition(Automate &automate, Symbole *symbole)
{
    ////cout << "ETAT3" << endl;
    switch (*symbole)
    {
    case PLUS:
        automate.Reduire(1, symbole);
        return;
    case MULT:
        automate.Reduire(1, symbole);
        return;
    case CLOSEPAR:
        automate.Reduire(1, symbole);
        return;
    case FIN:
        automate.Reduire(1, symbole);
        return;
    }
    automate.Erreur();
}

void Etat4::transition(Automate &automate, Symbole *symbole)
{
    ////cout << "ETAT4" << endl;
    switch (*symbole)
    {
    case INT:
        automate.Decaler(symbole, new Etat3);
        return;
    case OPENPAR:
        automate.Decaler(symbole, new Etat2);
        return;
    case EXP:
        automate.Empiler(symbole, new Etat7);
        return;
    }
    automate.Erreur();
}

void Etat5::transition(Automate &automate, Symbole *symbole)
{
    ////cout << "ETAT5" << endl;
    switch (*symbole)
    {
    case INT:
        automate.Decaler(symbole, new Etat3);
        return;
    case OPENPAR:
        automate.Decaler(symbole, new Etat2);
        return;
    case EXP:
        automate.Empiler(symbole, new Etat8);
        return;
    }
    automate.Erreur();
}

void Etat6::transition(Automate &automate, Symbole *symbole)
{
    ////cout << "ETAT6" << endl;
    switch (*symbole)
    {
    case PLUS:
        automate.Decaler(symbole, new Etat4);
        return;
    case MULT:
        automate.Decaler(symbole, new Etat5);
        return;
    case CLOSEPAR:
        automate.Decaler(symbole, new Etat9);
        return;
    }
    automate.Erreur();
}

void Etat7::transition(Automate &automate, Symbole *symbole)
{
    ////cout << "ETAT7" << endl;
    switch (*symbole)
    {
    case PLUS:
        automate.Reduire(3, symbole);
        return;
    case MULT:
        automate.Decaler(symbole, new Etat5);
        return;
    case CLOSEPAR:
        automate.Reduire(3, symbole);
        return;
    case FIN:
        automate.Reduire(3, symbole);
        return;
    }
    automate.Erreur();
}

void Etat8::transition(Automate &automate, Symbole *symbole)
{
    //cout << "ETAT8" << endl;
    switch (*symbole)
    {
    case PLUS:
        automate.Reduire(3, symbole);
        return;
    case MULT:
        automate.Reduire(3, symbole);
        return;
    case CLOSEPAR:
        automate.Reduire(3, symbole);
        return;
    case FIN:
        automate.Reduire(3, symbole);
        return;
    }
    automate.Erreur();
}
void Etat9::transition(Automate &automate, Symbole *symbole)
{
    //cout << "ETAT9" << endl;
    switch (*symbole)
    {
    case PLUS:
        automate.Reduire(3, symbole);
        return;
    case MULT:
        automate.Reduire(3, symbole);
        return;
    case CLOSEPAR:
        automate.Reduire(3, symbole);
        return;
    case FIN:
        automate.Reduire(3, symbole);
        return;
    }
    automate.Erreur();
}
