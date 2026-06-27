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
        tempscourant += temp->info.tempsExecution ;
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

void FCFSstatistiquesfinales(NOEUD n , int taille){
    int tempsCourant = 0 ;
    printf("\n");
    printf("\n============Statistiques============\n");
    printf("+----------+------------+----------------+\n");
    printf("| NOM      |  Attente   | Retournement   |\n");
    printf("+----------+------------+----------------+\n");

    int tempsCourant = 0;
    int sommetempsattente = 0 ;
    int sommetempsretournement = 0 ;
    while (n != NULL) {
    if (tempsCourant < n->info.tempsArrivee)
        tempsCourant = n->info.tempsArrivee;

    n->info.tempsAttente = tempsCourant - n->info.tempsArrivee;
    tempsCourant += n->info.tempsExecution;

    n->info.tempsRetournement = tempsCourant - n->info.tempsArrivee;
    printf("%s    %d       %d",n->info.nom ,n->info.tempsAttente , n->info.tempsRetournement);
    sommetempsattente+=n->info.tempsAttente;
    sommetempsretournement+=n->info.tempsRetournement;
    n = n->suivant;
    }
    float moyennetempsattente = sommetempsattente/f->taille ;
    float moyennetempsretournement = sommetempsretournement / f->taille ;

    printf("Attente moyenne      : %f s",moyennetempsattente);
    printf(" Retournement moyen   : %f s ",moyennetempsretournement);

}

void afficherGanttSJF(NOEUD n){
    int tempscourant = 0;
    NOEUD temp;
    printf("+");
    temp=n ;
    while (temp != NULL) {
        if (tempscourant < temp->info.tempsArrivee)
            tempscourant = temp->info.tempsArrivee;
        for (int i = 0; i < temp->info.tempsExecution + 2; i++)
            printf("-");
        printf("+");
        tempscourant += temp->info.tempsExecution;
        temp = temp->suivant;
    }

    tempscourant = 0;
    printf("\n|");
    temp = n;
    while (temp != NULL) {
        if (tempscourant < temp->info.tempsArrivee)
            tempscourant = temp->info.tempsArrivee;
        printf(" %-*s|", temp->info.tempsExecution + 1, temp->info.nom);
        tempscourant += temp->info.tempsExecution;
        temp = temp->suivant;
    }

    tempscourant = 0;
    printf("\n+");
    temp = n;
    while (temp != NULL) {
        if (tempscourant < temp->info.tempsArrivee)
            tempscourant = temp->info.tempsArrivee;
        for (int i = 0; i < temp->info.tempsExecution + 2; i++)
            printf("-");
        printf("+");
        tempscourant += temp->info.tempsExecution;
        temp = temp->suivant;
    }

    tempscourant = 0;
    printf("\n0");
    temp = n;
    while (temp != NULL) {
        if (tempscourant < temp->info.tempsArrivee)
            tempscourant = temp->info.tempsArrivee;
        tempscourant += temp->info.tempsExecution;
        printf("%*d", temp->info.tempsExecution + 3, tempscourant);
        temp = temp->suivant;
    }
    printf("\n");
}

void SJFstatistiquesfinales(NOEUD n, int taille) {
    int   tempscourant        = 0;
    int   sommetempsattente      = 0;
    int   sommetempsretournement = 0;

    printf("\n============Statistiques============\n");
    printf("+----------+------------+----------------+\n");
    printf("| NOM      |  Attente   | Retournement   |\n");
    printf("+----------+------------+----------------+\n");

    while (n != NULL) {
        if (tempscourant < n->info.tempsArrivee)
            tempscourant = n->info.tempsArrivee;

        n->info.tempsAttente      = tempscourant - n->info.tempsArrivee;
        tempscourant             += n->info.tempsExecution;
        n->info.tempsRetournement = tempscourant - n->info.tempsArrivee;

        printf("| %-8s | %-10d | %-14d |\n",
               n->info.nom,
               n->info.tempsAttente,
               n->info.tempsRetournement);

        sommetempsattente      += n->info.tempsAttente;
        sommetempsretournement += n->info.tempsRetournement;

        n = n->suivant;
    }

    printf("+----------+------------+----------------+\n");

    float moyennetempsattente      = (float)sommetempsattente      / taille;
    float moyennetempsretournement = (float)sommetempsretournement / taille;

    printf("\nAttente moyenne      : %.2f s\n", moyennetempsattente);
    printf("Retournement moyen   : %.2f s\n",  moyennetempsretournement);
}

void ordonnancerSJF(FileAttente f) {
    if (f == NULL || estVide(f)) {
        printf("\n+======================================+\n");
        printf("|        FILE D'ATTENTE VIDE           |\n");
        printf("+======================================+\n\n");
        return;
    }

    FileAttente B;
    creerFile(B);
    B = copierfile(f);


    for (int i = 0; i < f->taille; i++) {
        NOEUD n = B->tete;
        for (int j = 0; j < f->taille - 1 - i; j++) { 
            if (n->info.tempsExecution > n->suivant->info.tempsExecution) {
                Processus temp    = n->info;
                n->info          = n->suivant->info;
                n->suivant->info = temp;
            }
            n = n->suivant;
        }
    }

    printf("\n+-------+----------+-------------+-----------------+------------------+--------+\n");
    printf("| PID   | Nom      | Arrivee (s) | Execution (s)   | Attente (s)      | Etat   |\n");
    printf("+-------+----------+-------------+-----------------+------------------+--------+\n");

    NOEUD n        = B->tete;
    int tempscourant = 0;

    while (n != NULL) {
        if (tempscourant < n->info.tempsArrivee)
            tempscourant = n->info.tempsArrivee;

        int tempsDebut = tempscourant;
        int tempsFin   = tempsDebut + n->info.tempsExecution;

        n->info.tempsAttente      = tempsDebut - n->info.tempsArrivee;
        n->info.tempsRetournement = tempsFin   - n->info.tempsArrivee;
        n->info.etat              = TERMINE;

        tempscourant = tempsFin;

        printf("| %-5d | %-8s | %-11d | %-15d | %-16d | %-6s |\n",
               n->info.pid,
               n->info.nom,
               n->info.tempsArrivee,
               n->info.tempsExecution,
               n->info.tempsAttente,
               n->info.etat);

        n = n->suivant;
    }
    /*====AFFICHAGE GANT ET STATISTIQUES========*/
    afficherGanttSJF(B->tete);
    SJFstatistiquesfinales(B->tete, f->taille);
}
