# Grammaire et Languages INSA 4IF
### TP de compilation : Analyse syntaxique et évaluation d’une expression arithmétique

Étudiants :
- Cyril GOMES
- Emilien MARCHET

Encadrant :
- Éric GUÉRIN

## Résumé
Ce projet est notre implémentation de l'analyseur ascendant LALR(1) permettant d'évaluer des expressions arithmétiques simples (opérations d'addition et de multiplication uniquement).

## Éxecution du projet

À la racine du projet, utiliser make :
```bash
make all
```

Puis pour exécuter l'analyseur :
```bash
./lalr
```

Le programme vous demandera ensuite de saisir une chaîne de caractères à évaluer.
```bash
Entrez la chaine >> 1 + 2*3
TERMINE 7
```
