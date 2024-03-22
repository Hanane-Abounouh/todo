#ifndef HEADER_H
#define HEADER_H

typedef struct {
    char description[100];
    int priority;
    int finished; // 0: non termin�e, 1: termin�e

    char date[20];
} Task;

void addTask();
void modifyTask();
void deleteTask();
void displayTasks();
void filterTasksByPriority();
void markTaskFinished();

#endif
