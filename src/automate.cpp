#include "automate.h"
#include "etat.h"

Automate::Automate(string chaine) : lexer(chaine)
{
    pileEtats.push(new Etat0());
}

int Automate::Evaluer()
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
    cout << "EMPILE" << endl;
    s->Affiche();
    cout<<endl;
    pileSymboles.push(s);
    pileEtats.push(e);
    pileEtats.top()->transition(*this, lexer.Consulter());
}

void Automate::Decaler(Symbole *s, Etat *e)
{
    cout << "DECALE" << endl;
    s->Affiche();
    cout<<endl;
    pileSymboles.push(s);
    pileEtats.push(e);
    lexer.Avancer();
    pileEtats.top()->transition(*this,lexer.Consulter());
}

void Automate::Reduire(int n, Symbole *s)
{
    cout << "REDUIT" << endl;
    for (int i = 0; i < n; i++)
    {
        delete pileEtats.top();
        pileEtats.pop();
        delete pileSymboles.top();
        pileSymboles.pop();
    }
    s->Affiche();
    pileEtats.top()->transition(*this, s);


}
