#include "liste_bloques.h"

void creerListeBloques(ListeBloques *l){
    ListeBloques l = (*ListeBloques)malloc(sizeof(lastruct));
    if(!l){
        printf("erreur d'allocation memoire");
        return ;
    }
    l->tete = NULL;
    l->queue = NULL;
    l->taille = 0 ;
}

void insererBloque(ListeBloques l, Processus p){
    NOEUD n = (*NOEUD)malloc(sizeof(structnoeud));
    if(l->tete == NULL){
        n = l->tete ;
        n->info.pid = p.pid ;
        strcpy(n->info.nom , p.nom);
        n->info.tempsArrivee = p.tempsArrivee ;
        n->info.tempsExecution = p.tempsExecution ;
        n->info.tempsRestant = p.tempsRestant ;
        n-info.priorite = p.priorite ;
        n->info.tempsAttente = p.tempsAttente ;
        n-info.tempsRetournement = p.tempsRetournement ;
        n->info.memoireRequise = p.memoireRequise ;
        n->info.etat = p.etat ;
        l->taille++;
    }
    else{
        n = l->queue;
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
            n->info.etat = p.etat ;
            l->taille++;
        }
    }
}

Processus retirerBloque(ListeBloques l, pid_t pid){
    Processus P ;
    NOEUD n = (*NOEUD)malloc(sizeof(structnoeud));
    if(!n){
        return NULL ;
    } 
    n = l->tete ;
    while(n!=NULL){
        if(int(n->info.pid) == (p.pid)){
            if(n==l->tete){
                l->tete = n->suivant;
            if(l->tete !=NULL ){
                n->precedant = NULL ;
            } 
        }
        else{
            n->precedant->suivant = n->suivant ;
        }
            if (n==l->queue){
                l->queue = n->precedant ;
                if(l->queue !=NULL){
                    l->queue->suivant  = NULL . 
                }
                else{
                    n->suivant->precedant = n->precedant;
                } 
            }
            Processus p = n->info;
            free(n);
            l->taille--;   

            if (l->taille == 0) {
            l->tete  = NULL;
            l->queue = NULL;
            }
            return p ; /*type d'output est PROCESSUS*/
        }
        n=n->suivant;
    }
    return NULL ;
}

void afficherBloques(ListeBloques l){
    if(l==NULL || l->tete = NULL){
        printf("\n╔══════════════════════════════════════╗\n");
        printf("║         LISTE BLOQUES VIDE            ║\n");
        printf("╚══════════════════════════════════════╝\n\n");
        return;
    }
    NOEUD n = l->tete ;
    
    printf("╔══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                  PROCESSUS BLOQUÉS (%d)                               ║\n", l->taille);
    printf("╠════╦══════════════════════╦══════╦══════════╦══════════╦════════════╣\n");
    printf("║ %-2s ║ %-20s ║ %-4s ║ %-8s ║ %-8s ║ %-10s ║\n",
           "PID", "NOM", "ARR", "EXEC", "MEMOIRE", "ÉTAT");
    printf("╠════╬══════════════════════╬══════╬══════════╬══════════╬════════════╣\n");

    while (courant != NULL) {
        printf("║ %-2d ║ %-20s ║ %-4d ║ %-8d ║ %-8d ║ %-10s ║\n",
               courant->info.pid,
               courant->info.nom,
               courant->info.tempsArrivee,
               courant->info.tempsExecution,
               courant->info.memoireRequise,
               "BLOQUE");
        courant = courant->suivant;
    }

    printf("╚════╩══════════════════════╩══════╩══════════╩══════════╩════════════╝\n");
}

