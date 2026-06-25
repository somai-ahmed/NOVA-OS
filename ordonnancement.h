#ifndef ORDONNANCEMENT_H
#define ORDONNANCEMENT_H
#include "file_attente.h"
#include "processus.h"
/*=======================FCFS==========================*/
void affichagediagrammegrant(NOEUD n);
void FCFSstatistiquesfinales(NOEUD n , int taille);
void ordonnancerFCFS(FileAttente f); // First Come First Served


void ordonnancerSJF(FileAttente f); //Shortest Job First 
void ordonnancerRoundRobin(FileAttente f, int quantumSec);

/*===tourniquet -- RR===*/
/*Chaque processus dans la file reçoit une tranche de temps fixe
 *   appelée "quantum" (ici quantumSec secondes).
 *   Si le processus ne termine pas dans ce délai, il est remis
 *   en fin de file et le suivant prend la main.
 *   On répète jusqu'à ce que tous les processus soient terminés.*/

void ordonnancerPriorite(FileAttente f);//priorité numérique
void afficherStatistiques(Processus tab[], int n);

#endif