#ifndef LISTE_BLOQUES_H
#define LISTE_BLOQUES_H
#include "processus.h"

typedef struct structnoeud { //liste doublement chainee
    Processus        info;
    struct structnoeud *suivant;
    struct structnoeud *precedent;
}structnoeud ,*NOEUD;

typedef struct lastruct{
    NOEUD tete;
    NOEUD queue;
    int       taille;
}lastruct ,*ListeBloques;

void      creerListeBloques(ListeBloques l);
void      insererBloque(ListeBloques l, Processus p);
Processus retirerBloque(ListeBloques l, pid_t pid);
void      afficherBloques(ListeBloques l);

#endif
