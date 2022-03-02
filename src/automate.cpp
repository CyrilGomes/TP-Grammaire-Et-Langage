#include "automate.h"
#include "etat.h"

Automate::Automate(string chaine) : lexer(chaine), chaine(chaine)
{

    pileEtats.push(new Etat0());
}

int Automate::Parse()
{
    pileEtats.top()->transition(*this, lexer.Consulter());
    return 0;
}

Automate::~Automate()
{
    int etatsSize = pileEtats.size();
    for (int i = 0; i < etatsSize; i++)
    {
        Etat *toDelete = pileEtats.top();
        delete toDelete;
        pileEtats.pop();
    }

    int symbolesSize = pileSymboles.size();
    for (int i = 0; i < symbolesSize; i++)
    {
        Symbole *toDelete = pileSymboles.top();
        delete toDelete;
        pileSymboles.pop();
    }
}

void Automate::Empiler(Symbole *s, Etat *e)
{
    //s->Affiche();
    //cout << endl;
    //cout << "EMPILE" << endl;

    pileSymboles.push(s);
    pileEtats.push(e);
    pileEtats.top()->transition(*this, lexer.Consulter());
}

void Automate::Decaler(Symbole *s, Etat *e)
{
    //s->Affiche();
    //cout << endl;

    //cout << "DECALE" << endl;

    pileSymboles.push(s);
    pileEtats.push(e);
    lexer.Avancer();
    pileEtats.top()->transition(*this, lexer.Consulter());
}

int Automate::Evaluer(int n, Symbole *symboles[])
{
    //cout << n << "  ";
    if (n == 1)
    {
        //cout << "Evaluated : " << ((Expression *)symboles[0])->GetValue();
        return ((Expression *)symboles[0])->GetValue();
    }

    switch (*symboles[1])
    {
    case PLUS:
        //cout << ((Expression *)symboles[0])->GetValue() << " + " << ((Expression *)symboles[2])->GetValue() << endl;
        return ((Expression *)symboles[0])->GetValue() + ((Expression *)symboles[2])->GetValue();

    case MULT:
        //cout << ((Expression *)symboles[0])->GetValue() << " * " << ((Expression *)symboles[2])->GetValue() << endl;
        return ((Expression *)symboles[0])->GetValue() * ((Expression *)symboles[2])->GetValue();
    case EXP:
        //cout << "(" << ((Expression *)symboles[1])->GetValue() << ")" << endl;
        return ((Expression *)symboles[1])->GetValue();

    }
    return 0;
}

void Automate::Reduire(int n, Symbole *s)
{
    //s->Affiche();
    //cout << endl;
    //cout << "REDUIT" << endl;
    Symbole *symboles[n];
    for (int i = 0; i < n; i++)
    {

        delete pileEtats.top();
        pileEtats.pop();
        symboles[i] = pileSymboles.top();
        pileSymboles.pop();
    }

    Symbole *expr = new Expression(Evaluer(n, symboles));
    //cout << "\t";
    //expr->Affiche();
    //cout << endl;

    pileEtats.top()->transition(*this, expr);

    for (int i = 0; i < n; i++)
    {
        delete symboles[i];
    }
}

void Automate::Erreur(){
    cout  << "Erreur :" << endl;
    cout << chaine << endl;
    for (int i = 0; i < pileSymboles.size(); i++)
    {
        delete pileSymboles.top();
        pileSymboles.pop();
        cout << "-";
    }
    cout << "^"<<endl;
    
}

