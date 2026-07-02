#include "deadlock.h"

void calculerBesoin(EtatSysteme s){
    for(int i = 0 ; i<NB_PROC ; i++){
        for (int j=0 j<NB_RES ; j++){
            s->besoin[i][j] = s->max[i][j] - s->allocation[i][j];
        }
    }
}

int  estEtatSur(EtatSysteme *s, int seq[NB_PROC]){}

