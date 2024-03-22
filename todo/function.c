#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

Task *tasks = NULL;
int numTasks = 0;


void addTask() {
    // Allocation dynamique de mémoire ****************
    tasks = realloc(tasks, (numTasks + 1) * sizeof(Task));
    if (tasks == NULL) {
        printf("Erreur lors de l'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }
    printf("Entrez la description de la tâche : ");
    scanf(" %[^\n]s", tasks[numTasks].description);


    while (true) {
        printf("Entrez la priorité de la tâche : ");
        if (scanf("%d", &tasks[numTasks].priority) == 1) {
            break;
        } else {
            printf("Erreur : Veuillez entrer un entier pour la priorité.\n");
            // Nettoyer le buffer d'entrée
            while (getchar() != '\n');
        }
    }
    printf("Entrez la date de la tâche (jj/mm/aaaa) : ");
    scanf("%s", tasks[numTasks].date);


    while (true) {
        printf("La tâche est-elle terminée ? (1 pour Oui, 0 pour Non) : ");
        if (scanf("%d", &tasks[numTasks].finished) == 1 && (tasks[numTasks].finished == 0 || tasks[numTasks].finished == 1)) {
            break;
        } else {
            printf("Erreur : Veuillez entrer 0 ou 1 pour indiquer si la tâche est terminée.\n");

            while (getchar() != '\n');
    }
    }

    numTasks++;
    printf("Tâche ajoutée avec succès.\n");
}



void modifyTask() {
    int index;
    printf("Entrez l'indice de la tâche à modifier : ");
    scanf("%d", &index);
    if (index < 1 || index > numTasks) {
        printf("Indice de tâche invalide.\n");
        return;
    }

    printf("Entrez la nouvelle description de la tâche : ");
    scanf(" %[^\n]s", tasks[index - 1].description);

    printf("Entrez la nouvelle priorité de la tâche : ");
    scanf("%d", &tasks[index - 1].priority);

    printf("Entrez la nouvelle date de la tâche (jj/mm/aaaa) : ");
    scanf("%s", tasks[index - 1].date);


    printf("La tâche est-elle terminée ? (1 pour Oui, 0 pour Non) : ");
    scanf("%d", &tasks[index - 1].finished);

    printf("Tâche modifiée avec succès.\n");
}




void deleteTask() {
    int index;
    printf("Entrez l'indice de la tâche à supprimer : ");
    scanf("%d", &index);
    if (index < 1 || index > numTasks) {
        printf("Indice de tâche invalide.\n");
        return;
    }

    for (int i = index - 1; i < numTasks - 1; i++) {
        strcpy(tasks[i].description, tasks[i + 1].description);
        tasks[i].priority = tasks[i + 1].priority;
        strcpy(tasks[i].date, tasks[i + 1].date);
        tasks[i].finished = tasks[i + 1].finished;
    }

    numTasks--;

    printf("Tâche supprimée avec succès.\n");
}





void displayTasks() {
    if (numTasks == 0) {
        printf("Aucune tâche trouvée.\n");
        return;
    }

    printf("Liste des tâches :\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. Description : %s  Priorité : %d  Date : %s  Statut : %s\n", i + 1,
        tasks[i].description, tasks[i].priority, tasks[i].date, tasks[i].finished ? "Terminée" : "Non terminée");
    }
}


// **Fonction de comparaison pour le tri des tâches par priorité**
int compare_priorities(const void *a, const void *b) {
    Task *taskA = (Task *)a;
    Task *taskB = (Task *)b;
    return (taskA->priority - taskB->priority);
}

void filterTasksByPriority() {
    if (numTasks == 0) {
        printf("Aucune tâche trouvée.\n");
        return;
    }

    // Trier les tâches par priorité **********************
    qsort(tasks, numTasks, sizeof(Task), compare_priorities);

    printf("Liste des tâches :\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. Description : %s  Priorité : %d  Date : %s  Statut : %s\n", i + 1,
        tasks[i].description, tasks[i].priority, tasks[i].date, tasks[i].finished ? "Terminée" : "Non terminée");
    }
}


void markTaskFinished() {
    int index;
    printf("Entrez l'indice de la tâche terminée : ");
    scanf("%d", &index);
    if (index < 1 || index > numTasks) {
        printf("Indice de tâche invalide.\n");
        return;
    }
    tasks[index - 1].finished = 1;
    printf("Tâche marquée comme terminée avec succès.\n");
}
