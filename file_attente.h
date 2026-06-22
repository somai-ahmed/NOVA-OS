#ifndef file_attente_H
#define file_attente_H

#include "processus.h"

typedef struct structnoeud {
    Processus       info;
    struct Cellule *suivant;
}structnoeud,*NOEUD;

typedef struct {
    NOEUD tete;
    NOEUD fin;
    int      taille;
} *FileAttente;

void      creerFile(FileAttente *f);
void      enfiler(FileAttente *f, Processus p);
Processus defiler(FileAttente *f);
bool       estVideFile(FileAttente *f);
void      afficherFile(FileAttente *f);
void      libererFile(FileAttente *f);

#endif
