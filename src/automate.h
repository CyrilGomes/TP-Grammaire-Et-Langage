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

public:
    Automate(string chaine);
    stack<Etat *> pileEtats;
    stack<Symbole *> pileSymboles;

    void Empiler(Symbole*, Etat*);
    void Decaler(Symbole*, Etat*);
    void Reduire(int, Symbole*);

    int Evaluer();

    ~Automate();
};