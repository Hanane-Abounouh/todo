#include <stdio.h>
#include "header.h"

int main() {
    int choice = 0;

    printf("\nMenu Principal :\n");
    printf("1. Ajouter une t�che\n");
    printf("2. Modifier une t�che\n");
    printf("3. Supprimer une t�che\n");
    printf("4. Afficher toutes les t�ches\n");
    printf("5. Filtrer par priorit�\n");
    printf("6. Marquer une t�che comme termin�e\n");
    printf("7. Quitter\n");

    while (1) {

 
        printf("\nEntrez votre choix : ");
        scanf("%d", &choice);
        getchar(); // Pour consommer le caract�re de nouvelle ligne restant dans le buffer

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                modifyTask();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                displayTasks();
                break;
            case 5:
                filterTasksByPriority();
                break;
            case 6:
                markTaskFinished();
                break;
            case 7:
                printf("Fin du programme.\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
                break;
        }
    }

    return 0;
}
