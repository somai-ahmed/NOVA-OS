#include "deadlock.h"

void calculerBesoin(EtatSysteme *s){
    for(int i = 0 ; i<NB_PROC ; i++){
        for (int j=0 ; j<NB_RES ; j++){
            s.besoin[i][j] = s.max[i][j] - s.allocation[i][j];
        }
    }
}

int  estEtatSur(EtatSysteme *s, int seq[NB_PROC]){
    int travail[NB_RES];     
    int fini[NB_PROC] = {0};
    int k = 0;

    for (int j = 0; j < NB_RES; j++) {
        travail[j] = s.disponible[j];
    }

    while (k < NB_PROC) {
        int trouve = 0;

        for (int i = 0; i < NB_PROC; i++) {
            if (!fini[i]) {

                int indiceexecute = 1;
                for (int j = 0; j < NB_RES; j++) {
                    if (s->besoin[i][j] > travail[j]) {
                        indiceexecute = 0;
                        break;
                    }
                }
                if (indiceexecute) {
                    for (int j = 0; j < NB_RES; j++) {
                        travail[j] += s->allocation[i][j];
                    }
                    seq[k++] = i;
                    fini[i] = 1;
                    trouve = 1;
                }
            }
        }

        if (!trouve) {
            return 0; /*ETAT N EST PAS SUR*/
        }
    }
    return 1; /*ETAT SUR*/
}
