#include <stdio.h>
#include <stdlib.h>
#include "processus.h"

Processus creerProcessus(const char *nom, int arrivee, int duree, int priorite, int memoire){
    processus p;
    p.id = 0;
    strcpy(p.nom, nom);
    p.tempsArrivee = arrivee;
    p.tempsExecution = duree ;
    p.tempsRestant = duree ;
    p.priorite = priorite ;
    p.tempsAttente = 0 ;
    p.tempsRetournement = 0 ;
    p.memoireRequise = memoire ;
    p.etat = NOUVEAU ;

    return p ; 
}

const char* etatVersTexte(EtatProcessus e){
    switch (e){
        case NOUVEAU : return "NOUVEAU" ;
        case PRET : return "PRET" ;
        case EN_COURS : return "EN_COURS" ;
        case BLOQUE : return "BLOQUE" ;
        case TERMINE : return "TERMINE" ;

}
}

void afficherProcessus(Processus p){
    printf("+------------------------------------------------+\n");
    printf("|               PROCESSUS : %-20s |\n", p.nom);
    printf("+------------------------------------------------+\n");
    printf("|  PID                : %d\n", (int)p.pid);
    printf("|  Nom                : %s\n", p.nom);
    printf("|  Etat               : %s\n", etatVersTexte(p.etat));
    printf("|  Priorite           : %d\n", p.priorite);
    printf("|  Temps arrivee      : %d\n", p.tempsArrivee);
    printf("|  Temps execution    : %d (total)\n", p.tempsExecution);
    printf("|  Temps restant      : %d\n", p.tempsRestant);
    printf("|  Memoire requise    : %d octets\n", p.memoireRequise);
    printf("|  Temps attente      : %d\n", p.tempsAttente);
    printf("|  Temps retournement : %d\n", p.tempsRetournement);
    printf("+------------------------------------------------+\n");
}


