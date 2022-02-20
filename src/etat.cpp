#include "etat.h"

void Etat0::transition(Automate &automate, Symbole *symbole)
{
    cout<<"ETAT0"<<endl;
    switch (*symbole)
    {
    case INT:
        automate.Decaler(symbole, new Etat3);
        break;
    case OPENPAR:
        automate.Decaler(symbole, new Etat2);
        break;
    case EXP:
        automate.Empiler(symbole, new Etat1);
        break;
    }
}

void Etat1::transition(Automate &automate, Symbole *symbole)
{
        cout<<"ETAT1"<<endl;
    switch (*symbole)
    {
    case PLUS:
        automate.Decaler(symbole, new Etat4);
        break;
    case MULT:
        automate.Decaler(symbole, new Etat5);
        break;
    case FIN:
        break;
    }
}

void Etat2::transition(Automate &automate, Symbole *symbole)
{
        cout<<"ETAT2"<<endl;
    switch (*symbole)
    {
    case INT:
        automate.Decaler(symbole, new Etat3);
        break;
    case OPENPAR:
        automate.Decaler(symbole, new Etat2);
        break;
    case EXP:
        automate.Empiler(symbole, new Etat6);
        break;
    }
}

void Etat3::transition(Automate &automate, Symbole *symbole)
{
        cout<<"ETAT3"<<endl;
    switch (*symbole)
    {
    case PLUS:
        automate.Reduire(1, symbole);
        break;
    case MULT:
        automate.Reduire(1, symbole);
        break;
    case CLOSEPAR:
        automate.Reduire(1, symbole);
        break;
    case FIN:
        automate.Reduire(1, symbole);
        break;
    }
}

void Etat4::transition(Automate &automate, Symbole *symbole)
{
        cout<<"ETAT4"<<endl;
    switch (*symbole)
    {
    case INT:
        automate.Decaler(symbole, new Etat3);
        break;
    case OPENPAR:
        automate.Decaler(symbole, new Etat2);
        break;
    case EXP:
        automate.Empiler(symbole, new Etat7);
        break;
    }
}

void Etat5::transition(Automate &automate, Symbole *symbole)
{
        cout<<"ETAT5"<<endl;
    switch (*symbole)
    {
    case INT:
        automate.Decaler(symbole, new Etat3);
        break;
    case OPENPAR:
        automate.Decaler(symbole, new Etat2);
        break;
    case EXP:
        automate.Empiler(symbole, new Etat8);
        break;
    }
}

void Etat6::transition(Automate &automate, Symbole *symbole)
{
        cout<<"ETAT6"<<endl;
    switch (*symbole)
    {
    case PLUS:
        automate.Decaler(symbole, new Etat4);
        break;
    case MULT:
        automate.Decaler(symbole, new Etat5);
        break;
    case CLOSEPAR:
        automate.Decaler(symbole, new Etat9);
        break;
    }
}

void Etat7::transition(Automate &automate, Symbole *symbole)
{
        cout<<"ETAT7"<<endl;
    switch (*symbole)
    {
    case PLUS:
        automate.Reduire(3, symbole);
        break;
    case MULT:
        automate.Decaler(symbole, new Etat5);
        break;
    case CLOSEPAR:
        automate.Reduire(3, symbole);
        break;
    case FIN:
        automate.Reduire(3, symbole);
        break;
    }
}

void Etat8::transition(Automate &automate, Symbole *symbole)
{
        cout<<"ETAT8"<<endl;
    switch (*symbole)
    {
    case PLUS:
        automate.Reduire(3, symbole);
        break;
    case MULT:
        automate.Reduire(3, symbole);
        break;
    case CLOSEPAR:
        automate.Reduire(3, symbole);
        break;
    case FIN:
        automate.Reduire(3, symbole);
        break;
    }
}
void Etat9::transition(Automate &automate, Symbole *symbole)
{
        cout<<"ETAT9"<<endl;
    switch (*symbole)
    {
    case PLUS:
        automate.Reduire(3, symbole);
        break;
    case MULT:
        automate.Reduire(3, symbole);
        break;
    case CLOSEPAR:
        automate.Reduire(3, symbole);
        break;
    case FIN:
        automate.Reduire(3, symbole);
        break;
    }
}
