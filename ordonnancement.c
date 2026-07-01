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

void afficherGanttPriorite(NOEUD n){
    int tempscourant = 0;
    NOEUD temp;

    printf("+");
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
    printf("\n|");
    temp = n;
    while (temp != NULL) {
        if (tempscourant < temp->info.tempsArrivee)
            tempscourant = temp->info.tempsArrivee;
        char label[32];
        snprintf(label, sizeof(label), "%s(p%d)", temp->info.nom, temp->info.priorite);
        printf(" %-*s|", temp->info.tempsExecution + 1, label);
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

void prioriteStatistiquesfinales(NOEUD n, int taille){
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

void ordonnancerPriorite(FileAttente f){
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
    afficherGanttPriorite(B->tete);
    prioriteStatistiquesfinales(B->tete, f->taille); 
}


void afficherGanttRR(NOEUD n) {
    int tempsCourant = 0;
    NOEUD tmp;
    /*=============STRUCTURE D'AFFICHAGE========================*/
    printf("+");
    tmp = n;
    while (tmp != NULL) {
        for (int i = 0; i < tmp->info.tempsExecution + 2; i++)
            printf("-");
        printf("+");
        tmp = tmp->suivant;
    }

    printf("\n|");
    tmp = n;
    while (tmp != NULL) {
        printf(" %-*s|", tmp->info.tempsExecution + 1, tmp->info.nom);
        tmp = tmp->suivant;
    }

    printf("\n+");
    tmp = n;
    while (tmp != NULL) {
        for (int i = 0; i < tmp->info.tempsExecution + 2; i++)
            printf("-");
        printf("+");
        tmp = tmp->suivant;
    }

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


/*l'idee du code source est inspiree du ce site web */
/*https://www.ccbp.in/blog/articles/round-robin-program-in-c*/

void RRstatistiquesfinales(NOEUD n, int taille)
{
    int i, y, q, somme = 0, k = 0;
    int sommetempsattente = 0, sommetempsretournement = 0;

    if (n == NULL || taille <= 0) {
        printf("\nAucun processus a analyser.\n");
        return;
    }

    int  *at   = malloc(taille * sizeof(int));
    int  *bt   = malloc(taille * sizeof(int));
    int  *temp = malloc(taille * sizeof(int));
    char (*noms)[30] = calloc(taille, sizeof(*noms));

    if (at == NULL || bt == NULL || temp == NULL || noms == NULL) {
        printf("ERREUR D'ALLOCATION MEMOIRE\n");
        free(at); free(bt); free(temp); free(noms);
        return;
    }

    /* Copier les processus depuis la liste chainee originale */
    NOEUD p = n;
    i = 0;
    while (p != NULL && i < taille) {
        strncpy(noms[i], p->info.nom, 29);
        noms[i][29] = '\0';
        at[i]   = p->info.tempsArrivee;
        bt[i]   = p->info.tempsExecution;
        temp[i] = bt[i];
        p = p->suivant;
        i++;
    }
    /*POUR LE MAIN , L ' UTILISATEUR OU LES DONNES ASSEMBLY DU PC DOIT ENTRER*/
    /*LE QUANTUM DU TEMPS DU CET ALGORITHME*/
    /*printf("Time Quantum: ");
    scanf("%d", &q);*/

    y = i;   /* nombre reel de processus copies */

    printf("\n============Statistiques============\n");
    printf("+----------+------------+----------------+\n");
    printf("| NOM      |  Attente   | Retournement   |\n");
    printf("+----------+------------+----------------+\n");

    for (somme = 0, i = 0; y != 0; ) {
        if (temp[i] <= q && temp[i] > 0) {
            somme += temp[i];
            temp[i] = 0;
            k = 1;
        } else if (temp[i] > 0) {
            temp[i] -= q;
            somme += q;
        }

        if (temp[i] == 0 && k == 1) {
            y--;
            int tempsRetournement = somme - at[i];
            int tempsAttente      = tempsRetournement - bt[i];

            printf("| %-8s | %-10d | %-14d |\n",
                   noms[i], tempsAttente, tempsRetournement);

            sommetempsattente      += tempsAttente;
            sommetempsretournement += tempsRetournement;
            k = 0;
        }

        if (i == taille - 1)
            i = 0;
        else if (at[i + 1] <= somme)
            i++;
        else
            i = 0;
    }

    printf("+----------+------------+----------------+\n");

    float moyennetempsattente      = (float) sommetempsattente      / taille;
    float moyennetempsretournement = (float) sommetempsretournement / taille;

    printf("\nAttente moyenne      : %.2f s\n", moyennetempsattente);
    printf("Retournement moyen   : %.2f s\n", moyennetempsretournement);

    free(at);
    free(bt);
    free(temp);
    free(noms);
}
