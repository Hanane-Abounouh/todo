#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

Task *tasks = NULL;
int numTasks = 0;


void addTask() {
    // Allocation dynamique de m�moire ****************
    tasks = realloc(tasks, (numTasks + 1) * sizeof(Task));
    if (tasks == NULL) {
        printf("Erreur lors de l'allocation de m�moire.\n");
        exit(EXIT_FAILURE);
    }
    printf("Entrez la description de la t�che : ");
    scanf(" %[^\n]s", tasks[numTasks].description);


    while (true) {
        printf("Entrez la priorit� de la t�che : ");
        if (scanf("%d", &tasks[numTasks].priority) == 1) {
            break;
        } else {
            printf("Erreur : Veuillez entrer un entier pour la priorit�.\n");
            // Nettoyer le buffer d'entr�e
            while (getchar() != '\n');
        }
    }
    printf("Entrez la date de la t�che (jj/mm/aaaa) : ");
    scanf("%s", tasks[numTasks].date);


    while (true) {
        printf("La t�che est-elle termin�e ? (1 pour Oui, 0 pour Non) : ");
        if (scanf("%d", &tasks[numTasks].finished) == 1 && (tasks[numTasks].finished == 0 || tasks[numTasks].finished == 1)) {
            break;
        } else {
            printf("Erreur : Veuillez entrer 0 ou 1 pour indiquer si la t�che est termin�e.\n");

            while (getchar() != '\n');
    }
    }

    numTasks++;
    printf("T�che ajout�e avec succ�s.\n");
}



void modifyTask() {
    int index;
    printf("Entrez l'indice de la t�che � modifier : ");
    scanf("%d", &index);
    if (index < 1 || index > numTasks) {
        printf("Indice de t�che invalide.\n");
        return;
    }

    printf("Entrez la nouvelle description de la t�che : ");
    scanf(" %[^\n]s", tasks[index - 1].description);

    printf("Entrez la nouvelle priorit� de la t�che : ");
    scanf("%d", &tasks[index - 1].priority);

    printf("Entrez la nouvelle date de la t�che (jj/mm/aaaa) : ");
    scanf("%s", tasks[index - 1].date);


    printf("La t�che est-elle termin�e ? (1 pour Oui, 0 pour Non) : ");
    scanf("%d", &tasks[index - 1].finished);

    printf("T�che modifi�e avec succ�s.\n");
}




void deleteTask() {
    int index;
    printf("Entrez l'indice de la t�che � supprimer : ");
    scanf("%d", &index);
    if (index < 1 || index > numTasks) {
        printf("Indice de t�che invalide.\n");
        return;
    }

    for (int i = index - 1; i < numTasks - 1; i++) {
        strcpy(tasks[i].description, tasks[i + 1].description);
        tasks[i].priority = tasks[i + 1].priority;
        strcpy(tasks[i].date, tasks[i + 1].date);
        tasks[i].finished = tasks[i + 1].finished;
    }

    numTasks--;

    printf("T�che supprim�e avec succ�s.\n");
}





void displayTasks() {
    if (numTasks == 0) {
        printf("Aucune t�che trouv�e.\n");
        return;
    }

    printf("Liste des t�ches :\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. Description : %s  Priorit� : %d  Date : %s  Statut : %s\n", i + 1,
        tasks[i].description, tasks[i].priority, tasks[i].date, tasks[i].finished ? "Termin�e" : "Non termin�e");
    }
}


// **Fonction de comparaison pour le tri des t�ches par priorit�**
int compare_priorities(const void *a, const void *b) {
    Task *taskA = (Task *)a;
    Task *taskB = (Task *)b;
    return (taskA->priority - taskB->priority);
}

void filterTasksByPriority() {
    if (numTasks == 0) {
        printf("Aucune t�che trouv�e.\n");
        return;
    }

    // Trier les t�ches par priorit� **********************
    qsort(tasks, numTasks, sizeof(Task), compare_priorities);

    printf("Liste des t�ches :\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. Description : %s  Priorit� : %d  Date : %s  Statut : %s\n", i + 1,
        tasks[i].description, tasks[i].priority, tasks[i].date, tasks[i].finished ? "Termin�e" : "Non termin�e");
    }
}


void markTaskFinished() {
    int index;
    printf("Entrez l'indice de la t�che termin�e : ");
    scanf("%d", &index);
    if (index < 1 || index > numTasks) {
        printf("Indice de t�che invalide.\n");
        return;
    }
    tasks[index - 1].finished = 1;
    printf("T�che marqu�e comme termin�e avec succ�s.\n");
}
