#include "file_attente.h" 

void creerFile(FileAttente f){
    FileAttente f = (*FileAttente)malloc(sizeof(lastruct));
    if(!f){
        printf("ERREUR ALLOCATION MEMOIRE \n");
    }
    else{
    f->tete = NULL;
    f->fin = NULL ;
    f->taille = 0 ;
}
}

void enfiler(FileAttente f, Processus p){ //PRINCIPE FIFO :: enfiler ->ajpouter a la fin
    NOEUD n = f->fin ;
    n = n->suivant ;
    if(n==NULL){
    n->info.pid = p.pid ;
    strcpy(n->info.nom , p.nom);
    n->info.tempsArrivee = p.tempsArrivee ;
    n->info.tempsExecution = p.tempsExecution ;
    n->info.tempsRestant = p.tempsRestant ;
    n-info.priorite = p.priorite ;
    n->info.tempsAttente = p.tempsAttente ;
    n-info.tempsRetournement = p.tempsRetournement ;
    n->info.memoireRequise = p.memoireRequise ;
    n->info.etat = NOUVEAU ;
    
    f->fin = n;
    taille++;
    }
    else{
        printf("\nMEMOIRE SATUREE/n")
    }
}

Processus defiler(FileAttente f){ //defiler le premier element :: f->tete
    Processus p ;
    if(n==NULL){
        printf("\nFILE VIDE !");
        return p ;
    }
    NOEUD n = f->tete;
    f->tete = n->suivant;
    p = n->info ;
    free(n);
    return p;

}

bool estVideFile(FileAttente f){
    retrun(f==NULL || f->taille == 0);
}

void afficherFile(FileAttente f) {
    if (f == NULL || estVide(f)) {
        printf("\n╔══════════════════════════════════════╗\n");
        printf("║        FILE D'ATTENTE VIDE            ║\n");
        printf("╚══════════════════════════════════════╝\n\n");
        return;
    }

    NOEUD n = f->tete;
    
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                  FILE D'ATTENTE (%d processus)                                      ║\n", f->taille);
    printf("╠════╦══════════════════════╦══════╦══════╦══════════╦══════════╦══════════╦═════════╦════════════════╣\n");
    printf("║ %-2s ║ %-20s ║ %-4s ║ %-4s ║ %-8s ║ %-8s ║ %-8s ║ %-7s ║ %-14s ║\n",
           "PID", "NOM", "ARR", "PRI", "EXEC", "RESTANT", "ATTENTE", "MEMOIRE", "ETAT");
    printf("╠════╬══════════════════════╬══════╬══════╬══════════╬══════════╬══════════╬═════════╬════════════════╣\n");

    // Parcours et affichage de chaque nœud
    while (n != NULL) {
        Processus p = courant->info;
        
        printf("║ %-2d ║ %-20s ║ %-4d ║ %-4d ║ %-8d ║ %-8d ║ %-8d ║ %-7d ║ %-14s ║\n",
               p.pid,
               p.nom,
               p.tempsArrivee,
               p.priorite,
               p.tempsExecution,
               p.tempsRestant,
               p.tempsAttente,
               p.memoireRequise,
               etatToString(p.etat));
        
        n = n->suivant;
    }

    printf("╚════╩══════════════════════╩══════╩══════╩══════════╩══════════╩══════════╩═════════╩════════════════╝\n");
    printf("\n");
}


void libererFile(FileAttente f){
    if(estVideFile(f)){
        printf("FILE ATTENTE DEJA VIDE \n");
        free(f);
        retrun ;
    }
    else{
        NOEUD n;
        while(f->taille !=0){
            n = f->tete ;
            f->tete = n->suivant ;
            free(n);
            f->taille--;
        }
        free(f);
        retrun;
    }
}




