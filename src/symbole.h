#pragma once

#include <string>
using namespace std;

enum Identificateurs
{
   OPENPAR,
   CLOSEPAR,
   PLUS,
   MULT,
   INT,
   FIN,
   ERREUR,
   EXP,

};

const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPRESSION"};

class Symbole
{
public:
   Symbole(int i) : ident(i) {}
   virtual ~Symbole() {}
   operator int() const { return ident; }
   virtual void Affiche();

protected:
   int ident;
};

class Entier : public Symbole
{
public:
   Entier(int v) : Symbole(INT), valeur(v) {}
   ~Entier() {}
   virtual void Affiche();
   virtual int GetValue();

protected:
   int valeur;
};

class Expression : public Symbole
{
public:
   Expression(int v) : Symbole(EXP), valeur(v) {}
   ~Expression() {}
   virtual void Affiche();
   virtual int GetValue();

protected:
   int valeur;
};
