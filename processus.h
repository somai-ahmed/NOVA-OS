#ifndef PROCESSUS_H
#define POCESSUS_H
#include <sys/types.h>

typedef enum {
    NOUVEAU, PRET, EN_COURS, BLOQUE, TERMINE
} EtatProcessus;

typedef struct {
    pid_t pid;
    char  nom[30];
    int   tempsArrivee;
    int   tempsExecution;
    int   tempsRestant;
    int   priorite;
    int   tempsAttente;
    int   tempsRetournement;
    int   memoireRequise;
    EtatProcessus etat;
} Processus;


Processus   creerProcessus(const char *nom, int arrivee, int duree, int priorite, int memoire);
void        afficherProcessus(Processus p);
const char* etatVersTexte(EtatProcessus e);

#endif