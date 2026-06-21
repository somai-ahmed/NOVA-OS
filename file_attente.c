#include "file_attente.h" 

void creerFile(FileAttente f){
    f->tete = NULL;
    f->fin = NULL ;
    f->taille = 0 ;
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

Processus defiler(FileAttente *f){ //defiler le premier element :: f->tete
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

bool estVideFile(FileAttente *f){
    retrun(f==NULL || f->taille == 0);
}

void afficherFile(FileAttente *f){
    
}




