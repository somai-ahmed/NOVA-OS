#include "ordonnancement.h"
void affichagediagrammegrant(NOEUD n){
    int tempscourant = 0 ;
    /*========================AFFICHAGE============================*/
    printf("+");
    NOEUD temp = n ;
    while(temp!=NULL){
        if(tempscourant < temp->info.tempsArrivee){
            tempscourant = temp->info.tempsArrivee;
        }
        for(int i = 0 ; i<temp->info.tempsExecution +2 ;i++)/*+2 est pour le schema visuel du diagramme*/{
            printf("-");
        }
        printf("+");
        tempscourant =+ temp->info.tempsExecution ;
        temp = temp->suivant;
    }
    tempsCourant = 0;
    printf("\n|");
    tmp = n;
    while (tmp != NULL) {
        if (tempsCourant < tmp->info.tempsArrivee)
            tempsCourant = tmp->info.tempsArrivee;
        printf(" %-*s|", tmp->info.tempsExecution + 1, tmp->info.nom);
        tempsCourant += tmp->info.tempsExecution;
        tmp = tmp->suivant;
    }

    tempsCourant = 0;
    printf("\n+");
    tmp = n;
    while (tmp != NULL) {
        if (tempsCourant < tmp->info.tempsArrivee)
            tempsCourant = tmp->info.tempsArrivee;
        for (int i = 0; i < tmp->info.tempsExecution + 2; i++)
            printf("-");
        printf("+");
        tempsCourant += tmp->info.tempsExecution;
        tmp = tmp->suivant;
    }

    tempsCourant = 0;
    printf("\n0");
    tmp = n;
    while (tmp != NULL) {
        if (tempsCourant < tmp->info.tempsArrivee)
            tempsCourant = tmp->info.tempsArrivee;
        tempsCourant += tmp->info.tempsExecution;
        printf("%*d", tmp->info.tempsExecution + 3, tempsCourant);
        tmp = tmp->suivant;
    }
    printf("\n");
}

void ordonnancerFCFS(FileAttente f){
    if (f == NULL || estVide(f)) {
        printf("\n╔══════════════════════════════════════╗\n");
        printf("║        FILE D'ATTENTE VIDE            ║\n");
        printf("╚══════════════════════════════════════╝\n\n");
        return;
    }
    FileAttente B ;
    creerFile(B);
    B = copierfile(f);
    for(int i = 0 ; i<f->taille ; i++){
        NOEUD n = B->tete ;
        for(int j = 0 ; f->taille - 1 - i ; j++){
            if(n->info.tempsArrivee > n->suivant->info.tempsArrivee){
            Processus tmp = n->info;
            n->info       = n->suivant->info;
            n->suivant->info = tmp;
            }
        n = n->suivant ;
     
    }}

    printf("\n+-------+----------+-------------+-----------------+------------------+--------+\n");
    printf("| PID   | Nom      | Arrivee (s) | Execution (s)   | Attente (s)      | Etat   |\n");
    printf("+-------+----------+-------------+-----------------+------------------+--------+\n");

    NOEUD n = B->tete ;
    int tempsCourant = 0;

    if (tempsCourant < n->info.tempsArrivee)
        tempsCourant = n->info.tempsArrivee;

    int tempsDebut = tempsCourant;
    int tempsFin   = tempsDebut + n->info.tempsExecution;

    n->info.tempsAttente      = tempsDebut - n->info.tempsArrivee;
    n->info.tempsRetournement = tempsFin   - n->info.tempsArrivee;
    n->info.etat              = TERMINE; /*ENUM STRUCT*/

    tempsCourant = tempsFin; /*incrementation pour l'initiation du 2eme processus*/

    while(n!=NULL){
            printf("| %-5d | %-8s | %-11d | %-15d | %-16d | %-6s |\n",
            n->info.pid,
            n->info.nom,
            n->info.tempsArrivee,
            n->info.tempsExecution,
            n->info.tempsAttente,
            n->info.etat);
        n = n->suivant;
    }
    affichagediagrammegrant(B->tete);
    }


    