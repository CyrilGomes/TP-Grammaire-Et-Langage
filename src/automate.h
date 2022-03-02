#pragma once
#include <iostream>
#include <stack>
#include "symbole.h"
#include "lexer.h"
#include <string>
using namespace std;

class Etat;


class Automate
{
private:
    Lexer lexer;
    string chaine;

public:
    Automate(string chaine);
    stack<Etat *> pileEtats;
    stack<Symbole *> pileSymboles;

    void Empiler(Symbole*, Etat*);
    void Decaler(Symbole*, Etat*);
    void Reduire(int, Symbole*);

    int Parse();
    int Evaluer(int n, Symbole* symboles[]);

    void Erreur();

    ~Automate();
};