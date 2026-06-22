#ifndef file_attente_H
#define file_attente_H

#include "processus.h"

typedef struct structnoeud{
    Processus       info;
    struct structnoeud *suivant;
}structnoeud,*NOEUD;

typedef struct lastruct{
    NOEUD tete;
    NOEUD fin;
    int      taille;
}lastruct,*FileAttente;

void      creerFile(FileAttente f);
void      enfiler(FileAttente f, Processus p);
Processus defiler(FileAttente f);
bool       estVideFile(FileAttente f);
void      afficherFile(FileAttente f);
void      libererFile(FileAttente f);

#endif
