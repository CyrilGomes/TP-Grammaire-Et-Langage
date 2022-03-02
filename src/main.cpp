#include <iostream>
#include "lexer.h"
#include "automate.h"
#include <string>
int main(int argc, char * argv[])
{

   string chaine;
   cout << "Entrez la chaine >> ";
   std::getline(cin,chaine);
   //string chaine("(1+34)*123");
   //string chaine("(9*9)");
   /*
   Lexer l(chaine);

   Symbole * s;

   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }
      */

   Automate automate(chaine);
   automate.Parse();
   return 0;
}
