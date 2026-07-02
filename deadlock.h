#ifndef DEADLOCK_H
#define DEADLOCK_H

#define NB_PROC 5
#define NB_RES  3

typedef struct {
    int allocation[NB_PROC][NB_RES];  /* ressources deja allouees    */
    int max       [NB_PROC][NB_RES];  /* besoin maximal declare       */
    int besoin    [NB_PROC][NB_RES];  /* = max - allocation           */
    int disponible[NB_RES];            /* ressources libres            */
} EtatSysteme;

void calculerBesoin(EtatSysteme *s);
int  estEtatSur(EtatSysteme *s, int seq[NB_PROC]);

#endif