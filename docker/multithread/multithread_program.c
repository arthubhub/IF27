#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NB_THREAD 6
#define MAX_TENTATIVE 5

int nb_tentatives = 0;

void *tentatives_connexion(void *arg) {
    for (int i = 0; i < 3; i++) {  
        int tentatives_actuelles = nb_tentatives;
        usleep(10);
        tentatives_actuelles++;
        nb_tentatives = tentatives_actuelles;
        printf("Client %d : Tentative de connexion échouée. Total des tentatives : %d\n", (int)arg, tentatives_actuelles);
        if (nb_tentatives >= MAX_TENTATIVE) {
            printf("Compte bloqué\n");
            break;
        }
    }
    return NULL;
}

int main() {
    pthread_t clients[NB_THREAD];
    for (int i = 0; i < NB_THREAD; i++) {
        pthread_create(&clients[i], NULL, tentatives_connexion, (void *)i);
    }
    for (int i = 0; i < NB_THREAD; i++) {
        pthread_join(clients[i], NULL);
    }
    printf("\nAudit de sécurité :\n");
    printf("Total des tentatives de connexion enregistrées : %d\n", nb_tentatives);
    if (nb_tentatives < MAX_TENTATIVE) {
        printf("Tout est ok : %d tentative(s)\n", nb_tentatives);
    } else if (nb_tentatives > MAX_TENTATIVE) {
        printf("Erreur critique : %d tentatives de plus que la limite\n", nb_tentatives - MAX_TENTATIVE);
    } else {
        printf("Compte bloque\n");
    }
    return 0;
}

